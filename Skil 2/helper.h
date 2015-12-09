#ifndef HELPER_H
#define HELPER_H
#include "computersabstract.h"
#include "computerscientist.h"
#include <vector>
#include <cctype>
#include <string>

class helper
{
public:
    void Tolower(string &temp);
    bool ValidNumber(string &temp);
    bool ValidCSId(vector<ComputerScientist>& tmp, const int& id);
    bool ValidComputerId(vector<computersabstract>& tmp, const int& id);
    bool CheckValidtyOfString(string& tmp);
    helper();
};

#endif // HELPER_H
