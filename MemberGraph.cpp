#include "MemberGraph.h"

MemberGraph::MemberGraph(int members, vector<Member> *memberVec)
{
    this->members = members;
    this->memberVec = memberVec;
    adjMemberList = new list<Member>[members];
    adjMemberListReverse = new list<Member>[members];
}

void MemberGraph::addEdge(Member mSpeaks, Member mUnderstands)
{
    adjMemberList[mSpeaks.getId()].push_back(mUnderstands);
    adjMemberListReverse[mUnderstands.getId()].push_back(mSpeaks);

    //cout << mSpeaks.getName() << " Speaks " << mSpeaks.getSpeaks() << " and " << mUnderstands.getName() << " understands " << mSpeaks.getSpeaks() << endl;
}

void MemberGraph::DFS1ToFillStack(Member member, bool visited[], stack<Member> &memberStack)
{
    if(visited[member.getId()]){
        return;
    }
    visited[member.getId()] = true;

    for (auto itr = adjMemberList[member.getId()].begin(); itr != adjMemberList[member.getId()].end(); itr++)
    {
        if (!visited[(*itr).getId()])
        {
            DFS1ToFillStack(*itr, visited, memberStack);
        }
        memberStack.push(member);
    }
}

void MemberGraph::DFS2InReverse(Member member, bool visited[], vector<Member> *sccMembers)
{ 
    // Base case
    if (visited[member.getId()])
    {
        return;
    }

    // mark the current member node as visited
    visited[member.getId()] = true;
   // cout << member.getName() << " ";
    (*sccMembers).push_back(member);

    // move to the next member node and recurse for all unvisited  members
    for (auto itr = adjMemberListReverse[member.getId()].begin(); itr != adjMemberListReverse[member.getId()].end(); itr++)
    {
        if (!visited[(*itr).getId()])
        {
            DFS2InReverse(*itr, visited, sccMembers);
        }
    }
}

vector<vector<Member>> MemberGraph::findSCC()
{
    vector<vector<Member>> scc;
    stack<Member> memberStack;

    bool *visited = new bool[members];
    for (int i = 0; i < members; i++)
    {
        visited[i] = false;
    }

    // first DFS to put members in stack in reverse order of their finishing times
    for (int i=0; i<(*memberVec).size(); i++)
    {

        if (!visited[(*memberVec).at(i).getId()])
        {
            DFS1ToFillStack((*memberVec).at(i), visited, memberStack);
        }
    }

    // set all members as not visited for second DFS
    for (int i = 0; i < members; i++)
    {
        visited[i] = false;
    }

    while (!memberStack.empty())
    {
        Member m = memberStack.top();
        memberStack.pop();

        vector<Member> scMembers;

        if (!visited[m.getId()])
        {
            DFS2InReverse(m, visited, &scMembers);
            scc.push_back(scMembers);
        }
    }

    return scc;
}

/*Refrences
 * https://www.geeksforgeeks.org/strongly-connected-components/
 */