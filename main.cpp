#include <iostream>
#include "ui.h"

using namespace std;

int main()
{
    UI main;
    main.InitializeUI();
    char cont;
    bool Continue = false;
    do
    {
        Continue = false;
        main.MainMenu();
        cout << "Press y/Y to continue, anything else will exit.\n"
             << "Do you wish to Continue? ";
        cin >> cont;
        if(cont == 'Y' || cont == 'y')
        {
            main.clrscr();
            Continue = true;
        }
    }while(Continue == true);
    return 0;
}
