#include "scientistdata.h"

ScientistData::ScientistData()
{
}

void ScientistData::InitConnect()
{
    SQLConnect db;
    db.Connect();
}

//--------    SORTING FUNCTIONS    --------//

vector<ComputerScientist> ScientistData::GetComputerScientist(const QString& str,bool desc)
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


//--------    Helper Functions    --------//

void ScientistData::FillcsVector(QSqlQuery& query, vector<ComputerScientist> &temp)
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


//--------    Adding functions    --------//

bool ScientistData::AddComputerScientist(ComputerScientist& input)
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



//--------    Deletion functions    --------//

bool ScientistData::MarkDeleted(const QString& tab, const int& id)
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

bool ScientistData::UnmarkDeleted(const QString& tab, const int& id)
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

bool ScientistData::DeleteAllMarked()
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

vector<ComputerScientist> ScientistData::GetDeletedCS()
{
    SQLConnect database;
    vector<ComputerScientist> returnvec;
    database.ConnectToDB();
    QSqlQuery query = database.GetQuery();

    query.prepare("SELECT * FROM scientists WHERE deleted = 1 ORDER BY id");
    query.exec();

    FillcsVector(query,returnvec);
    database.Disconnect();
    query.clear();

    return returnvec;
}

//--------    Linking functions    --------//

bool ScientistData::DeleteLink(const int& rowid)
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


vector<ComputerScientist> ScientistData::GetCSInnerJoin()
{
    SQLConnect database;
    vector<ComputerScientist> science;
    database.ConnectToDB();
    QSqlQuery query = database.GetQuery();

    query.prepare("SELECT * FROM scientists INNER JOIN computers_scientists ON scientists.id = computers_scientists.scientists_id");
    query.exec();

    FillcsVector(query,science);

    database.Disconnect();
    query.clear();

    return science;
}

vector<int> ScientistData::GetRowID()
{
    SQLConnect database;
    vector<int> temp;
    database.ConnectToDB();
    QSqlQuery query = database.GetQuery();

    query.prepare("SELECT rowid FROM computers_scientists");
    query.exec();

    while(query.next())
    {
        int i = query.value("rowid").toInt();
        temp.push_back(i);
    }
    temp.shrink_to_fit();

    database.Disconnect();
    query.clear();

    return temp;
}

bool ScientistData::AddLink(const int& scientists_id, const int& computers_id)
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


//--------    Searching functions    --------//

vector<ComputerScientist> ScientistData::SearchCS(const QString& search)
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

vector<ComputerScientist> ScientistData::SearchCSID(const int& search)
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



//--------    Editing functions    --------//

bool ScientistData::UpdateCS(const QString& tempfirst, const QString& tempmid, const QString& templast, const QString& tempgender, const int& bday, const int& dday, const int& id)
{

    SQLConnect database;
    database.ConnectToDB();
    QSqlQuery query = database.GetQuery();

    query.prepare("UPDATE scientists SET first_name = ?, middle_name = ?, last_name = ?, gender =?, birth_year =?, death_year=? WHERE id=?");
    query.bindValue(0,tempfirst);
    if(tempmid != "")
    {
        query.bindValue(1,tempmid);
    }
    else
    {
        query.bindValue(1,QString());
    }
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
