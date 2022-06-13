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
    Member Fran("Fran", 0, "French", vector<string>{"Italian"});
    Member Enid("Enid", 1, "English", vector<string>{"German"});
    Member George("George", 2, "German", vector<string>{"Italian"});
    Member Ian("Ian", 3, "Italian", vector<string>{"French", "Spanish"});
    Member Spencer("Spencer", 4, "Spanish", vector<string>{"Portuguese"});
    Member Polly("Polly", 5, "Portuguese", vector<string>{"Spanish"});

    vector<Member> memberVector{Fran, Enid, George, Ian, Spencer, Polly};

    // cout << Fran.toString() << endl;
    // cout << Enid.toString() << endl;
    // cout << George.toString() << endl;
    // cout << Ian.toString() << endl;
    // cout << Spencer.toString() << endl;
    // cout << Polly.toString() << endl;
    // cout << endl;


    MemberGraph memG(6, &memberVector);
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