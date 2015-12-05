#include <iostream>
#include "sqlquerydata.h"
#include "computerscientist.h"
#include <vector>
#include "computersabstract.h"
#include "sqlconnect.h"
using namespace std;

int main()
{

    SQLQueryData data;
    data.InitConnect();
    vector<ComputerScientist> test = data.GetComputerScientist();
    for(size_t i = 0; i < test.size(); i++)
    {
        cout << i+1 << "\t" << test[i].getID() << ": " << test[i].getFirst() << " ";
        if(test[i].getMid() != "")
        {
        cout << test[i].getMid() << " ";
        }
        cout << test[i].getLast() << "\n";
    }
    cout << "\n\n";
    vector<computersabstract> temp = data.GetComputers();
    for(size_t i = 0; i < temp.size(); i++)
    {
        cout << i+1 << "\t" << temp[i].getID() << ": " << temp[i].getName() << "\n";
    }
    return 0;
}
