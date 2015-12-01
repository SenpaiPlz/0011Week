#include "search.h"
#include "computerscientist.h"
#include "databank.h"
#include "ui.h"
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
Search::earch()
{

}

void Search::getSearchConditions(string& x)
{
    cin >> x;
}

void Search::searchForScientist(const string x)
{

    ifstream C_S_Search;

    C_S_Search.open("list_of_famous_feople.txt");
    list<string> checkS = C_S_Scearch;

    for(list<string>::iterator i = checkS.begin(); i != checkS.end(); ++i)
        {

            ComputerScientist temp = *i;
            ComputerScientist name = temp.name
            if(name.find(x) != string::npos)
        }
}




