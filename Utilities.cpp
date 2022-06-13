#include "Utilities.h"

void Utilities::printVector(vector<string> vec)
{
    cout << "{";
    for (int i = 0; i < vec.size(); i++)
    {
        if (i == vec.size() - 1)
        {
            cout << vec[i];
        }
        else
        {
            cout << vec[i] << ", ";
        }
    }
    cout << "}" << endl;
}

void Utilities::printMemberVector(vector<Member> vec)
{
    cout << "{";
    for (int i = 0; i < vec.size(); i++)
    {
        if (i == vec.size() - 1)
        {
            cout << vec[i].getId() << "_" << vec[i].getName();
            // cout << vec[i].toString();
        }
        else
        {
            cout << vec[i].getId() << "_" << vec[i].getName() << ", ";
            // cout << vec[i].toString() << ", ";
        }
    }
    cout << "}" << endl
         << endl;
}