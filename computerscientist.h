#ifndef COMPUTERSCIENTIST_H
#define COMPUTERSCIENTIST_H
#include <string>

using namespace std;

class ComputerScientist
{
    friend class Databank;
    friend class DataManipulation;
    string name;
    string bday;
    string dday;
    string gender;
    string age;
public:
    ComputerScientist();
    ComputerScientist(const string& tmpname, const int& tmpbday, const int& tmpdday, const string& tmpgender);

    string getName();
    string getGender();
    string getBday();
    string getDday();
    string getAge();

    void setname(const string& tmp);
    void setbday(const string& tmp);
    void setdday(const string& tmp);
    void setgender(const string& tmp);

    friend ComputerScientist operator- (const ComputerScientist& d, const ComputerScientist& b);
    /*
     * Maybe implement somewhere else.
     *
     friend istream& operator >>(istream& in, ComputerScientist& cs1);
     friend ostream& operator <<(ostream& out, ComputerScientist& cs1);
     */
};

#endif // COMPUTERSCIENTIST_H
