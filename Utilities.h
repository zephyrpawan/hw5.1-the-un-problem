#ifndef UTILITIES_H
#define UTILITIES_H

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

using namespace std;

class Utilities
{
public:
    static void printVector(vector<string> vec);
    static void printMemberVector(vector<Member> vec, ofstream &outputdata);
    static int readInputFile(vector<Member> *memberVector, string inputFile);
    static void createMemberGraph(vector<Member> *memberVector, MemberGraph *UNMemberGraph, ofstream &outputdata);
    static void exitIfBadInputFile( int numberOfMembers, int membersWithDetails);
};

#endif