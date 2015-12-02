#ifndef DATAMANIPULATION_H
#define DATAMANIPULATION_H
#include "computerscientist.h"
#include "databank.h"
#include "ui.h"
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <cstring>


class DataManipulation
{
    vector<ComputerScientist> css;
public:
    vector<ComputerScientist> ReturnVector();
    vector<ComputerScientist> ReturnReverse();
    DataManipulation();
    DataManipulation(DataBank& d1);

    friend bool sortByName(ComputerScientist& lhs, ComputerScientist& rhs);
    friend bool sortByGender(ComputerScientist& lhs, ComputerScientist& rhs);
    friend bool sortByBday(ComputerScientist& lhs, ComputerScientist& rhs);
    friend bool sortByDday(ComputerScientist& lhs, ComputerScientist& rhs);

    void Update(DataBank& d1);
    void sortChoice(char choice, char reverse);
    bool Search(string &str);
    bool substringSearch(string& str);
};
#endif // DATAMANIPULATION_H
