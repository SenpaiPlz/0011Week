#ifndef COMPUTERDOMAIN_H
#define COMPUTERDOMAIN_H
#include <QString>
#include <vector>
#include <string>
#include "sqlconnect.h"
#include "computerscientist.h"
#include "computer.h"
#include "computerdata.h"

class ComputerDomain
{
public:
    //all this class does is pass data to the UI.
    ComputerDomain();
    vector<Computer> GetComputers(const QString &str, bool desc);
    bool AddComputer(Computer& input);
    vector<Computer> GetDeletedComputers();
    vector<Computer> SearchComputerID(const int& search);
    vector<Computer> SearchComputer(const QString& search);
    vector<Computer> GetComputerInnerJoin();
    bool UpdateComputer(const QString &tempname, const int &year, const QString &type, const bool& built, const int &id);
};

#endif // COMPUTERDOMAIN_H
