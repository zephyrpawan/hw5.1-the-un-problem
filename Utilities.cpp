/*
 * Author: Pawan Bhandari
 * Assignment Title: Homework 5.1: The UN Problem
 * Assignment Description: Applies the Kosaraju's Algorith to find strongly connceted components
 *                         for solving the UN Problem
 * Due Date: 06/06/2022
 * Date Created: 06/06/2022
 * Date Last Modified:06/13/2022
 */

// Uses C++-2011 standard

#include "Utilities.h"

//***************************************************************************************************
// description: prints the elements of a string vector to the terminal                              *
// return: void                                                                                     *
// precondition: vector<string>                                                                     *
//                  vector<string> strVec {str1, str2, str3}                                        *
// postcondition: print vector<string> to the terminal                                              *
//                  {str1, str2, str3}                                                              *
//***************************************************************************************************
void Utilities::printVector(vector<string> vec)
{
    cout << "{";
    for (int i = 0; i < vec.size(); i++)
    {
        if (i == vec.size() - 1)
        {
            cout << vec[i];
        }
        else
        {
            cout << vec[i] << ", ";
        }
    }
    cout << "}" << endl;
}

//***************************************************************************************************
// description: prints the name of the members in a Member vector to the outfile                    *
// return: void                                                                                     *
// precondition: vector<Member> and ofstream                                                        *
// postcondition: prints the name of each member from vector<Member> to the outputfile              *                                                             *
//***************************************************************************************************
void Utilities::printMemberVector(vector<Member> vec, ofstream &outputData)
{
    outputData << "{";
    for (int i = 0; i < vec.size(); i++)
    {
        if (i == vec.size() - 1)
        {
            outputData << vec[i].getName();
            // cout << vec[i].toString();
        }
        else
        {
            outputData << vec[i].getName() << ", ";
            // cout << vec[i].toString() << ", ";
        }
    }
    outputData << "}" << endl;
}

//***************************************************************************************************
// description: reads input.txt file                                                                *
//              determines the total number of members from line 1                                  *
//              creates a Member object for each member and pushes it to the memberVector           *
// return: number of members as int                                                                 *
// precondition: input.txt and vector<Member>                                                       *
// postcondition: populates Member vector with the member object from each member line in input.txt *
//***************************************************************************************************
int Utilities::readInputFile(vector<Member> *memberVector, string inputFileName)
{
    // Process input file
    int numberOfMembers = 0;

    ifstream inputFile(inputFileName);
    if (inputFile.is_open())
    {
        string line;
        int lineNumber = -1;
        while (getline(inputFile, line))
        {
            vector<string> wordsInALine;
            Member member;
            // read first line and set the number as numberofMembers
            if (lineNumber == -1)
            {
                numberOfMembers = stoi(line);
            }

            // for each line from seconf line onwards, read each line, split into words and push each words to a temp vector<string>
            if (lineNumber >= 0)
            {
                istringstream ss(line);
                string word;
                while (ss >> word)
                {
                    wordsInALine.push_back(word);
                }

                // set properties of a Member object using the words for the line
                member.setName(wordsInALine[0]);
                member.setid(lineNumber);
                member.setSpeaks(wordsInALine[1]);
                member.setUnderstands(set<string>(wordsInALine.begin() + 2, wordsInALine.end()));

                // push the Member object created from each line to membervector
                (*memberVector).push_back(member);
            }
            lineNumber++;
        }
    }
    else
    {
        cout << "Unable to open inputfile.txt" << endl;
        cout << "Please make sure inputfile.txt exists in the source folder and try again!" << endl;
    }
    return numberOfMembers;
}

//***************************************************************************************************
// description: Adds a directional edge to a member graph between mSpeaks --> mUnderstands          *
// return: void                                                                                     *
// precondition: vector<Member>, MemberGraph and ofstream                                           *
// postcondition:  An edge between mSpeaks --> mUnderstands is added in the MemberGraph             *
//***************************************************************************************************
void Utilities::createMemberGraph(vector<Member> *memberVector, MemberGraph *UNMemberGraph, ofstream &outputData)
{
    for (int i = 0; i < (*memberVector).size(); i++)
    {
        for (int j = 0; j < (*memberVector).size(); j++)
        {
            if (((*memberVector)[i].getSpeaks() == (*memberVector)[j].getSpeaks()) ||
                ((*memberVector)[j].getUnderstands().count((*memberVector)[i].getSpeaks()) == 1))
            {
                (*UNMemberGraph).addEdge((*memberVector)[i], (*memberVector)[j]);
                outputData << (*memberVector)[i].getName() << " speaks " << (*memberVector)[i].getSpeaks() << " and "
                           << (*memberVector)[j].getName() << " understands " << (*memberVector)[i].getName() << endl;
            }
        }
    }
}

//***************************************************************************************************
// description: gracefully exit the program if the inputfile doesnot contain details of all members *
// return: void                                                                                     *
// precondition: integer inputs: numberOfMembers and membersWithDetails                             *
// postcondition: gracefully exit program if numberOfMembers != membersWithDetails                  *                                                             *
//***************************************************************************************************
void Utilities::exitIfBadInputFile(int numberOfMembers, int membersWithDetails)
{
    if (numberOfMembers != membersWithDetails)
    {
        cout << "Input file says there are " << numberOfMembers << " members in line 1, but it contains";
        cout << " details of " << membersWithDetails << " members." << endl;
        cout << "Please correct the inputfile.txt and rerun the program!" << endl;
        cout << "Terminating program. Exit code: -1" << endl
             << endl;
        exit(-1);
    }
}