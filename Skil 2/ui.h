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
public:
    UI();
    void InitialMenu();
    void MainMenu();
    void SortScientistMenu();
    void scientistTable(vector<ComputerScientist>& tmp);
    void computerTable(vector<computersabstract>& tmp);
};

#endif // SCIENTISTUI_H
