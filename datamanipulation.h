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
    DataManipulation();
    DataManipulation(DataBank& d1);

    void Update(DataBank& d1);
    void sortChoice(char choice, char reverse);
    bool Search(string &str);
    bool substringSearch(string& str);

    //Search parameters
    friend bool sortByName(ComputerScientist& lhs, ComputerScientist& rhs);
    friend bool sortByGender(ComputerScientist& lhs, ComputerScientist& rhs);
    friend bool sortByBday(ComputerScientist& lhs, ComputerScientist& rhs);
    friend bool sortByDday(ComputerScientist& lhs, ComputerScientist& rhs);
};
#endif // DATAMANIPULATION_H
