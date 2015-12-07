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
    if(str == "first_name")
    {
        if(desc == true)
        {
            query.prepare(QString("SELECT * FROM scientists WHERE deleted = 0 ORDER BY %1 DESC, last_name DESC").arg(str));
        }
        else
        {
            query.prepare(QString("SELECT * FROM scientists WHERE deleted = 0 ORDER BY %1, last_name").arg(str));
        }
    }
    else
    {
        if(desc == true)
        {
            query.prepare(QString("SELECT * FROM scientists WHERE deleted = 0 ORDER BY %1 DESC, first_name DESC").arg(str));
        }
        else
        {
            query.prepare(QString("SELECT * FROM scientists WHERE deleted = 0 ORDER BY %1, first_name").arg(str));
        }
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
    if(str == "name")
    {
        if(desc == true)
        {
            query.prepare(QString("SELECT * FROM computers WHERE deleted = 0 ORDER BY %1 DESC, year DESC").arg(str));
        }
        else
        {
            query.prepare(QString("SELECT * FROM computers WHERE deleted = 0 ORDER BY %1, year").arg(str));
        }
    }
    else
    {
        if(desc == true)
        {
            query.prepare(QString("SELECT * FROM computers WHERE deleted = 0 ORDER BY %1 DESC, name DESC").arg(str));
        }
        else
        {
            query.prepare(QString("SELECT * FROM computers WHERE deleted = 0 ORDER BY %1, name").arg(str));
        }
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

        tmp.setID(query.value("id").toInt());
        tmp.setFirst(query.value("first_name").toString().toStdString());
        tmp.setMid((query.value("middle_name").toString().toStdString()));
        tmp.setLast(query.value("last_name").toString().toStdString());
        tmp.setgender((query.value("gender").toString().toStdString()));
        tmp.setbday((query.value("birth_year").toInt()));
        tmp.setdday((query.value("death_year").toInt()));

        temp.push_back(tmp);
    }
    temp.shrink_to_fit();
}

void SQLQueryData::FillcomputerVector(QSqlQuery& query, vector<computersabstract> &temp)
{
    //Loop through and fill vector with ComputerScientists.
    while(query.next())
    {
        computersabstract tmp;

        tmp.setID(query.value("id").toInt());
        tmp.setName(query.value("name").toString().toStdString());
        tmp.setYear((query.value("year").toInt()));
        tmp.setType((query.value("type").toString().toStdString()));
        tmp.setBuilt((query.value("built").toBool()));

        temp.push_back(tmp);

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
        query.bindValue(1,QString());
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
        database.Disconnect();
        query.clear();
        return true;
    }
    database.Disconnect();
    query.clear();
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
        query.clear();
        database.Disconnect();
        return true;
    }
    query.clear();
    database.Disconnect();
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
        query.clear();
        database.Disconnect();
        return true;
    }
    query.clear();
    database.Disconnect();
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
        database.Disconnect();
        query.clear();
        return true;
    }
    database.Disconnect();
    query.clear();
    return false;
}

bool SQLQueryData::DeleteAllMarked()
{
    SQLConnect database;
    database.ConnectToDB();
    QSqlQuery query = database.GetQuery();
    bool css = false;

    query.prepare("DELETE FROM scientists WHERE deleted = 1");
    if(query.exec())
    {
        css = true;
        query.clear();
    }
    query.prepare("DELETE FROM computers WHERE deleted = 1");
    if(css && query.exec())
    {
        database.Disconnect();
        query.clear();
        return true;
    }
    database.Disconnect();
    query.clear();
    return false;
}

vector<ComputerScientist> SQLQueryData::GetDeletedCS()
{
    SQLConnect database;
    vector<ComputerScientist> returnvec;
    database.ConnectToDB();
    QSqlQuery query = database.GetQuery();

    query.prepare("SELECT * FROM scientists WHERE deleted = 1 ORDER BY first_name");
    query.exec();

    FillcsVector(query,returnvec);
    database.Disconnect();
    query.clear();

    return returnvec;
}

vector<computersabstract> SQLQueryData::GetDeletedComputers()
{
    SQLConnect database;
    vector<computersabstract> returnvec;
    database.ConnectToDB();
    QSqlQuery query = database.GetQuery();

    query.prepare("SELECT * FROM computers WHERE deleted = 1 ORDER BY name");
    query.exec();

    FillcomputerVector(query,returnvec);
    database.Disconnect();
    query.clear();

    return returnvec;
}

vector<int> SQLQueryData::GetLinkID()
{
    //---Returns a vector where i = scientists_id and i+1 = computers_id ordered by rowid---//

    SQLConnect database;
    vector<int> returnvec;
    database.ConnectToDB();
    QSqlQuery query = database.GetQuery();

    query.prepare("SELECT * FROM computers_scientists ORDER BY rowid");
    query.exec();

    while(query.next())
    {
        auto temp = query.value("scientists_id").toInt();
        returnvec.push_back(temp);
        temp = query.value("computers_id").toInt();
        returnvec.push_back(temp);
    }
    returnvec.shrink_to_fit();

    database.Disconnect();
    query.clear();
    return returnvec;
}


