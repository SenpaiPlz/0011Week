#include "datamanipulation.h"
#include <algorithm>            //for sort
#include <vector>
#include <string>

using namespace std;

DataManipulation::DataManipulation()
{
    name = "NA";
    bday = "NA";
    dday = "NA";
    gender = "NA";
}

bool DataManipulation::sortByName(const DataManipulation& lhs, const DataManipulation& rhs)
{
    return lhs.name < rhs.name;
}

bool DataManipulation::sortByGender(const DataManipulation& lhs, const DataManipulation& rhs)
{
    return lhs.gender < rhs.gender;
}

bool DataManipulation::sortByBday(const DataManipulation& lhs, const DataManipulation& rhs)
{
    return lhs.bday < rhs.bday;
}

bool DataManipulation::sortByDday(const DataManipulation& lhs, const DataManipulation& rhs)
{
    return lhs.dday < rhs.dday;
}

void DataManipulation::print()
{
    for(unsigned int i = 0; i != css.size(); i++)
    {
        cout << css.at(i).name << " " << css.at(i).gender << " " <<
                css.at(i).bday << " " << css.at(i).dday << endl;
    }
}

void DataManipulation::sortChoice(string& choice)
{
    if(choice == name)
    {
        sort(css.begin(), css.end(), sortByName);
    }
    if(choice == gender)
    {
        sort(css.begin(), css.end(), sortByGender);
    }
    if(choice == bday)
    {
        sort(css.begin(), css.end(), sortByBday);
    }
    if(choice == dday)
    {
        sort(css.begin(), css.end(), sortByDday);
    }
}

