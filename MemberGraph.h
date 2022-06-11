#ifndef MEMBERGRAPH_H
#define MEMBERGRAPH_H

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <list>

#include "Member.h"

using namespace std;

class MemberGraph {
    private:
        //Number of members in the meeting
        int members;

        //Adjacency list to represent member graph
        list<Member> *adjMemberList;

    public:
        MemberGraph(int members);
        void addEdge(Member mSpeaks, Member mUnderstands);
        void DFSTraverse(Member member, bool visited[]);
        void DFS(Member Member);
};

#endif