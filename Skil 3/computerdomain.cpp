#include "computerdomain.h"

ComputerDomain::ComputerDomain()
{
}

vector<Computer> ComputerDomain::GetComputers(const QString &str, bool desc)
{
    ComputerData get;
    return get.GetComputers(str,desc);
}

bool ComputerDomain::AddComputer(Computer& input)
{
    ComputerData add;
    return add.AddComputer(input);
}

vector<Computer> ComputerDomain::GetDeletedComputers()
{
    ComputerData tmp;
    return tmp.GetDeletedComputers();
}

vector<Computer> ComputerDomain::SearchComputerID(const int& search)
{
    ComputerData seek;
    return seek.SearchComputerID(search);
}

vector<Computer> ComputerDomain::SearchComputer(const QString& search)
{
    ComputerData seek;
    return seek.SearchComputer(search);
}

vector<Computer> ComputerDomain::GetComputerInnerJoin()
{
    ComputerData join;
    return join.GetComputerInnerJoin();
}

bool ComputerDomain::UpdateComputer(const QString &tempname, const int &year, const QString &type, const bool& built, const int &id)
{
    ComputerData update;
    return update.UpdateComputer(tempname,year,type,built,id);
}
