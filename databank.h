#ifndef DATABANK_H
#define DATABANK_H
#include <vector>
#include "computerscientist.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

class DataBank
{
    vector<ComputerScientist> css;
public:
    DataBank();
    void testDataBank();
    void PopulateWithCSV();
    bool isempty(ifstream& file);
    vector<ComputerScientist> GetDataBank();
    void AddToDataBank(const string& tmpname, const string& tmpbday, const string& tmpdday,const string& tmpgender);
    void DeleteFromDataBank(int ele);
};

#endif // DATABANK_H
