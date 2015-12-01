#include "computerscientist.h"

using namespace std;

//------------- Construction of Pylos -------------//
ComputerScientist::ComputerScientist()
{
    name = "NA";
    bday = "NA";
    dday = "NA";
    gender = "NA";
}

ComputerScientist::ComputerScientist(const string& tmpname, const int& tmpbday, const int& tmpdday, const string& tmpgender)
{
        name = tmpname;
        bday = tmpbday;
        dday = tmpdday;
        gender = tmpgender;
}

//------------- Do we get Set bonuses? -------------//
void ComputerScientist::setname(const string& tmp)
{
    name = tmp;
}

void ComputerScientist::setbday(const string& tmp)
{
    bday = tmp;
}

void ComputerScientist::setdday(const string& tmp)
{
    dday = tmp;
}

void ComputerScientist::setgender(const string& tmp)
{
    gender = tmp;
}

//------------- Quads Get -------------//
string ComputerScientist::getName()
{
    return name;
}

string ComputerScientist::getGender()
{
    return gender;
}

string ComputerScientist::getBday()
{
    return bday;
}

string ComputerScientist::getDday()
{
    return dday;
}

ComputerScientist operator- (const ComputerScientist& d, const ComputerScientist& b)
{
    ComputerScientist temp;
    if(d.empty())
        temp.age = 2015 - b.bday;
    else
        temp.age = d.dday - b.bday;
    return temp;
}

string ComputerScientist::getAge()
{
    if(dday.empty())
    {
        return age = 2015 - bday;
    }
    else
    {
        return age = dday - bday;
        //Then we can write "Died at" << age
        //Or write another list next to it, alive or dead.
    }
}

//------------- Pedo Mellon a Minno -------------//

/*
 * Not sure if we should implement these here...
 *
 friend istream& operator >>(istream& in, ComputerScientist& cs1)
 {

 }

 friend ostream& operator <<(ostream& out, ComputerScientist& cs1)
 {

 }
*/
