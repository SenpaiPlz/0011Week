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

class UI
{
    void SortScientistSwitches(const QString& tmp);
    void SortComputerSwitches(const QString& tmp);
    domain Domain;
public:
    UI();
    void InitialMenu();
    void MainMenu();
    void SortScientistMenu();
    void SortComputerMenu();
    void scientistTable(vector<ComputerScientist>& tmp);
    void computerTable(vector<computersabstract>& tmp);
    void AddComputerScientist();
};

#endif // SCIENTISTUI_H
