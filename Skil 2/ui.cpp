#include "ui.h"

UI::UI()
{
    cout << "\t######## PARSING SQL FILE AND CONNECTING TO DATABASE ########\n\n";
    domain d;
    d.connect();
    InitialMenu();
}

void UI::scientistTable(vector<ComputerScientist>& tmp)
{
    //Header for table
    cout << left << "| " << setw(3) << "ID" << "| "
             << setw(13) << "First Name" << "| " << setw(12)
             << "Middle N." << "| " << setw(14) << "Last Name" << "| "
             << setw(7) << "Gender" << "| " << setw(6) << "Birth" << "| "
             << setw(6) << "Death" <<  "|"
             << endl;
        cout << "----------------------------------------------------------------------------" << endl;
    //Input into table
    for(size_t i = 0; i < tmp.size(); i++)
    {
        cout << left << "| " << setw(3) << tmp[i].getID() << "| " << setw(13)
             << tmp[i].getFirst() << "| " << setw(12) << tmp[i].getMid()
             << "| " << setw(14) << tmp[i].getLast() << "| " << setw(7)
             << tmp[i].getGender() << "| " << setw(6) << tmp[i].getBday()
             << "| " << setw(6) << tmp[i].getDday() << "|" << endl;
    }
}

void UI::computerTable(vector<computersabstract>& tmp)
{
    //Header for table
    cout << left << "| " << setw(3) << "ID" << "| "
                 << setw(18) << "Name" << "| " << setw(5)
                 << "Year" << "| " << setw(11) << "Type" << "| "
                 << setw(7) << "Built?" << "|"
                 << endl;
        cout << "------------------------------------------------------------" << endl;
    //Input into table
    for(size_t i = 0; i < tmp.size(); i++)
    {
        cout << left << "| " << setw(3) << tmp[i].getID() << "| " << setw(18)
             << tmp[i].getName() << "| " << setw(5) << tmp[i].getYear()
             << "| " << setw(11) << tmp[i].getType() << "| " << setw(7)
             << tmp[i].getBuilt() << "|" << endl;
    }
}

void UI::InitialMenu()
{
    cout << "\t  Y88b   d88P       888b     d888        d8888  .d8888b.  \n";
    cout << "\t    Y88b d88P        8888b   d8888       d88888 d88P  Y88b \n";
    cout << "\t     Y88o88P         88888b.d88888      d88P888 Y88b.      \n";
    cout << "\t      Y888P   888888 888Y88888P888     d88P 888  \"Y888b.   \n";
    cout << "\t      d888b   888888 888 Y888P 888    d88P  888     \"Y88b. \n";
    cout << "\t     d88888b         888  Y8P  888   d88P   888       \"888 \n";
    cout << "\t    d88P Y88b        888   \"   888  d8888888888 Y88b  d88P \n";
    cout << "\t   d88P   Y88b       888       888 d88P     888  \"Y8888P\n";
    cout << "\t    ~~The super cool Scientist&Computer SQL Program~~\n\n\n";
}
