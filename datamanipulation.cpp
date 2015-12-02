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

//-----uses the sorting functions------//
void DataManipulation::sortChoice(char choice, char r)
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
    if(r == 'y')
    {
        reverse(css.begin(), css.end());
    }
}

bool DataManipulation::Search(string& str)
{
    vector<int> indexes;
    for(unsigned int i = 0; i < css.size(); i++)
    {
        //String search for each string in ComputerScientist
        //If we do not hit npos we have found it.
        string tmp = css[i].getName();
        unsigned int j = str.find(tmp);
        if(j != tmp.npos)
        {
            indexes.push_back(i);
        }
        tmp = css[i].getBday();
        j = str.find(tmp);
        if(j != tmp.npos)
        {
            indexes.push_back(i);
        }
        tmp = css[i].getDday();
        j = str.find(tmp);
        if(j != tmp.npos)
        {
            indexes.push_back(i);
        }
        tmp = css[i].getGender();
        j = str.find(tmp);
        if(j != tmp.npos)
        {
            indexes.push_back(i);
        }
    }
    sort(indexes.begin(),indexes.end());
    //makes sure that the indexes are 0,0,0,1,1,1,1,2,2,2 etc
    indexes.erase(unique(indexes.begin(),indexes.end()),indexes.end());
    //Erases multiples fx above vector would become 0,1,2
    indexes.shrink_to_fit();

    vector<ComputerScientist> temp;
    for(size_t i = 0; i < indexes.size(); i++)
    {
        temp.push_back(css[indexes[i]]);
    }
    css = temp;
    css.shrink_to_fit();
    if(!css.empty())
    {
        return true;
    }
    return false;
}

bool DataManipulation::substringSearch(string& str)
{
    vector<int> indexes;
    for(unsigned int i = 0; i < css.size(); i++)
    {
        //Thanks for being there http://www.cplusplus.com/reference/cstring/strstr/
        //I literrally did not know what I was doing here until google turned up this...
        string tmpname = css[i].getName();
        string tmpbday = css[i].getBday();
        string tmpdday = css[i].getDday();
        string tmpgender = css[i].getGender();
        //Creates tmp strings of all the strings in ComputerScientist

        const char *name = strstr(tmpname.c_str(),str.c_str());
        const char *bday = strstr(tmpbday.c_str(),str.c_str());
        const char *dday = strstr(tmpdday.c_str(),str.c_str());
        const char *gender = strstr(tmpgender.c_str(),str.c_str());
        //strstr scans both c_strings, if it does not find the str.c_str() it will return a NULL pointer.

        if(name != NULL || bday != NULL || dday != NULL || gender != NULL)
        {
            indexes.push_back(i);
        }
    }

    vector<ComputerScientist> temp;
    for(size_t i = 0; i < indexes.size(); i++)
    {
        temp.push_back(css[indexes[i]]);
    }
    css = temp;
    css.shrink_to_fit();
    if(!css.empty())
    {
        return true;
    }
    return false;
}
