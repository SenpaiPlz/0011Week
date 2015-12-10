#ifndef COMPUTER_H
#define COMPUTER_H
#include <string>
#include <iostream>

using namespace std;

class Computer
{
private:
    int id;
    string name;
    int builtyear;
    string type;
    bool built;

public:
    Computer();

    void setID(const int &tmp);
    void setName(const string& tmp);
    void setYear(const int& tmp);
    void setType(const string& tmp);
    void setBuilt(const bool &tmp);

    int getID();
    string getName();
    int getYear();
    string getType();
    bool getBuilt();

};

#endif // COMPUTERSABSTRACT_H
