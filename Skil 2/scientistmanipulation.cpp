#include "scientistmanipulation.h"

ScientistManipulation::ScientistManipulation()
{

}

vector<ComputerScientist> ScientistManipulation::sortScientists(QString& str, char& choice)
{
    //Create objects
    SQLConnect database;
    vector<ComputerScientist> returnvec;

    //Connect to database and get query
    database.ConnectToDB();
    QSqlQuery query = database.GetQuery();

    switch(choice)
    {
        case 1:
            query.prepare(QString("SELECT * FROM scientists ORDER BY first_name, last_name").arg(str));
            break;
        case 2:
            query.prepare(QString("SELECT * FROM scientists ORDER BY middle_name, first_name").arg(str));
            break;
        case 3:
            query.prepare(QString("SELECT * FROM scientists ORDER BY last_name, first_name").arg(str));
            break;
        case 4:
            query.prepare(QString("SELECT * FROM scientists ORDER BY gender, first_name").arg(str));
            break;
        case 5:
            query.prepare(QString("SELECT * FROM scientists ORDER BY birth_year, first_name").arg(str));
            break;
        case 6:
            query.prepare(QString("SELECT * FROM scientists ORDER BY deleted, first_name").arg(str));
            break;

    }
    query.exec();
    FillcsVector(query,returnvec);

    //Close the database and make sure that the vector has only values nothing empty.
    database.Disconnect();
    query.clear();

    //return vector
    return returnvec;

}

void ScientistManipulation::FillcsVector(QSqlQuery& query, vector<ComputerScientist> &temp)
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

