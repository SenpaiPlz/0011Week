#ifndef DATABANK_H
#define DATABANK_H
#include <vector>
#include <fstream>
#include <cstdlib>
#include "computerscientist.h"

using namespace std;

class DataBank
{
    vector<ComputerScientist> css;
public:
    DataBank();
    void testDataBank();
    void PopulateWithCSV();
};

#endif // DATABANK_H
