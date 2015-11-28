#ifndef COMPUTERSCIENTIST_H
#define COMPUTERSCIENTIST_H
#include <string>

using namespace std;

class ComputerScientist
{
    string mame;
    int bday;
    int dday;
    string gender;
public:
    ComputerScientist();
    ComputerScientist(const string& tmpname, const int& tmpbday, const int& tmpdday, const string& tmpgender);

    string getName();
    string getGender();
    int getBday();
    int getDday();

    void setname(const string& tmp);
    void setbday(const int& tmp);
    void setdday(const int& tmp);
    void setgender(const string& tmp);
    /*
     *  Mabey implement somewhere else.
     *
    friend istream& operator >>(istream& in, ComputerScientist& cs1);
    friend ostream& operator <<(ostream& out, ComputerScientist& cs1);
    */
};

#endif // COMPUTERSCIENTIST_H
