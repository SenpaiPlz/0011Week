#ifndef COMPUTERSABSTRACT_H
#define COMPUTERSABSTRACT_H
#include <string>
#include <iostream>

using namespace std;

class computersabstract
{
private:
    int id;
    string name;
    int builtyear;
    string type;
    bool built;

public:
    computersabstract();

    void setid(const int &tmp);
    void setname(const string& tmp);
    void setyear(const int& tmp);
    void settype(const string& tmp);
    void setbuilt(const bool &tmp);

    int getid();
    string getname();
    int getbuiltyear();
    string gettype();
    bool getbuilt();

};

#endif // COMPUTERSABSTRACT_H
