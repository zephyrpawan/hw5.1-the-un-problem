#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>

#include "Member.h"
#include "MemberGraph.h"

using namespace std;

void printMemberVector(vector<Member> vec);
void printVector(vector<string> vec);

int main(int argc, char const *argv[])
{
    Member Fran("Fran", 0, "French", set<string>{"Italian"});
    Member Enid("Enid", 1, "English", set<string>{"German"});
    Member George("George", 2, "German", set<string>{"Italian"});
    Member Ian("Ian", 3, "Italian", set<string>{"French", "Spanish"});
    Member Spencer("Spencer", 4, "Spanish", set<string>{"Portuguese"});
    Member Polly("Polly", 5, "Portuguese", set<string>{"Spanish"});
    vector<Member> memberVec{Fran, Enid, George, Ian, Spencer, Polly};

    MemberGraph memG(6, &memberVec);
    memG.addEdge(Fran, Fran);
    memG.addEdge(Enid, Enid);
    memG.addEdge(George, George);
    memG.addEdge(Ian, Ian);
    memG.addEdge(Spencer, Spencer);
    memG.addEdge(Polly, Polly);

    memG.addEdge(Fran, Ian);
    memG.addEdge(Ian, Fran);
    memG.addEdge(George, Enid);
    memG.addEdge(Spencer, Polly);
    memG.addEdge(Polly, Spencer);

    cout << endl;
    cout << "List of memers who can all converse with each other: " << endl;

    vector<vector<Member>> sccVecs = memG.findSCC();

    int maxSccSize = 0;

    for (vector<Member> &memVec : sccVecs)
    {
        if (memVec.size() > maxSccSize)
        {
            maxSccSize = memVec.size();
        }
        printMemberVector(memVec);
    }

    cout << endl
         << "Maximum members who can all converse with each other: " << maxSccSize << endl
         << endl;

    // End of manual processing

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
                cout << "number of Members = " << numberOfMembers << endl;
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
    printMemberVector(memberVector);

    MemberGraph UNMemberGraph(numberOfMembers, &memberVector);

    // for (int i = 0; i< memberVector.size(); i++) {
    //     for(int j=0; j<memberVector.size(); i++) {
    //         //if()
    //     }
    // }

    
    
    return 0;
}

void printMemberVector(vector<Member> vec)
{
    cout << "{";
    for (int i = 0; i < vec.size(); i++)
    {
        if (i == vec.size() - 1)
        {
            //cout << vec[i].getId() << "_" << vec[i].getName();
            cout << vec[i].toString();
        }
        else
        {
            //cout << vec[i].getId() << "_" << vec[i].getName() << ", ";
            cout << vec[i].toString() << ", ";
        }
    }
    cout << "}" << endl
         << endl;
}
void printVector(vector<string> vec)
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