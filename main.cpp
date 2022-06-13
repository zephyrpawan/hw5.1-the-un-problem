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
    // Initialize ofstream to outputfile [optional] for logging
    // For testing and debugging purposes details will be printed to output.txt
    ofstream outputData;
    outputData.open("output.txt");
    if (!outputData)
    {
        cerr << "Unable to open file!" << endl;
    }

    // Initialize a member vector to hold all the members from each line in the input file
    vector<Member> memberVector;

    // Read inputfile to populate memberVector and set number of members
    int numberOfMembers = Utilities::readInputFile(&memberVector, "input.txt");

    // Check to make sure first line of inputfile contains correct number of members before proceeding
    Utilities::exitIfBadInputFile(numberOfMembers, memberVector.size());

    // Print member count and the list of members to outputfile.txt [optional]
    outputData << "Number of UN Members in a meeting = " << numberOfMembers << endl;
    Utilities::printMemberVector(memberVector, outputData);
    outputData << endl;

    // Initialize a member graph
    MemberGraph UNMemberGraph(numberOfMembers, &memberVector);

    // Populate the member graph by adding directional edges
    // Edge member1 --> member2 will be added if member2 understands the language spoken by member1
    Utilities::createMemberGraph(&memberVector, &UNMemberGraph, outputData);

    // Call findScc() on member graph to get vector of member vectors i.e stronglyConnectedMembersVec
    // Each vector in stronglyConnectedMembersVec contains members who can converse with each other
    vector<vector<Member>> stronglyConnectedMembersVec = UNMemberGraph.findSCC();

    // write to oputput file [optional]
    outputData << endl << "List of memers who can all converse with each other: " << endl;

    // Initialize the  max size of strongly connected members
    int maxSccMembersSize = 0;

    // loop through stronglyConnectedMembers to find the largest group size that can converse
    for (vector<Member> &stronglyConnectedMembers : stronglyConnectedMembersVec)
    {
        if (stronglyConnectedMembers.size() > maxSccMembersSize)
        {
            maxSccMembersSize = stronglyConnectedMembers.size();
        }
        // Print an edge m1-->m2 as "m1 speaks *language* and m2 understands m1" to the file output.txt [optional]
        Utilities::printMemberVector(stronglyConnectedMembers, outputData);
        
    }

    // printing to outputfile [optional]
    outputData << endl;
    outputData << "Maximum number of members who can all converse with each other: " << maxSccMembersSize << endl;
    outputData << endl;

    // Calculate the number of members required to leave
    int membersRequiredToLeave = numberOfMembers - maxSccMembersSize;

    // Print the output to the terminal and the file
    outputData << "Minimum number of members required to leave = " << membersRequiredToLeave;
    cout << membersRequiredToLeave;
    cout << endl;

    // closing ofsream
    outputData.close();

    return 0;
}
