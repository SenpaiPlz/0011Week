#include "computerdata.h"

ComputerData::ComputerData()
{
}

//--------    SORTING FUNCTIONS    --------//

vector<Computer> ComputerData::GetComputers(const QString& str, bool desc)
{
    //Create objects
    vector<Computer> returnvec;
    SQLConnect database;
    Computer temp;

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



//--------    Helper Functions    --------//

void ComputerData::FillcomputerVector(QSqlQuery& query, vector<Computer> &temp)
{
    //Loop through and fill vector with ComputerScientists.
    while(query.next())
    {
        Computer tmp;

        tmp.setID(query.value("id").toInt());
        tmp.setName(query.value("name").toString().toStdString());
        tmp.setYear((query.value("year").toInt()));
        tmp.setType((query.value("type").toString().toStdString()));
        tmp.setBuilt((query.value("built").toBool()));

        temp.push_back(tmp);

    }
    temp.shrink_to_fit();
}



//--------    Adding functions    --------//

bool ComputerData::AddComputer(Computer& input)
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



//--------    Deletion functions    --------//

vector<Computer> ComputerData::GetDeletedComputers()
{
    SQLConnect database;
    vector<Computer> returnvec;
    database.ConnectToDB();
    QSqlQuery query = database.GetQuery();

    query.prepare("SELECT * FROM computers WHERE deleted = 1 ORDER BY id");
    query.exec();

    FillcomputerVector(query,returnvec);
    database.Disconnect();
    query.clear();

    return returnvec;
}


//--------    Linking functions    --------//

vector<Computer> ComputerData::GetComputerInnerJoin()
{
    SQLConnect database;
    vector<Computer> comp;
    database.ConnectToDB();
    QSqlQuery query = database.GetQuery();

    query.prepare("SELECT * FROM computers INNER JOIN computers_scientists ON computers.id = computers_scientists.computers_id");
    query.exec();

    FillcomputerVector(query,comp);

    database.Disconnect();
    query.clear();

    return comp;
}


//--------    Searching functions    --------//

vector<Computer> ComputerData::SearchComputerID(const int& search)
{
    SQLConnect database;
    database.ConnectToDB();
    QSqlQuery query = database.GetQuery();
    vector<Computer> returnvec;

    query.prepare("SELECT * FROM computers WHERE id LIKE '%'||?||'%'");
    query.bindValue(0,search);
    query.exec();

    FillcomputerVector(query,returnvec);

    database.Disconnect();
    query.clear();

    return returnvec;
}

vector<Computer> ComputerData::SearchComputer(const QString& search)
{
    SQLConnect database;
    database.ConnectToDB();
    QSqlQuery query = database.GetQuery();
    vector<Computer> returnvec;

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


//--------    Editing functions    --------//

bool ComputerData::UpdateComputer(const QString& tempname,const int& year, const QString& type,const bool& built , const int& id)
{
    SQLConnect database;
    database.ConnectToDB();
    QSqlQuery query = database.GetQuery();

    query.prepare("UPDATE computers SET name =?, year=?, type=?, built=? WHERE id=?");
    query.bindValue(0,tempname);
    query.bindValue(1,year);
    query.bindValue(2,type);
    query.bindValue(3,built);
    query.bindValue(4,id);

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

