#ifndef MEMBER_H
#define MEMBER_H

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>

using namespace std;

class Member
{
private:
    string name;
    int id;
    string speaks;
    set<string> understands;

public:
    Member() = default;
    Member(string name, int id, string speaks, set<string> understands);
    string getName();
    int getId();
    string getSpeaks();
    set<string> getUnderstands();
    void setName(string memberName);
    void setid(int memberId);
    void setSpeaks(string memberSpeaks);
    void setUnderstands(set<string> memberUnderstands);
    string toString();
};

#endif