#ifndef UI_H
#define UI_H
#include "datamanipulation.h"
#include "databank.h"
#include "computerscientist.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include <cctype>

class UI
{
    void addUI();
    void deleteUI();
    void Print(vector<ComputerScientist> css);
    void displayUI();
    void searchUI();
    DataBank Mainframe;
public:
    UI();
    void clrscr();
    void InitializeUI();
    void MainMenu();
};

#endif // UI_H
