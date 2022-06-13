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
    // Initialize a member vector to hold all the members from each line in the input file
    vector<Member> memberVector;

    // Read inputfile to populate memberVector and set number of members
    int numberOfMembers = Utilities::readInputFile(&memberVector, "input.txt");

    // Print member count and the list of members
    cout << "Number of UN Members in a meeting = " << numberOfMembers << endl;
    Utilities::printMemberVector(memberVector);

    // Initialize a member graph
    MemberGraph UNMemberGraph(numberOfMembers, &memberVector);

    // Populate the membergraph by adding direction edges
    // Edge member1 --> member2 will be added if member2 understands the language spoken by member1
    Utilities::createMemberGraph(&memberVector, &UNMemberGraph);

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
