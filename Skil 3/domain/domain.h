#ifndef DOMAIN_H
#define DOMAIN_H
#include <QString>
#include <vector>
#include <string>
#include "Data/sqlconnect.h"
#include "Data/scientistdata.h"
#include "Data/computerdata.h"
#include "The_Children/computerscientist.h"
#include "The_Children/computer.h"


class Domain
{
public:
    //all this class does is pass data to the UI.
    Domain();

    //LINKING
    bool DeleteAllMarked();
    bool DeleteLink(const int& rowid);
    vector<int> GetRowID();
    bool AddLink(const int& scientists_id, const int& computers_id);

    //CSS
    vector<ComputerScientist> GetComputerScientist(const QString &str, bool desc);
    bool AddComputerScientist(ComputerScientist& input);
    vector<ComputerScientist> GetDeletedCS();
    vector<ComputerScientist> SearchCS(const QString& search);
    vector<ComputerScientist> SearchCSID(const int& search);
    vector<ComputerScientist> GetCSInnerJoin();
    bool UpdateCS(const QString& tempfirst, const QString& tempmid, const QString& templast, const QString& tempgender, const int& bday, const int& dday, const int& id);

    //COMPUTERS
    vector<Computer> GetComputers(const QString &str, bool desc);
    bool AddComputer(Computer& input);
    vector<Computer> GetDeletedComputers();
    vector<Computer> SearchComputerID(const int& search);
    vector<Computer> SearchComputer(const QString& search);
    vector<Computer> GetComputerInnerJoin();
    bool UpdateComputer(const QString &tempname, const int &year, const QString &type, const bool& built, const int &id);

    //MODULAR
    void connect();
    bool MarkDeleted(const QString &tab, const int& id);
    bool UnmarkDeleted(const QString& tab, const int& id);
};

#endif // DOMAIN_H
