#ifndef SCIENTISTDOMAIN_H
#define SCIENTISTDOMAIN_H
#include <QString>
#include <vector>
#include <string>
#include "sqlconnect.h"
#include "computerscientist.h"
#include "computer.h"
#include "scientistdata.h"

class ScientistDomain
{
public:
    //all this class does is pass data to the UI.
    ScientistDomain();
    vector<ComputerScientist> GetComputerScientist(const QString &str, bool desc);
    bool AddComputerScientist(ComputerScientist& input);
    vector<ComputerScientist> GetDeletedCS();
    vector<ComputerScientist> SearchCS(const QString& search);
    vector<ComputerScientist> SearchCSID(const int& search);
    vector<ComputerScientist> GetCSInnerJoin();
    bool UpdateCS(const QString& tempfirst, const QString& tempmid, const QString& templast, const QString& tempgender, const int& bday, const int& dday, const int& id);
    //---Extra Domain functions---//
    void connect();
    bool MarkDeleted(const QString &tab, const int& id);
    bool UnmarkDeleted(const QString& tab, const int& id);
    bool DeleteAllMarked();
    bool DeleteLink(const int& rowid);
    vector<int> GetRowID();
    bool AddLink(const int& scientists_id, const int& computers_id);
};

#endif // SCIENTISTDOMAIN_H
