#ifndef SCIENTISTDATA_H
#define SCIENTISTDATA_H
#include <QSqlQuery>
#include <QString>
#include <QVariant>
#include <QSqlError>
#include <vector>
#include <string>
#include "sqlconnect.h"
#include "The_Children/computerscientist.h"
#include "The_Children/computer.h"

using namespace std;

class ScientistData
{
    //        HELP FUNCTION        //
    void FillcsVector(QSqlQuery& query, vector<ComputerScientist>& temp);
public:
    ScientistData();
    void InitConnect();

    //        ADDING FUNCTIONS        //
    bool AddComputerScientist(ComputerScientist& input);

    //        SORTING FUNCTIONS        //
    vector<ComputerScientist> GetComputerScientist(const QString &str, bool desc);

    //        DELETING FUNCTIONS        //
    bool MarkDeleted(const QString &tab, const int& id);
    bool UnmarkDeleted(const QString& tab, const int& id);
    bool DeleteAllMarked();
    vector<ComputerScientist> GetDeletedCS();

    /*        LINKING FUNCTIONS
    /    Sorry that I used two functions instead of one
    /    this ;_; was easier to pass into the table that was already made
    */
    vector<ComputerScientist> GetCSInnerJoin();
    vector<int> GetRowID();
    bool DeleteLink(const int& rowid);
    bool AddLink(const int& scientists_id, const int& computers_id);

    //        SEARCH FUNCTIONS        //
    vector<ComputerScientist> SearchCS(const QString& search);
    vector<ComputerScientist> SearchCSID(const int& search);

    //        EDIT FUNCTIONS        //
    bool UpdateCS(const QString& tempfirst, const QString& tempmid, const QString& templast, const QString& tempgender, const int& bday, const int& dday, const int& id);
};

#endif // SCIENTISTDATA_H
