#include "databank.h"
#include "computerscientist.h"
#include <iostream>
#include <string>

using namespace std;

DataBank::DataBank()
{
    //implying this does nothing...
}


void DataBank::PopulateWithCSV()
{
    ifstream in("testdata.csv");

    if(!in.is_open())
    {
        cout << "FILE OPEN ERROR";
        exit(7);
    }
    string tmp;
    ComputerScientist Cstemp;

    while(in.eof())
    {
        getline(in,tmp,',');
        Cstemp.name = tmp;
        getline(in,tmp,',');
        Cstemp.bday = tmp;
        getline(in,tmp,',');
        Cstemp.dday = tmp;
        getline(in,tmp,',');
        Cstemp.gender = tmp;
        css.push_back(Cstemp);
    }
    in.close();
}

void DataBank::testDataBank()
{
    for(size_t i = 0; i < css.size(); i++)
    {
        cout << css[i].getName() << " " << css[i].getBday() << " " << css[i].getDday()<< " " << css[i].getGender();
    }
}
