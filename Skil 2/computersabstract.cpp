#include "computersabstract.h"

computersabstract::computersabstract()
{
    id = -42;
}

//---------------  Do we get Set bonuses?  ---------------//
void computersabstract::setID(const int &tmp)
{
    if(id == -42)
        id = tmp;
}

void computersabstract::setName(const string& tmp)
{
    name = tmp;
}

void computersabstract::setYear(const int& tmp)
{
    builtyear = tmp;
}

void computersabstract::setType(const string& tmp)
{
    type = tmp;
}


void computersabstract::setBuilt(const bool &tmp)
{
    built = tmp;
}

//---------------  Quads Get  ---------------//

int computersabstract::getID()
{
    return id;
}
string computersabstract::getName()
{
    return name;
}

int computersabstract::getYear()
{
    return builtyear;
}
string computersabstract::getType()
{
    return type;
}
bool computersabstract::getBuilt()
{
    return built;
}
