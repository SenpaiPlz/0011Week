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
    int getid();
    string getname();
    int getbuiltyear();
    string gettype();
    bool getbuilt();

};

#endif // COMPUTERSABSTRACT_H
