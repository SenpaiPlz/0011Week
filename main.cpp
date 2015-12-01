<<<<<<< HEAD
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
=======
#include <QCoreApplication>
#include <iostream>
#include "computerscientist.h"
#include "databank.h"
#include "datamanipulation.h"

void logo();

int main()//(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);

    logo();

    //a.exec();
    return 0;
}

void logo()
{
    cout << " ________________________________________________\n"
             << "|                                                |\n"
             << "|\t _____ _____                 ______\t |\n"
             << "|\t|  __ |  __ \\               |___  /\t |\n"
             << "|\t| |  \\| |  \\/  ______    ___   / / \t |\n"
             << "|\t| | __| | __  |______|  / _ \\ / /  \t |\n"
             << "|\t| |_\\ | |_\\ \\          |  __./ /___\t |\n"
             << "|\t \\____/\\____/           \\___\\_____/\t |\n"
             << "|                                                |\n"
             << "|________________________________________________|\n";
}
>>>>>>> a520be2812127db3e523ebd08e679ef8c7e1a0de
