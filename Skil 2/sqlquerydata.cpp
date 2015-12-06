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

vector<ComputerScientist> SQLQueryData::GetComputerScientist(const QString& str,bool desc)
{
    //Create objects
    SQLConnect database;
    vector<ComputerScientist> returnvec;
    ComputerScientist temp;

    //Connect to database and get query
    database.ConnectToDB();
    QSqlQuery query = database.GetQuery();

    //-----      WARNIG! THE CODE BELOW IS INJECTABLE!   ----//
    //___________HARDCORE THE INPUT FOR THIS FUNCTION________//

    /*
     * Only way to have a variable column is to either hardcode it
     * or take it in as a argument. If the second option is chosen,
     * then do keep in mind that people could attempt to inject SQL commands.
     */

    //Prepare and execute sql statement
    if(desc == true)
    {
        query.prepare(QString("SELECT * FROM scientists ORDER BY %1 DESC").arg(str));
    }
    else
    {
        query.prepare(QString("SELECT * FROM scientists ORDER BY %1").arg(str));
    }
    query.exec();
    FillcsVector(query,returnvec);

    //Close the database and make sure that the vector has only values nothing empty.
    database.Disconnect();
    query.clear();

    //return vector
    return returnvec;
}

vector<computersabstract> SQLQueryData::GetComputers(const QString& str, bool desc)
{
    //Create objects
    vector<computersabstract> returnvec;
    SQLConnect database;
    computersabstract temp;

    //Connect to database and get query
    database.ConnectToDB();
    QSqlQuery query = database.GetQuery();

    //-----      WARNIG! THE CODE BELOW IS INJECTABLE!   ----//
    //___________HARDCORE THE INPUT FOR THIS FUNCTION________//

    //Prepare and execute sql statement
    if(desc == true)
    {
        query.prepare(QString("SELECT * FROM computers ORDER BY %1 DESC").arg(str));
    }
    else
    {
        query.prepare(QString("SELECT * FROM computers ORDER BY %1").arg(str));
    }
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

bool SQLQueryData::AddComputerScientist(ComputerScientist& input)
{
    SQLConnect database;
    database.ConnectToDB();
    QSqlQuery query = database.GetQuery();

    query.prepare("INSERT INTO scientists (first_name, middle_name, last_name, gender, birth_year, death_year, deleted) VALUES (?, ?, ?, ?, ?, ?, 0)");
    query.bindValue(0,QString::fromStdString(input.getFirst()));
    if(input.getMid() != "")
    {
        query.bindValue(1, QString::fromStdString(input.getMid()));
    }
    else
    {
        query.bindValue(1,"NULL");
    }
    query.bindValue(2,QString::fromStdString(input.getLast()));
    query.bindValue(3,QString::fromStdString(input.getGender()));
    query.bindValue(4,input.getBday());
    if(input.getDday() != 0)
    {
        query.bindValue(5,input.getDday());
    }
    else
    {
        query.bindValue(5,"");
    }

    if(query.exec())
    {
        return true;
    }
    return false;
}

bool SQLQueryData::AddComputer(computersabstract& input)
{
    SQLConnect database;
    database.ConnectToDB();
    QSqlQuery query = database.GetQuery();

    query.prepare("INSERT INTO computers (name, year, type, built, deleted) VALUES (?, ?, ?, ?, 0)");
    query.bindValue(0,QString::fromStdString(input.getName()));
    query.bindValue(1,input.getYear());
    query.bindValue(2,QString::fromStdString(input.getType()));
    query.bindValue(3,input.getBuilt());

    if(query.exec())
    {
        return true;
    }
    return false;
}

bool SQLQueryData::MarkDeleted(const QString& tab, const int& id)
{
    SQLConnect database;
    database.ConnectToDB();
    QSqlQuery query = database.GetQuery();

    //-----      WARNIG! THE CODE BELOW IS INJECTABLE!   ----//
    //___________HARDCORE THE INPUT FOR THIS FUNCTION________//

    query.prepare(QString("UPDATE %1 SET deleted = 1 WHERE id = ?").arg(tab));
    query.bindValue(0,id);

    if(query.exec())
    {
        return true;
    }
    return false;
}

bool SQLQueryData::UnmarkDeleted(const QString& tab, const int& id)
{
    SQLConnect database;
    database.ConnectToDB();
    QSqlQuery query = database.GetQuery();

    //-----      WARNIG! THE CODE BELOW IS INJECTABLE!   ----//
    //___________HARDCORE THE INPUT FOR THIS FUNCTION________//

    query.prepare(QString("UPDATE %1 SET deleted = 0 WHERE id = ?").arg(tab));
    query.bindValue(0,id);

    if(query.exec())
    {
        return true;
    }
    return false;
}
