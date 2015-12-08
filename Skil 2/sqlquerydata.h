#ifndef SQLQUERYDATA_H
#define SQLQUERYDATA_H
#include <QSqlQuery>
#include <QString>
#include <QVariant>
#include <QSqlError>
#include <vector>
#include "sqlconnect.h"
#include <string>
#include "computerscientist.h"
#include "computersabstract.h"

using namespace std;

class SQLQueryData
{
    //        HELP FUNCTIONS        //
    void FillcomputerVector(QSqlQuery& query, vector<computersabstract> &temp);
    void FillcsVector(QSqlQuery& query, vector<ComputerScientist>& temp);
public:
    SQLQueryData();
    void InitConnect();

    //        ADDING FUNCTIONS        //
    bool AddComputerScientist(ComputerScientist& input);
    bool AddComputer(computersabstract& input);

    //        SORTING FUNCTIONS        //
    vector<computersabstract> GetComputers(const QString &str, bool desc);
    vector<ComputerScientist> GetComputerScientist(const QString &str, bool desc);

    //        DELETING FUNCTIONS        //
    bool MarkDeleted(const QString &tab, const int& id);
    bool UnmarkDeleted(const QString& tab, const int& id);
    bool DeleteAllMarked();
    vector<ComputerScientist> GetDeletedCS();
    vector<computersabstract> GetDeletedComputers();

    /*        LINKING FUNCTIONS
    /    Sorry that I used two functions instead of one
    /    this ;_; was easier to pass into the table that was already made
    */
    vector<ComputerScientist> GetCSInnerJoin();
    vector<computersabstract> GetComputerInnerJoin();
    vector<int> GetRowID();
    bool DeleteLink(const int& rowid);
    bool AddLink(const int& scientists_id, const int& computers_id);

    //        SEARCH FUNCTIONS        //
    vector<ComputerScientist> SearchCS(const QString& search);
    vector<ComputerScientist> SearchCSID(const int& search);
    vector<computersabstract> SearchComputerID(const int& search);
    vector<computersabstract> SearchComputer(const QString& search);

    //        EDIT FUNCTIONS        //
    bool UpdateCS(const QString& tempfirst, const QString& tempmid, const QString& templast, const QString& tempgender, const int& bday, const int& dday, const int& id);
    bool UpdateComputer(const QString &tempname, const int &year, const QString &type, const bool& built, const int &id);
};

#endif // SQLQUERYDATA_H
