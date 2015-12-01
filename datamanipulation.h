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
    vector<ComputerScientist> ReturnVector();
    vector<ComputerScientist> ReturnReverse();
    DataManipulation();
    DataManipulation(DataBank& d1);
    friend bool sortByName(ComputerScientist& lhs, ComputerScientist& rhs);
    friend bool sortByGender(ComputerScientist& lhs, ComputerScientist& rhs);
    friend bool sortByBday(ComputerScientist& lhs, ComputerScientist& rhs);
    friend bool sortByDday(ComputerScientist& lhs, ComputerScientist& rhs);
    friend bool sortByRName(ComputerScientist& lhs, ComputerScientist& rhs);
    friend bool sortByRGender(ComputerScientist& lhs, ComputerScientist& rhs);
    friend bool sortByRBday(ComputerScientist& lhs, ComputerScientist& rhs);
    friend bool sortByRDday(ComputerScientist& lhs, ComputerScientist& rhs);
    void Update(DataBank& d1);
    void sortChoice(char choice);
    void sortReverseChoice(char choice);
    //vecor<ComputerScientist> DataManipulation::SearchForScientist(string search);
};
#endif // DATAMANIPULATION_H
