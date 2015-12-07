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
#include "domain.h"

class UI
{
public:
    UI();
    void InitialMenu();
    void MainMenu();
    void scientistTable(vector<ComputerScientist>& tmp);
    void computerTable(vector<computersabstract>& tmp);
};

#endif // SCIENTISTUI_H
