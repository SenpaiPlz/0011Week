#ifndef SCIENTISTUI_H
#define SCIENTISTUI_H
#include <QString>
#include <vector>
#include <string>
#include "computerscientist.h"
#include "computer.h"
#include "helper.h"
#include <iomanip>
#include "scientistdomain.h"
#include "computerdomain.h"
#include <cstdlib>
#include <cctype>

class UI
{
    //helper + domain class
    ScientistDomain d;
    ComputerDomain c;
    helper h;

    //tables
    void linkTable(vector<ComputerScientist>& temp, vector<Computer>& tmp, vector<int> &rowid);
    void scientistTable(vector<ComputerScientist>& tmp);
    void computerTable(vector<Computer>& tmp);

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
