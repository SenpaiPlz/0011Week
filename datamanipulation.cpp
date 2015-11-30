#include "datamanipulation.h"

using namespace std;

DataManipulation::DataManipulation(DataBank& d1)
{
    css = d1.GetDataBank();
}

//---------sorting----------//
bool sortByName(ComputerScientist& lhs, ComputerScientist& rhs)
{
    return lhs.getName() < rhs.getName();
}

bool sortByGender(ComputerScientist& lhs, ComputerScientist& rhs)
{
    while(lhs.getGender() == rhs.getGender())
    {
        return lhs.getName() < rhs.getName();
    }
    return lhs.getGender() < rhs.getGender();
}

bool sortByBday(ComputerScientist& lhs, ComputerScientist& rhs)
{
    while(lhs.getBday() == rhs.getBday())
    {
        return lhs.getName() < rhs.getName();
    }
    return lhs.getBday() < rhs.getBday();
}

bool sortByDday(ComputerScientist& lhs, ComputerScientist& rhs)
{
    while(lhs.getDday() == rhs.getDday())
    {
        return lhs.getName() < rhs.getName();
    }
    return lhs.getDday() < rhs.getDday();
}

//Prints out everything, here or somewhere else? only for testeroni
/*void DataManipulation::print()
{
    for(unsigned int i = 0; i != css.size(); i++)
    {
        cout << css.at(i).getName() << "\t" << css.at(i).getGender() << "\t" <<
                css.at(i).getBday() << "\t" << css.at(i).getDday << endl;
    }
}*/

//-----uses the sorting functions------//
void DataManipulation::sortChoice(char choice)
{
    /*char choice;
    cout << "Enter a letter: " << endl;
    cout << "N. Sort by name"
         << "G. Sort by gender"
         << "B. sort by year of birth"
         << "D. sort by year of death" << endl;

    cin >> choice;*/

    if(choice == 'N' || choice == 'n')
    {
        sort(css.begin(), css.end(), sortByName);
    }
    else if(choice == 'G' || choice == 'g')
    {
        sort(css.begin(), css.end(), sortByGender);
    }
    else if(choice == 'D' || choice == 'd')
    {
        sort(css.begin(), css.end(), sortByBday);
    }
    else if(choice == 'B' || choice == 'b')
    {
        sort(css.begin(), css.end(), sortByDday);
    }
}

