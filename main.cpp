#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <set>

#include "Member.h"
#include "MemberGraph.h"
#include "Utilities.h"

using namespace std;

int main(int argc, char const *argv[])
{
    vector<Member> memberVector;
    int numberOfMembers = Utilities::readInputFile(&memberVector, "input.txt");
    
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
