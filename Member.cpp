#include "Member.h"

Member::Member(string name, int id, string speaks, vector<string> understands)
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

int Member::getId() {
    return id;
}

string Member::getSpeaks()
{
    return speaks;
}

vector<string> Member::getUnderstands()
{
    return understands;
}

string Member::toString()
{
    string understoodLangs = " ";
    for (int i = 0; i < understands.size(); i++)
    {
        if (i == 0)
        {
            understoodLangs += understands[i];
        }
        else if (i == understands.size() - 1)
        {
            understoodLangs += " and " + understands[i];
        }
        else
        {
            understoodLangs += ", " + understands[i];
        }
    }
    string memberToString = name + " speaks " + speaks + " and understands" + understoodLangs;
    return memberToString;
}