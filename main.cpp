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

/*
 * Data Abstraction:
 *       Member class is custom defined to hold member all the member data in an member object
 *       Input file stream is opened and vector of Member [vector<Member> memberVector] is created
 *
 * Input:
 *       input.txt file in the same relative path as the program that contains 
 *       the total number of members in the first line followed by the each member detail.
 *
 * Process:
 *       Input file stream is opened to read from input.txt
 *       vector<Member> is created with the details from input.txt
 *       MemberGraph object is initialized with member data from vector<Member>
 *       Populate the member graph by adding directional edges
 *              Edge member1 --> member2 will be added if member2 understands the language spoken by member1
 *       Call findScc() on MemberGraph to get vector of member vectors i.e stronglyConnectedMembersVec
 *       Each vector in stronglyConnectedMembersVec contains members who can converse with each other
 *       loop through stronglyConnectedMembersVec to find the largest group size that can converse
 *       calculate the minimum number of members required to leave and print it on the terminal
 *              membersRequiredToLeave = numberOfMembers - maxSccMembersSize;     
 *
 * Output:
 *      Minimum number of members required to leave is printed in the console
 *
 * Assumptions:
 *      input.txt file is valid and is present in same path and named correctly
 *      program is able to open and write logs to file output.txt
 *      Members can understand themselves
 */

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

    // Read inputfile to populate memberVector and find number of members
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

/*Refrences
 * https://www.geeksforgeeks.org/strongly-connected-components/
 */
