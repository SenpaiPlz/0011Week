#include "databank.h"
#include "computerscientist.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

DataBank::DataBank()
{
    //implying this does nothing...
}


void DataBank::PopulateWithCSV()
{
    ifstream in("testdata.csv", ios::in);

    if(!in.is_open())
    {
        cout << "FILE OPEN ERROR";
        exit(7);
    }
    string tmp;
    ComputerScientist Cstemp;

    while(!in.eof())
    {
        getline(in,tmp,',');
        Cstemp.setname(tmp);
        getline(in,tmp,',');
        Cstemp.setbday(tmp);
        getline(in,tmp,',');
        Cstemp.setdday(tmp);
        getline(in,tmp,',');
        Cstemp.setgender(tmp);
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
