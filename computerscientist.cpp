#include "computerscientist.h"

using namespace std;
//---------------  Construction of Pylons  ---------------//
ComputerScientist::ComputerScientist()
{
    name = "";
    bday = 0;
    dday = -1;
    gender = "";
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

void ComputerScientist::setbday(const int& tmp)
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

//---------------  Pedo Mellon a Minno  ---------------//

/*
 *  Not Sure if we should implement these here...
 *
friend istream& operator >>(istream& in, ComputerScientist& cs1)
{

}

friend ostream& operator <<(ostream& out, ComputerScientist& cs1)
{

}
*/
