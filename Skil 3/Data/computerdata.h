#ifndef COMPUTERDATA_H
#define COMPUTERDATA_H
#include <QSqlQuery>
#include <QString>
#include <QVariant>
#include <QSqlError>
#include <vector>
#include "sqlconnect.h"
#include <string>
#include "The_Children/computerscientist.h"
#include "The_Children/computer.h"

using namespace std;


class ComputerData
{
    //        HELP FUNCTIONS        //
    void FillcomputerVector(QSqlQuery& query, vector<Computer> &temp);
public:
    ComputerData();

     //        ADDING FUNCTIONS        //
     bool AddComputer(Computer& input);

     //        SORTING FUNCTIONS        //
     vector<Computer> GetComputers(const QString &str, bool desc);

     //        DELETING FUNCTIONS        //
     vector<Computer> GetDeletedComputers();

     /*        LINKING FUNCTIONS
     /    Sorry that I used two functions instead of one
     /    this ;_; was easier to pass into the table that was already made
     */
     vector<Computer> GetComputerInnerJoin();

     //        SEARCH FUNCTIONS        //
     vector<Computer> SearchComputerID(const int& search);
     vector<Computer> SearchComputer(const QString& search);

     //        EDIT FUNCTIONS        //
     bool UpdateComputer(const QString &tempname, const int &year, const QString &type, const bool &built, const int &id);
};

#endif // COMPUTERDATA_H
