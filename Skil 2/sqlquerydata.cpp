#include "sqlquerydata.h"

using namespace std;

SQLQueryData::SQLQueryData()
{
}

void SQLQueryData::InitConnect()
{
    SQLConnect db;
    db.Connect();
}

vector<ComputerScientist> SQLQueryData::GetComputerScientist()
{
    //Create objects
    SQLConnect database;
    vector<ComputerScientist> returnvec;
    ComputerScientist temp;

    //Connect to database and get query
    database.ConnectToDB();
    QSqlQuery query = database.GetQuery();

    //Prepare and execute sql statement
    query.prepare("SELECT * FROM scientists ORDER BY first_name");
    query.exec();
    FillcsVector(query,returnvec);

    //Close the database and make sure that the vector has only values nothing empty.
    database.Disconnect();
    query.clear();

    //return vector
    return returnvec;
}

vector<computersabstract> SQLQueryData::GetComputers()
{
    //Create objects
    QString databasename;
    vector<computersabstract> returnvec;
    SQLConnect database;
    computersabstract temp;

    //Connect to database and get query
    database.ConnectToDB();
    QSqlQuery query = database.GetQuery();
    database.GetConnectionName();

    //Prepare and execute sql statement
    query.prepare("SELECT * FROM computers ORDER BY name");
    query.exec();

    FillcomputerVector(query,returnvec);
    //Close the database and make sure that the vector has only values nothing empty.
    database.Disconnect();
    query.clear();

    //return vector
    return returnvec;
}

void SQLQueryData::FillcsVector(QSqlQuery& query, vector<ComputerScientist> &temp)
{
    //Loop through and fill vector with ComputerScientists.
    while(query.next())
    {
        ComputerScientist tmp;
        if(!query.value("deleted").toBool())
        {
            tmp.setID(query.value("id").toInt());
            tmp.setFirst(query.value("first_name").toString().toStdString());
            tmp.setMid((query.value("middle_name").toString().toStdString()));
            tmp.setLast(query.value("last_name").toString().toStdString());
            tmp.setgender((query.value("gender").toString().toStdString()));
            tmp.setbday((query.value("birth_year").toInt()));
            tmp.setbday((query.value("birth_year").toInt()));
            tmp.setdday((query.value("death_year").toInt()));

            temp.push_back(tmp);
        }
    }
    temp.shrink_to_fit();
}

void SQLQueryData::FillcomputerVector(QSqlQuery& query, vector<computersabstract> &temp)
{
    //Loop through and fill vector with ComputerScientists.
    while(query.next())
    {
        computersabstract tmp;
        if(!query.value("deleted").toBool())
        {
            tmp.setID(query.value("id").toInt());
            tmp.setName(query.value("name").toString().toStdString());
            tmp.setYear((query.value("year").toInt()));
            tmp.setType((query.value("type").toString().toStdString()));
            tmp.setBuilt((query.value("built").toBool()));

            temp.push_back(tmp);
        }
    }
    temp.shrink_to_fit();
}
