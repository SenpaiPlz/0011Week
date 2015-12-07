#ifndef SCIENTISTUI_H
#define SCIENTISTUI_H
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QString>
#include <vector>
#include "sqlconnect.h"
#include <string>
#include "computerscientist.h"
#include "computersabstract.h"
#include <iomanip>

class UI
{
public:
    UI();
    void scientistTable(vector<ComputerScientist>& tmp);
    void computerTable(vector<computersabstract>& tmp);
};

#endif // SCIENTISTUI_H
