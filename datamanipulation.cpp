#include "datamanipulation.h"

using namespace std;

DataManipulation::DataManipulation(DataBank& d1)
{
    css = d1.GetDataBank();
}

//---------sorting----------//
bool sortByName(ComputerScientist& lhs,ComputerScientist& rhs)
{
    return lhs.getName() < rhs.getName();
}

bool sortByGender(ComputerScientist& lhs, ComputerScientist& rhs)
{
    return lhs.getGender() < rhs.getGender();
}

bool sortByBday(ComputerScientist& lhs, ComputerScientist& rhs)
{
    return lhs.getBday() < rhs.getBday();
}

bool sortByDday(ComputerScientist &lhs, ComputerScientist &rhs)
{
    return lhs.getDday() < rhs.getDday();
}

//Prints out everything, here or somewhere else? only for testeroni
void DataManipulation::print()
{
    for(unsigned int i = 0; i != css.size(); i++)
    {
        cout << css[i].getName() << "\t" << css[i].getGender() << "\t" <<
                css[i].getBday() << "\t" << css[i].getDday() << endl;
    }
}

//-----uses the sorting functions------//
void DataManipulation::sortChoice(char choice)
{
    if(choice == 'N' || choice == 'n')
        sort(css.begin(), css.end(), sortByName);
    else if(choice == 'G' || choice == 'g')
        sort(css.begin(), css.end(), sortByGender);
    else if(choice == 'D' || choice == 'd')
        sort(css.begin(), css.end(), sortByDday);
    else if(choice == 'B' || choice == 'b')
        sort(css.begin(), css.end(), sortByBday);
}
