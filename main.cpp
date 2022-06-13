#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>

#include "Member.h"
#include "MemberGraph.h"
#include "Utilities.h"

using namespace std;

int main(int argc, char const *argv[])
{
    // Process input file
    int numberOfMembers = 0;
    vector<Member> memberVector;

    ifstream inputFile("input.txt");
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

                memberVector.push_back(member);
            }

            lineNumber++;
        }
    }
    else
    {
        cout << "Unable to open inputfile.txt" << endl;
        cout << "Please make sure inputfile.txt exists in the source folder and try again!" << endl;
    }
    cout << "Number of UN Members in a meeting = " << numberOfMembers << endl;
    Utilities::printMemberVector(memberVector);

    MemberGraph UNMemberGraph(numberOfMembers, &memberVector);

    for (int i = 0; i < memberVector.size(); i++)
    {
        for (int j = 0; j < memberVector.size(); j++)
        {

            if ((memberVector[i].getSpeaks() == memberVector[j].getSpeaks()) ||
                (memberVector[j].getUnderstands().count(memberVector[i].getSpeaks()) == 1))
            {
                UNMemberGraph.addEdge(memberVector[i], memberVector[j]);
                cout << memberVector[j].getName() << " understands " << memberVector[i].getName() << endl;
            }
        }
    }
    cout << endl;
    cout << "List of memers who can all converse with each other: " << endl;

    vector<vector<Member>> sccUNVecs = UNMemberGraph.findSCC();

    int maxSccUNSize = 0;

    for (vector<Member> &memUNVec : sccUNVecs)
    {
        if (memUNVec.size() > maxSccUNSize)
        {
            maxSccUNSize = memUNVec.size();
        }
        Utilities::printMemberVector(memUNVec);
    }

    cout << endl
         << "Maximum members who can all converse with each other: " << maxSccUNSize << endl
         << endl;
    // End of file processing

    return 0;
}

