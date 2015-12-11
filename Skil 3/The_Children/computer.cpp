#include "computer.h"

Computer::Computer()
{
    id = -42;
}

//---------------  Do we get Set bonuses?  ---------------//
void Computer::setID(const int &tmp)
{
    //allows us to set id once, and only once;
    if(id == -42)
        id = tmp;
}

void Computer::setName(const string& tmp)
{
    name = tmp;
}

void Computer::setYear(const int& tmp)
{
    builtyear = tmp;
}

void Computer::setType(const string& tmp)
{
    type = tmp;
}


void Computer::setBuilt(const bool &tmp)
{
    built = tmp;
}

//---------------  Quads Get  ---------------//

int Computer::getID()
{
    return id;
}
string Computer::getName()
{
    return name;
}

int Computer::getYear()
{
    return builtyear;
}
string Computer::getType()
{
    return type;
}
bool Computer::getBuilt()
{
    return built;
}
