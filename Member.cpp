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