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
public:
    UI();
    void InitialMenu();
    void MainMenu();
    void scientistTable(vector<ComputerScientist>& tmp);
    void computerTable(vector<computersabstract>& tmp);
};

#endif // SCIENTISTUI_H
