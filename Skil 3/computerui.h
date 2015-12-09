/*#ifndef COMPUTERUI_H
#define COMPUTERUI_H
#include <QString>
#include <vector>
#include <string>
#include "Computer.h"
#include "helper.h"
#include <iomanip>
#include "computerdomain.h"
#include <cstdlib>
#include <cctype>

class ComputerUI
{
    //helper + domain class
    ComputerDomain c;
    helper h;

    //tables
    void computerTable(vector<Computer>& tmp);

    //switch cases for sort
    void SortComputerSwitches(const QString& tmp);

    //All UI menus
    void SortComputerMenu();
    void AddComputer();
    void EditComputer();
public:
    ComputerUI();
};

#endif // COMPUTERUI_H
*/
