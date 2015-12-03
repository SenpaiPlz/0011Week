#ifndef COMPUTERSCIENTIST_H
#define COMPUTERSCIENTIST_H
#include <string>

using namespace std;

class ComputerScientist
{
    int id;
    string firstname;
    string middlename;
    string lastname;
    int bday;
    int dday;
    string gender;
public:
    ComputerScientist();

    int getID();
    string getFirst();
    string getMid();
    string getLast();
    string getGender();
    int getBday();
    int getDday();

    void setID(const int& ID);
    void setFirst(const string& tmp);
    void setMiddle(const string& tmp);
    void setLast(const string& tmp);
    void setbday(const int& tmp);
    void setdday(const int& tmp);
    void setgender(const string& tmp);
};

#endif // COMPUTERSCIENTIST_H
