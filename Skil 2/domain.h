#ifndef DOMAIN_H
#define DOMAIN_H
#include <QString>
#include <vector>
#include "sqlconnect.h"
#include <string>
#include "computerscientist.h"
#include "computersabstract.h"
#include "sqlquerydata.h"

class domain
{
public:
    //all this class does is pass data to the UI.
    domain();
    void connect();
    vector<computersabstract> GetComputers(const QString &str, bool desc);
    vector<ComputerScientist> GetComputerScientist(const QString &str, bool desc);
    bool AddComputerScientist(ComputerScientist& input);
    bool AddComputer(computersabstract& input);
    bool MarkDeleted(const QString &tab, const int& id);
    bool UnmarkDeleted(const QString& tab, const int& id);
    bool DeleteAllMarked();
    vector<ComputerScientist> GetDeletedCS();
    vector<computersabstract> GetDeletedComputers();
    vector<ComputerScientist> SearchCS(const QString& search);
    vector<ComputerScientist> SearchCSID(const int& search);
    vector<computersabstract> SearchComputerID(const int& search);
    vector<computersabstract> SearchComputer(const QString& search);
    vector<ComputerScientist> GetCSInnerJoin();
    vector<computersabstract> GetComputerInnerJoin();
    bool DeleteLink(const int& rowid);
    vector<int> GetRowID();
    bool AddLink(const int& scientists_id, const int& computers_id);
    bool UpdateCS(const QString& tempfirst, const QString& tempmid, const QString& templast, const QString& tempgender, const int& bday, const int& dday, const int& id);
    bool UpdateComputer(const QString &tempname, const int &year, const QString &type, const bool& built, const int &id);
};

#endif // DOMAIN_H
