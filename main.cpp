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

    // Check to make sure first line of input file contains correct number of members
    Utilities::exitIfBadInputFile(numberOfMembers, memberVector.size());

    // Print member count and the list of members
    // cout << "Number of UN Members in a meeting = " << numberOfMembers << endl;
    // Utilities::printMemberVector(memberVector);

    // Initialize a member graph
    MemberGraph UNMemberGraph(numberOfMembers, &memberVector);

    // Populate the member graph by adding directional edges
    // Edge member1 --> member2 will be added if member2 understands the language spoken by member1
    Utilities::createMemberGraph(&memberVector, &UNMemberGraph);

    // Call findScc() on member graph to get vector of member vectors i.e stronglyConnectedMembersVec
    // Each vector in stronglyConnectedMembersVec contains members who can converse with each other
    vector<vector<Member>> stronglyConnectedMembersVec = UNMemberGraph.findSCC();

    // cout << "List of memers who can all converse with each other: " << endl;

    // Initialize the size of strongly connected members
    int maxSccMembersSize = 0;

    // loop through stronglyConnectedMembers to find the largest group size that can converse
    for (vector<Member> &stronglyConnectedMembers : stronglyConnectedMembersVec)
    {
        if (stronglyConnectedMembers.size() > maxSccMembersSize)
        {
            maxSccMembersSize = stronglyConnectedMembers.size();
        }
        // Utilities::printMemberVector(stronglyConnectedMembers);
    }

    // cout << "Maximum members who can all converse with each other: " << maxSccMembersSize << endl;

    int membersRequiredToLeave = numberOfMembers - maxSccMembersSize;

    // cout << "Minimum number of members required to leave = ";
    cout << membersRequiredToLeave;
    cout << endl << endl;

    return 0;
}
