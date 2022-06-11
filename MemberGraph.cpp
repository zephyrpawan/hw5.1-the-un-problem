#include "MemberGraph.h"

MemberGraph::MemberGraph(int members)
{
    this->members = members;
    adjMemberList = new list<Member>[members];
}

void MemberGraph::addEdge(Member mSpeaks, Member mUnderstands)
{
    adjMemberList[mSpeaks.getId()].push_back(mUnderstands);
}

void MemberGraph::DFSTraverse(Member member, bool visited[])
{
    // Base case
    if (visited[member.getId()])
    {
        return;
    }

    // mark the current member node as visited
    visited[member.getId()] = true;
    cout << member.getName() << " ";

    // move to the next member node and recurse for all unvisited  members
    for (auto itr = adjMemberList[member.getId()].begin(); itr != adjMemberList[member.getId()].end(); ++itr)
    {
        if (!visited[(*itr).getId()])
        {
            DFSTraverse(*itr, visited);
        }
    }
}

void MemberGraph::DFS(Member member)
{
    bool *visited = new bool[members];
    for (int i = 0; i < members; i++)
    {
        visited[i] = false;
    }

    DFSTraverse(member, visited);
}

int MemberGraph::findSCCKosaraju() {
    int sccCount = 0;

    return sccCount;
}