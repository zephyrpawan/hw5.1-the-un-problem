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

#ifndef MEMBERGRAPH_H
#define MEMBERGRAPH_H

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <vector>

#include "Member.h"

using namespace std;

class MemberGraph
{
private:
    // Number of members in the meeting
    int members;
    vector<Member> *memberVec;

    // member vector with their names only
    // vector<string> *memberNames;

    // Adjacency list to represent member graph and its reverse
    list<Member> *adjMemberList;
    list<Member> *adjMemberListReverse;

public:
    MemberGraph(int members, vector<Member> *memberVec);
    void addEdge(Member mSpeaks, Member mUnderstands);
    void DFS1ToFillStack(Member member, bool visited[], stack<Member> &memberStack);
    void DFS2InReverse(Member member, bool visited[], vector<Member> *sccMembers);
    vector<vector<Member>> findSCC();
};

#endif