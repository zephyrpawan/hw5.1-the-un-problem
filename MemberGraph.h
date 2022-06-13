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