#ifndef DATAMANIPULATION_H
#define DATAMANIPULATION_H
#include "computerscientist.h"
#include "databank.h"
#include "ui.h"
#include <vector>
#include <string>


class DataManipulation
{
    string name;
    string gender;
    string bday;
    string dday;
    vector<DataManipulation> css;
public:
    DataManipulation();
    bool sortByName(const DataManipulation& lhs, const DataManipulation& rhs);
    bool sortByGender(const DataManipulation& lhs, const DataManipulation& rhs);
    bool sortByBday(const DataManipulation& lhs, const DataManipulation& rhs);
    bool sortByDday(const DataManipulation& lhs, const DataManipulation& rhs);
    void print();
    void sortChoice(string& choice);
};
#endif // DATAMANIPULATION_H
