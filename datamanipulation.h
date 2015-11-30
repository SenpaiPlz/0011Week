#ifndef DATAMANIPULATION_H
#define DATAMANIPULATION_H
#include "computerscientist.h"
#include "databank.h"
#include "ui.h"
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

class DataManipulation
{
    vector<ComputerScientist> css;
public:
    DataManipulation(DataBank& d1);
    friend bool sortByName( ComputerScientist& lhs, ComputerScientist& rhs);
    friend bool sortByGender(ComputerScientist& lhs, ComputerScientist& rhs);
    friend bool sortByBday(ComputerScientist &lhs, ComputerScientist &rhs);
    friend bool sortByDday(ComputerScientist& lhs, ComputerScientist& rhs);
    void print();
    void sortChoice(char choice);
};
#endif // DATAMANIPULATION_H
