#include "computersabstract.h"

computersabstract::computersabstract()
{
    id = -42;
}

//---------------  Do we get Set bonuses?  ---------------//
void computersabstract::setid(const int &tmp)
{
    if(id == -42)
        id = tmp;
}

void computersabstract::setname(const string& tmp)
{
    name = tmp;
}

void computersabstract::setyear(const int& tmp)
{
    builtyear = tmp;
}

void computersabstract::settype(const string& tmp)
{
    type = tmp;
}


void computersabstract::setbuilt(const bool &tmp)
{
    built = tmp;
}

//---------------  Quads Get  ---------------//

int computersabstract::getid()
{
    return id;
}
string computersabstract::getname()
{
    return name;
}

int computersabstract::getbuiltyear()
{
    return builtyear;
}
string computersabstract::gettype()
{
    return type;
}
bool computersabstract::getbuilt()
{
    return built;
}

