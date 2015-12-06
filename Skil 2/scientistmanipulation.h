#ifndef SCIENTISTMANIPULATION_H
#define SCIENTISTMANIPULATION_H
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QString>
#include <vector>
#include "sqlconnect.h"
#include <string>
#include "computerscientist.h"
#include "computersabstract.h"

using namespace std;


class ScientistManipulation
{
    void FillcsVector(QSqlQuery& query, vector<ComputerScientist>& temp);
public:
    ScientistManipulation();
    vector<ComputerScientist> sortScientists(QString& str, char& choice);
};

#endif // SCIENTISTMANIPULATION_H
