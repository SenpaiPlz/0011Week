#include "computerscientist.h"

using namespace std;

//---------------  Construction of Pylons  ---------------//
ComputerScientist::ComputerScientist()
{
    id = -1337;
}

//---------------  Do we get Set bonuses?  ---------------//
void ComputerScientist::setID(const int &tmp)
{
    if(id == -1337)
        id = tmp;
}

void ComputerScientist::setFirst(const string& tmp)
{
    firstname = tmp;
}

void ComputerScientist::setMid(const string& tmp)
{
    middlename = tmp;
}

void ComputerScientist::setLast(const string& tmp)
{
    lastname = tmp;
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
string ComputerScientist::getFirst()
{
    return firstname;
}
string ComputerScientist::getMid()
{
    return middlename;
}
string ComputerScientist::getLast()
{
    return lastname;
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
