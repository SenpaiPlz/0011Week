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
    friend bool sortByName(ComputerScientist& lhs, ComputerScientist& rhs);
    friend bool sortByGender(ComputerScientist& lhs, ComputerScientist& rhs);
    friend bool sortByBday(ComputerScientist& lhs, ComputerScientist& rhs);
    friend bool sortByDday(ComputerScientist& lhs, ComputerScientist& rhs);
    void Update(DataBank& d1);
    void print();
    void sortChoice(char choise);
<<<<<<< HEAD
    friend bool age();
    void SearchForScientist(const vector<ComputerScientist> str);
=======
>>>>>>> 2d084bc88a0595f2421f4d0e515380b5252b8948
};
#endif // DATAMANIPULATION_H
