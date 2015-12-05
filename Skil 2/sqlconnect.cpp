#include "sqlconnect.h"

const QString dbname = "DataBank.sqlite3";

SQLConnect::SQLConnect()
{

}

void SQLConnect::ConnectToDB()
{
    db = QSqlDatabase::database();
}

void SQLConnect::Connect()
{
    bool sqlite3found = QFile::exists(dbname);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbname);
    if(db.open() && db.isOpen())
    {
        if(sqlite3found)
        {
            cout << "Connection established!\n";
        }
        else
        {
            cout << "Reading from sql file!\n";
            TranslateSQLFile();
        }
    }
    else
    {
        throw runtime_error("Dabase failed to open."
                            "Error detail:" + db.lastError().text().toStdString());
    }

}

SQLConnect::~SQLConnect()
{

}

void SQLConnect::Disconnect()
{
    db.close();
}

void SQLConnect::TranslateSQLFile()
{
    /*
     * A function that reads a sql file and automatically carries out the commands in the file.
     * We use this to populate a sqlite3 file if it does not already exist in our working folder.
     * Very good for testing.
     * Credit:
     * https://stackoverflow.com/questions/3736984/multiple-sql-statements-in-qsqlquery-using-the-sqlite3-driver
     */
    if (!db.isOpen()) return;
    QSqlQuery query(db);
    QFile scriptFile("data.sql");
    if (scriptFile.open(QIODevice::ReadOnly))
    {
        QStringList scriptQueries = QTextStream(&scriptFile).readAll().split(';');

        foreach (QString queryTxt, scriptQueries)
        {
            if (queryTxt.trimmed().isEmpty()) {
                continue;
            }
            if (!query.exec(queryTxt))
            {
                throw runtime_error("One of the setup queries failed to execute."
                                    "Error detail:" + query.lastError().text().toStdString());
            }
            query.finish();
        }
    }
}

QSqlQuery SQLConnect::GetQuery()
{
    if(!db.isOpen())
    {
        db.open();
    }
    QSqlQuery query(db);
    return query;
}

QString SQLConnect::GetConnectionName()
{
    return db.connectionName();
}
