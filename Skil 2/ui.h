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

class UI
{
    domain d;
    void linkTable(vector<ComputerScientist>& temp, vector<computersabstract>& tmp, vector<int> &rowid);
    void Tolower(string &temp);
    void SortScientistSwitches(const QString& tmp);
    void SortComputerSwitches(const QString& tmp);
    bool CheckValidtyOfString(string& tmp);
    bool CheckValidtyOfStringPunct(string& tmp);
    bool CheckValidtyOfStringWithASingleSpace(string& tmp);
    bool ValidNumber(string &temp);
    bool ValidCSId(vector<ComputerScientist>& tmp, const int& id);
    bool ValidComputerId(vector<computersabstract>& tmp, const int& id);
    void scientistTable(vector<ComputerScientist>& tmp);
    void computerTable(vector<computersabstract>& tmp);
    vector<ComputerScientist> createCSLink();
    vector<computersabstract> createComputerLink();
public:
    UI();
    void InitialMenu();
    void MainMenu();
    void SortScientistMenu();
    void SortComputerMenu();
    void DeleteMenu();
    void LinkMenu();
    void AddComputerScientist();
    void AddComputer();
    void SearchMenu();
    void EditCS();

};

#endif // SCIENTISTUI_H
