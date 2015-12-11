#ifndef HELPER_H
#define HELPER_H
#include "The_Children/computer.h"
#include "The_Children/computerscientist.h"
#include <vector>
#include <cctype>
#include <string>

using namespace std;

class helper
{
public:
    void Tolower(string &temp);
    bool ValidNumber(string &temp);
    bool ValidCSId(vector<ComputerScientist>& tmp, const int& id);
    bool ValidComputerId(vector<Computer>& tmp, const int& id);
    bool CheckValidtyOfString(string& tmp);
    helper();
};

#endif // HELPER_H
