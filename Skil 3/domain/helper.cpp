#include "helper.h"


helper::helper()
{

}


bool helper::CheckValidtyOfString(string tmp)
{
    for(size_t i = 0; i < tmp.size(); i++)
    {
        if(!isalpha(tmp[i]) && tmp[i] != ' ' && tmp[i] != '.')
        {
            return false;
        }
    }
    return !tmp.empty();
}


void helper::Tolower(string &temp)
{
    for(unsigned int i = 0; i < temp.size(); i++)
    {
        temp[i] = tolower(temp[i]);
    }
}

bool helper::ValidNumber(string temp)
{
    for(unsigned int i = 0; i < temp.size(); i++)
    {
        if(!isdigit(temp[i]))
        {
            return false;
        }
    }
    return !temp.empty();
}



bool helper::ValidCSId(vector<ComputerScientist>& tmp, const int& id)
{
    for(size_t i = 0; i < tmp.size(); i++)
    {
        if(tmp[i].getID() == id)
        {
            return true;
        }
    }
    return false;
}

bool helper::ValidComputerId(vector<Computer>& tmp, const int& id)
{
    for(size_t i = 0; i < tmp.size(); i++)
    {
        if(tmp[i].getID() == id)
        {
            return true;
        }
    }
    return false;
}
