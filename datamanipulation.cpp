#include "datamanipulation.h"
#include <algorithm>            //for sort
#include <vector>
#include <string>
#include <iostream>

using namespace std;


//Not sure if this is necessary ?
DataManipulation::DataManipulation()
{
    name = "NA";
    bday = "NA";
    dday = "NA";
    gender = "NA";
}

//---------sorting----------//
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

//Prints out everything, here or somewhere else?
void DataManipulation::print()
{
    for(unsigned int i = 0; i != css.size(); i++)
    {
        cout << css.at(i).name << "\t" << css.at(i).gender << "\t" <<
                css.at(i).bday << "\t" << css.at(i).dday << endl;
    }
}

//-----uses the sorting functions------//
void DataManipulation::sortChoice()
{
    char choice;
    cout << "Enter a number: " << endl;
    cout << "1. Sort by name"
         << "2. Sort by gender"
         << "3. sort by year of birth"
         << "4. sort by year of death" << endl;

    cin >> choice;

    if(choice == '1')
    {
        sort(css.begin(), css.end(), sortByName);
    }
    if(choice == '2')
    {
        sort(css.begin(), css.end(), sortByGender);
    }
    if(choice == '3')
    {
        sort(css.begin(), css.end(), sortByBday);
    }
    if(choice == '4')
    {
        sort(css.begin(), css.end(), sortByDday);
    }
}

