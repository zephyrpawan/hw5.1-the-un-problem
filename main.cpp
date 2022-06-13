#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <list>

#include "Member.h"
#include "MemberGraph.h"

using namespace std;

void printVector(vector<Member> vec);

int main(int argc, char const *argv[])
{
    Member M0("M0", 0, "French", vector<string>{"Italian"});
    Member M1("M1", 1, "English", vector<string>{"German"});
    Member M2("M2", 2, "German", vector<string>{"Italian"});
    Member M3("M3", 3, "Italian", vector<string>{"French", "Spanish"});
    Member M4("M4", 4, "Spanish", vector<string>{"Portuguese"});
    // Member Polly("Polly", 5, "Portuguese", vector<string>{"Spanish"});

    // cout << Fran.toString() << endl;
    // cout << Enid.toString() << endl;
    // cout << George.toString() << endl;
    // cout << Ian.toString() << endl;
    // cout << Spencer.toString() << endl;
    // cout << Polly.toString() << endl;
    // cout << endl;

    MemberGraph memG(5);
    memG.addEdge(M1, M0);
    memG.addEdge(M0, M2);
    memG.addEdge(M2, M1);
    memG.addEdge(M0, M3);
    memG.addEdge(M3, M4);
    memG.addEdge(M3, M3);
    memG.addEdge(M4, M4);
    // memG.addEdge(Ian, Ian);
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
        // printVector(memVec);
    }

    cout << endl
         << "Maximum members who can all converse with each other: " << maxSccSize << endl
         << endl;

    return 0;
}

void printVector(vector<Member> vec)
{
    cout << "{";
    for (int i = 0; i < vec.size(); i++)
    {
        if (i == vec.size() - 1)
        {
            cout << vec[i].toString();
        }
        else
        {
            cout << vec[i].toString() << ", ";
        }
    }
    cout << "}" << endl
         << endl;
}