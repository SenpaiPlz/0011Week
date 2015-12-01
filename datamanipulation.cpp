#include "datamanipulation.h"

using namespace std;

DataManipulation::DataManipulation()
{

}

DataManipulation::DataManipulation(DataBank& d1)
{
    css = d1.GetDataBank();
}

vector<ComputerScientist> DataManipulation::ReturnVector()
{
    return css;
}

//---------sorting----------//
bool sortByName(ComputerScientist& lhs, ComputerScientist& rhs)
{
    return lhs.getName() < rhs.getName();
}

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

void DataManipulation::Update(DataBank& d1)
{
    css.clear();
    css = d1.GetDataBank();
    css.shrink_to_fit();
}

//-----Reverse Sorting------//
bool sortByRName(ComputerScientist& lhs, ComputerScientist& rhs)
{
    return lhs.getName() > rhs.getName();
}

bool sortByRGender(ComputerScientist& lhs, ComputerScientist& rhs)
{
    if(lhs.getGender() == rhs.getGender())
    {
        return lhs.getName() > rhs.getName();
    }
    return lhs.getGender() > rhs.getGender();
}

bool sortByRBday(ComputerScientist& lhs, ComputerScientist& rhs)
{
    if(lhs.getBday() == rhs.getBday())
    {
        return lhs.getName() > rhs.getName();
    }
    return lhs.getBday() > rhs.getBday();
}

bool sortByRDday(ComputerScientist& lhs, ComputerScientist& rhs)
{
    if(lhs.getDday() == rhs.getDday())
    {
        return lhs.getName() > rhs.getName();
    }
    return lhs.getDday() > rhs.getDday();
}

//-----uses the sorting functions------//
void DataManipulation::sortChoice(char choice)
{
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

void DataManipulation::sortReverseChoice(char choice)
{
    if(choice == 'N' || choice == 'n')
    {
        sort(css.begin(), css.end(), sortByRName);
    }
    else if(choice == 'G' || choice == 'g')
    {
        sort(css.begin(), css.end(), sortByRGender);
    }
    else if(choice == 'D' || choice == 'd')
    {
        sort(css.begin(), css.end(), sortByRBday);
    }
    else if(choice == 'B' || choice == 'b')
    {
        sort(css.begin(), css.end(), sortByRDday);
    }
}
