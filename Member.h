#ifndef MEMBER_H
#define MEMBER_H

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

class Member
{
private:
    string name;
    int id;
    string speaks;
    vector<string> understands;

public:
    Member(string name, int id, string speaks, vector<string> understands);
    string getName();
    string getSpeaks();
    vector<string> getUnderstands();
    string toString();
    int getId();
};

#endif