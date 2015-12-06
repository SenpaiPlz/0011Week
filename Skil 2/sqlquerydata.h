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
    void FillcomputerVector(QSqlQuery& query, vector<computersabstract> &temp);
    void FillcsVector(QSqlQuery& query, vector<ComputerScientist>& temp);
public:
    SQLQueryData();
    void InitConnect();
    bool AddComputerScientist(ComputerScientist& input);
    vector<computersabstract> GetComputers(const QString &str, bool desc);
    vector<ComputerScientist> GetComputerScientist(const QString &str, bool desc);
};

#endif // SQLQUERYDATA_H
