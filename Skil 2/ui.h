#ifndef SCIENTISTUI_H
#define SCIENTISTUI_H
#include <QString>
#include <vector>
#include <string>
#include "computerscientist.h"
#include "computersabstract.h"
#include <iomanip>
#include "domain.h"
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include "sqlquerydata.h"

class UI
{
    void Tolower(string &temp);
    void SortScientistSwitches(const QString& tmp);
    void SortComputerSwitches(const QString& tmp);
    bool CheckValidtyOfString(string& tmp);
public:
    UI();
    void InitialMenu();
    void MainMenu();
    void SortScientistMenu();
    void SortComputerMenu();
    void AddComputerScientist();
    void scientistTable(vector<ComputerScientist>& tmp);
    void computerTable(vector<computersabstract>& tmp);
};

#endif // SCIENTISTUI_H