bool SQLQueryData::DeleteLink(const int& rowid)
{
    SQLConnect database;
    database.ConnectToDB();
    QSqlQuery query = database.GetQuery();

    query.prepare("DELETE FROM computers_scientists WHERE rowid = ?");
    query.bindValue(0,rowid);
    if(query.exec())
    {
        database.Disconnect();
        query.clear();
        return true;
    }
    database.Disconnect();
    query.clear();
    return false;
}

bool SQLQueryData::AddLink(const int& scientists_id, const int& computers_id)
{
    SQLConnect database;
    database.ConnectToDB();
    QSqlQuery query = database.GetQuery();

    query.prepare("INSERT INTO computers_scientists VALUES (?, ?)");
    query.bindValue(0,scientists_id);
    query.bindValue(1,computers_id);
    if(query.exec())
    {
        database.Disconnect();
        query.clear();
        return true;
    }
    database.Disconnect();
    query.clear();
    return false;
}

vector<ComputerScientist> SQLQueryData::SearchCS(const QString& search)
{
    SQLConnect database;
    database.ConnectToDB();
    QSqlQuery query = database.GetQuery();
    vector<ComputerScientist> returnvec;

    query.prepare("SELECT * FROM scientists WHERE ((first_name LIKE '%'||?||'%') OR (middle_name LIKE '%'||?||'%') OR "
                  "(last_name LIKE '%'||?||'%') OR (birth_year LIKE '%'||?||'%') OR (death_year LIKE '%'||?||'%')) ORDER BY first_name");
    query.bindValue(0,search);
    query.bindValue(1,search);
    query.bindValue(2,search);
    query.bindValue(3,search);
    query.bindValue(4,search);
    query.exec();

    FillcsVector(query,returnvec);

    returnvec.shrink_to_fit();

    database.Disconnect();
    query.clear();

    return returnvec;
}

vector<ComputerScientist> SQLQueryData::SearchCSID(const int& search)
{
    SQLConnect database;
    database.ConnectToDB();
    QSqlQuery query = database.GetQuery();
    vector<ComputerScientist> returnvec;

    query.prepare("SELECT * FROM scientists WHERE id LIKE '%'||?||'%'");
    query.bindValue(0,search);
    query.exec();

    FillcsVector(query,returnvec);

    database.Disconnect();
    query.clear();

    return returnvec;
}


vector<computersabstract> SQLQueryData::SearchComputerID(const int& search)
{
    SQLConnect database;
    database.ConnectToDB();
    QSqlQuery query = database.GetQuery();
    vector<computersabstract> returnvec;

    query.prepare("SELECT * FROM computers WHERE id LIKE '%'||?||'%'");
    query.bindValue(0,search);
    query.exec();

    FillcomputerVector(query,returnvec);

    database.Disconnect();
    query.clear();

    return returnvec;
}

vector<computersabstract> SQLQueryData::SearchComputer(const QString& search)
{
    SQLConnect database;
    database.ConnectToDB();
    QSqlQuery query = database.GetQuery();
    vector<computersabstract> returnvec;

    query.prepare("SELECT * FROM computers WHERE ((name LIKE '%'||?||'%') OR (year LIKE '%'||?||'%') OR (type LIKE '%'||?||'%')) ORDER BY name");
    query.bindValue(0,search);
    query.bindValue(1,search);
    query.bindValue(2,search);
    query.exec();

    FillcomputerVector(query,returnvec);

    database.Disconnect();
    query.clear();

    return returnvec;
}

bool SQLQueryData::UpdateCS(const QString& tempfirst, const QString& tempmid, const QString& templast, const QString& tempgender, const int& bday, const int& dday, const int& id)
{

    SQLConnect database;
    database.ConnectToDB();
    QSqlQuery query = database.GetQuery();

    query.prepare("UPDATE scientists SET first_name = ?, middle_name = ?, last_name = ?, gender =?, birth_year =?, death_year=? WHERE id=?");
    query.bindValue(0,tempfirst);
    query.bindValue(1,tempmid);
    query.bindValue(2,templast);
    query.bindValue(3,tempgender);
    query.bindValue(4,bday);
    query.bindValue(5,dday);
    query.bindValue(6,id);

    if(query.exec())
    {
        database.Disconnect();
        query.clear();
        return true;
    }
    database.Disconnect();
    query.clear();
    return false;
}

bool SQLQueryData::UpdateComputer(const QString& tempname,const int& year, const QString& type, const int& id)
{
    SQLConnect database;
    database.ConnectToDB();
    QSqlQuery query = database.GetQuery();

    query.prepare("UPDATE computers SET name =?, year=?, type=? WHERE id=?");
    query.bindValue(0,tempname);
    query.bindValue(1,year);
    query.bindValue(2,type);
    query.bindValue(3,id);

    if(query.exec())
    {
        database.Disconnect();
        query.clear();
        return true;
    }
    database.Disconnect();
    query.clear();
    return false;
}
