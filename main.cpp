#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <list>

#include "Member.h"
#include "MemberGraph.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Member Fran("Fran", 0, "French", vector<string>{"Italian"});
    Member Enid("Enid", 1, "English", vector<string>{"German"});
    Member George("George", 2, "German", vector<string>{"Italian"});
    Member Ian("Ian", 3, "Italian", vector<string>{"French", "Spanish"});
    Member Spencer("Spencer", 4, "Spanish", vector<string>{"Portuguese"});
    Member Polly("Polly", 5, "Portuguese", vector<string>{"Spanish"});

    cout << Fran.toString() << endl;
    cout << Enid.toString() << endl;
    cout << George.toString() << endl;
    cout << Ian.toString() << endl;
    cout << Spencer.toString() << endl;
    cout << Polly.toString() << endl;
    cout << endl;

    MemberGraph memG(4);
    memG.addEdge(Fran, Enid);
    memG.addEdge(Fran, George);
    memG.addEdge(Enid, George);
    memG.addEdge(George, Ian);
    memG.addEdge(George, Fran);
    memG.addEdge(Ian, Ian);

    memG.DFS(George);

    return 0;
}
