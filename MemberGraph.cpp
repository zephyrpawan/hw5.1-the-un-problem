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

#include "MemberGraph.h"

//***************************************************************************************************
// description: MemberGraph class constructor for creating MemberGraph objects                      *
// return: Creates MemberGraph object and provides methods for implementation Kosaraju's Algorithm  *
// precondition: member vector (memberVec), and adjacency list representation of member graph       *
// postcondition: Instantiates MemberGraph object                                                   *
//***************************************************************************************************
MemberGraph::MemberGraph(int members, vector<Member> *memberVec)
{
    this->members = members;
    this->memberVec = memberVec;
    adjMemberList = new list<Member>[members];
    adjMemberListReverse = new list<Member>[members];
}

//***************************************************************************************************
// description: Adds a directional edge to a member graph between mSpeaks --> mUnderstands          *
// return: void                                                                                     *
// precondition: member mSpeaks and mUnderstand are present in original member vector               *
// postcondition:  An edge between mSpeaks --> mUnderstands is added in the MemberGraph             *
//***************************************************************************************************
void MemberGraph::addEdge(Member mSpeaks, Member mUnderstands)
{
    adjMemberList[mSpeaks.getId()].push_back(mUnderstands);
    adjMemberListReverse[mUnderstands.getId()].push_back(mSpeaks);
}

//***************************************************************************************************
// description: Implements first Depth-First-Search algorith on the MemberGraph and                 *
//               fills stack with the members in the decreasing order of their finish time          *
// return: void                                                                                     *
// precondition: boolean vector visited initialized to false and a empty stack to hold members      *
// postcondition: fills member stack with members in the decreasing order of their finish time      *
//***************************************************************************************************
void MemberGraph::DFS1ToFillStack(Member member, bool visited[], stack<Member> &memberStack)
{
    // Base case, return if member vertex is already visited
    if (visited[member.getId()])
    {
        return;
    }
    // mark the current unvisited member vertex as visited and continue
    visited[member.getId()] = true;

    // Recursive DFS starting from the input member vertex
    for (auto itr = adjMemberList[member.getId()].begin(); itr != adjMemberList[member.getId()].end(); itr++)
    {
        if (!visited[(*itr).getId()])
        {
            DFS1ToFillStack(*itr, visited, memberStack);
        }

        // Push member vertex to the stack they are finished exploring
        memberStack.push(member);
    }
}

//***************************************************************************************************
// description: Implements second Depth-First-Search algorith on the reversed MemberGraph and       *
//               populates a vector of strongly connected members sccmembers                        *
// return: void                                                                                     *
// precondition: boolean vector visited initialized to false and a vector of member vectors         *
// postcondition: populates the vector of member vector with strongly connected members             *
//***************************************************************************************************
void MemberGraph::DFS2InReverse(Member member, bool visited[], vector<Member> *sccMembers)
{
    // Base case, return if the member vertex is already visited
    if (visited[member.getId()])
    {
        return;
    }

    // mark the current unvisited member vertex as visited and continue
    visited[member.getId()] = true;

    // cout << member.getName() << " "; // print to help with testing and debugging

    // push the strongly connected members to a vector as they are discovered
    (*sccMembers).push_back(member);

    // Recursive DFS starting from the input member vertex in the reverseed MemberGraph
    for (auto itr = adjMemberListReverse[member.getId()].begin(); itr != adjMemberListReverse[member.getId()].end(); itr++)
    {
        if (!visited[(*itr).getId()])
        {
            DFS2InReverse(*itr, visited, sccMembers);
        }
    }
}

//***************************************************************************************************
// description: Implements Kosaraju's algorith to find strongly connected components on a graph     *
//               First DFS on MemberGraph to put members in a stack decreasing order of finish time *
//               Second DFS on reversed MemberGraph starting from top vertex in stack to find SCC   *
// return: A vector that contains vectors of strongly connected Members                             *
// precondition: DFS1 and DFS2 functions are implemented and can be called from this function       *
// postcondition: A vector that contains vectors of strongly connected Members is returned          *
//***************************************************************************************************
vector<vector<Member>> MemberGraph::findSCC()
{
    // initialize a vector of strongly connected member vectors & a  member stack
    vector<vector<Member>> scc;
    stack<Member> memberStack;

    // initialize a boolean array to mark all member vertices as false (not visited) to start
    bool *visited = new bool[members];
    for (int i = 0; i < members; i++)
    {
        visited[i] = false;
    }

    // first DFS to put members in stack in reverse order of their finishing times
    for (int i = 0; i < (*memberVec).size(); i++)
    {
        if (!visited[(*memberVec).at(i).getId()])
        {
            DFS1ToFillStack((*memberVec).at(i), visited, memberStack);
        }
    }

    // set all members on visited[] as false for second DFS
    for (int i = 0; i < members; i++)
    {
        visited[i] = false;
    }

    // Second DFS on the reverse array starting from the top element of member stack filled by first DFS
    while (!memberStack.empty())
    {
        Member m = memberStack.top();
        memberStack.pop();

        vector<Member> scMembers;

        if (!visited[m.getId()])
        {
            DFS2InReverse(m, visited, &scMembers);

            // Push the vector of strongly connected members to scc
            scc.push_back(scMembers);
        }
    }

    return scc;
}

/*Refrences
 * https://www.geeksforgeeks.org/strongly-connected-components/
 */