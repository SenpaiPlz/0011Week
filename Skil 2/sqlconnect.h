#ifndef SQLCONNECT_H
#define SQLCONNECT_H
#include <iostream>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFile>
#include <QVariant>
#include <QSqlError>
#include <QTextStream>
#include <QString>
using namespace std;

class SQLConnect
{
    QSqlDatabase db;
public:
    //QString GetConnectionName();
    QSqlQuery GetQuery();
    void ConnectToDB();
    void TranslateSQLFile();
    void Connect();
    void Disconnect();
    SQLConnect();
    ~SQLConnect();
};

#endif // SQLCONNECT_H
