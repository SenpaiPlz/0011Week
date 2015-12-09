#ifndef SCIENTISTUI_H
#define SCIENTISTUI_H
#include <QString>
#include <vector>
#include <string>
#include "computerscientist.h"
#include "computersabstract.h"
#include "helper.h"
#include <iomanip>
#include "domain.h"
#include <cstdlib>
#include <cctype>

class UI
{
    //helper + domain class
    domain d;
    helper h;

    //tables
    void linkTable(vector<ComputerScientist>& temp, vector<computersabstract>& tmp, vector<int> &rowid);
    void scientistTable(vector<ComputerScientist>& tmp);
    void computerTable(vector<computersabstract>& tmp);

    //switch cases for sort
    void SortScientistSwitches(const QString& tmp);
    void SortComputerSwitches(const QString& tmp);

    //All UI menus
    void InitialMenu();
    void MainMenu();
    void SortScientistMenu();
    void SortComputerMenu();
    void DeleteMenu();
    void LinkMenu();
    void AddComputerScientist();
    void AddComputer();
    void SearchMenu();
    void EditComputer();
    void EditCS();
public:
    UI();


};

#endif // SCIENTISTUI_H
