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

#ifndef MEMBER_H
#define MEMBER_H

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <set>

using namespace std;

//*************************************************************************************
// description: Custom Member class for creating Member objects                       *
// return: Creates Member object with member variables and their getters & setters    *
// precondition: name, id and languages spoken & understood                           *
//              String name (name of the member)                                      *  
//              int id (member id)                                                    *
//              string speaks (languaage spoken by member)                            *
//              set<string> understands (langiage member understands)                 *
// postcondition: Instantiates Member object                                          *
//*************************************************************************************
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