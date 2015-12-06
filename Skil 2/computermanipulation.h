#ifndef COMPUTERMANIPULATION_H
#define COMPUTERMANIPULATION_H
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QString>
#include <vector>
#include "sqlconnect.h"
#include <string>
#include "computerscientist.h"
#include "computersabstract.h"


class ComputerManipulation
{
    void FillcsVector(QSqlQuery& query, vector<computersabstract> &temp);
public:
    ComputerManipulation();
    vector<computersabstract> sortComputers(QString& str, char& choice);
};

#endif // COMPUTERMANIPULATION_H
