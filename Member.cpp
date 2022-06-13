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

#include "Member.h"

Member::Member(string name, int id, string speaks, set<string> understands)
{
    this->name = name;
    this->id = id;
    this->speaks = speaks;
    this->understands = understands;
}

string Member::getName()
{
    return name;
}

int Member::getId()
{
    return id;
}

string Member::getSpeaks()
{
    return speaks;
}

set<string> Member::getUnderstands()
{
    return understands;
}

void Member::setName(string memberName){
    name = memberName;
}
void Member::setid(int memberId) {
    id = memberId;
}
void Member::setSpeaks(string memberSpeaks){
    speaks = memberSpeaks;

}
void Member::setUnderstands(set<string> memberUnderstands) {
    understands = memberUnderstands;
}

string Member::toString()
{
    string understoodLangs = " ";

    for(auto itr = understands.begin(); itr!= understands.end(); itr++) {
        understoodLangs += (*itr + " ");
    }

    string memberToString = name + " speaks " + speaks + " and understands" + understoodLangs;
    return memberToString;
}