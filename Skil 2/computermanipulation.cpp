#include "computermanipulation.h"

ComputerManipulation::ComputerManipulation()
{

}

vector<computersabstract> ComputerManipulation::sortComputers(char& choice)
{
    //Create objects
    SQLConnect database;
    vector<computersabstract> returnvec;

    //Connect to database and get query
    database.ConnectToDB();
    QSqlQuery query = database.GetQuery();

    switch(choice)
    {
        case 1:
            query.exec("SELECT * FROM scientists ORDER BY name, year");
            break;
        case 2:
            query.exec("SELECT * FROM scientists ORDER BY year, name");
            break;
        case 3:
            query.exec("SELECT * FROM scientists ORDER BY type, name");
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

void ComputerManipulation::FillcsVector(QSqlQuery& query, vector<computersabstract> &temp)
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


