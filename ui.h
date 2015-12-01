#ifndef UI_H
#define UI_H
#include "datamanipulation.h"
#include "databank.h"
#include "computerscientist.h"
#include <iostream>
#include <string>

class UI
{
    void addUI();
    void deleteUI();
    void deletePrint(vector<ComputerScientist> css);
    void displayUI();
    DataBank Mainframe;
public:
    UI();
    void clrscr();
    void InitializeUI();
    void MainMenu();
};

#endif // UI_H
