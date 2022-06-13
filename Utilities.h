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