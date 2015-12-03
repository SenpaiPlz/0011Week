#include "computerscientist.h"

using namespace std;

//---------------  Construction of Pylons  ---------------//
ComputerScientist::ComputerScientist()
{
    id = -1337;
}

ComputerScientist::ComputerScientist(const string& tmpname, const int& tmpbday, const int& tmpdday, const string& tmpgender)
{
    name = tmpname;
    bday = tmpbday;
    dday = tmpdday;
    gender = tmpgender;
}

//---------------  Do we get Set bonuses?  ---------------//
void ComputerScientist::setname(const string& tmp)
{
    name = tmp;
}

void ComputerScientist::setbday(const int &tmp)
{
    bday = tmp;
}

void ComputerScientist::setdday(const int& tmp)
{
    dday = tmp;
}

void ComputerScientist::setgender(const string& tmp)
{
    gender = tmp;
}

//---------------  Quads Get  ---------------//
string ComputerScientist::getName()
{
    return name;
}
string ComputerScientist::getGender()
{
    return gender;
}
int ComputerScientist::getBday()
{
    return bday;
}
int ComputerScientist::getDday()
{
    return dday;
}
