#include "Utilities.h"

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

void Utilities::printMemberVector(vector<Member> vec)
{
    cout << "{";
    for (int i = 0; i < vec.size(); i++)
    {
        if (i == vec.size() - 1)
        {
            cout << vec[i].getId() << "_" << vec[i].getName();
            // cout << vec[i].toString();
        }
        else
        {
            cout << vec[i].getId() << "_" << vec[i].getName() << ", ";
            // cout << vec[i].toString() << ", ";
        }
    }
    cout << "}" << endl
         << endl;
}

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
            if (lineNumber == -1)
            {
                numberOfMembers = stoi(line);
            }

            if (lineNumber >= 0)
            {
                istringstream ss(line);
                string word;
                while (ss >> word)
                {
                    wordsInALine.push_back(word);
                }
                member.setName(wordsInALine[0]);
                member.setid(lineNumber);
                member.setSpeaks(wordsInALine[1]);
                member.setUnderstands(set<string>(wordsInALine.begin() + 2, wordsInALine.end()));

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