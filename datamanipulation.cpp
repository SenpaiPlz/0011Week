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

/*
 * This is fine but I do think we should give the user
 * choice if he purelly wants to sort by age, gender and so forth,
 * this is good for a priority search, ie. first x, then name.
 * We just have to say so in our UI.
 *
 */

bool sortByGender(ComputerScientist& lhs, ComputerScientist& rhs)
{
    if(lhs.getGender() == rhs.getGender())
    {
        return lhs.getName() < rhs.getName();
    }
    return lhs.getGender() < rhs.getGender();
}

bool sortByBday(ComputerScientist& lhs, ComputerScientist& rhs)
{
    if(lhs.getBday() == rhs.getBday())
    {
        return lhs.getName() < rhs.getName();
    }
    return lhs.getBday() < rhs.getBday();
}

bool sortByDday(ComputerScientist& lhs, ComputerScientist& rhs)
{
    if(lhs.getDday() == rhs.getDday())
    {
        return lhs.getName() < rhs.getName();
    }
    return lhs.getDday() < rhs.getDday();
}

//Remove once UI is there.
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

