#include "ui.h"

UI::UI()
{
    cout << "############ PARSING SQL FILE AND CONNECTING TO DATABASE ############\n\n";
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
    cout << "\t   Y88b d88P        8888b   d8888       d88888 d88P  Y88b \n";
    cout << "\t    Y88o88P         88888b.d88888      d88P888 Y88b.      \n";
    cout << "\t     Y888P   888888 888Y88888P888     d88P 888  \"Y888b.   \n";
    cout << "\t     d888b   888888 888 Y888P 888    d88P  888     \"Y88b. \n";
    cout << "\t    d88888b         888  Y8P  888   d88P   888       \"888 \n";
    cout << "\t   d88P Y88b        888   \"   888  d8888888888 Y88b  d88P \n";
    cout << "\t  d88P   Y88b       888       888 d88P     888  \"Y8888P\n\n";
    cout << "\t    ~~The super cool Scientist&Computer SQL Program~~\n\n\n";
    MainMenu();
}

void UI::MainMenu()
{
    cout << "\n#######-----------        MAIN MENU        -----------#######\n";
    cout << "1.\t\tView Computerscientists\n";
    cout << "2.\t\tView Computers\n";
    cout << "3.\t\tI dont know what I am supposed to write here\n";
    cout << "0.\t\tPress 0 to QUIT this program\n\n";
    cout << "choice: ";
    while(true)
    {
        char choice;
        cin >> choice;
        switch(choice)
        {
        case '1': {SortScientistMenu(); break;}
        case '2': break;
        case '0': {exit(0); break;}
        default: break;
        }
    }
}

void UI::SortScientistMenu()
{
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    vector<ComputerScientist> temp;
    cout << "\n#######-----------      Sort Scientist     -----------#######\n";
    cout << "1.\t\tSort by First Name\n";
    cout << "2.\t\tSort by Middle Name\n";
    cout << "3.\t\tSort by Last Name\n";
    cout << "4.\t\tSort by Birth Year\n";
    cout << "5.\t\tSort by Death Year\n";
    cout << "0.\t\tMAIN MENU\n\n";
    cout << "choice: ";
    while(true)
    {
        char choice = cin.get();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        switch(choice)
        {
        case '1':
        {
            SortScientistSwitches("first_name");
            break;
        }
        case '2':
        {
            SortScientistSwitches("middle_name");
            break;
        }
        case '3':
        {
            SortScientistSwitches("last_name");
            break;
        }
        case '4':
        {
            SortScientistSwitches("birth_year");
            break;
        }
        case '5':
        {
            SortScientistSwitches("death_year");
            break;
        }
        case '0': {MainMenu(); break;}
        default: {cout << "Invalid choice\n"; break;}
        }
    }
}

void UI::SortScientistSwitches(const QString& tmp)
{
    domain sort;
    string test;
    vector<ComputerScientist> temp;
    cout << "Do you wish to sort in Descending order? y/n: ";
    char in = std::cin.get();
    in = tolower(in);
    if(in != 'y' && in != 'n')
    {
        cout << "Invalid input\n";
        SortScientistMenu();
    }
    else if(in == 'y')
    {
        temp = sort.GetComputerScientist(tmp,1);
        scientistTable(temp);
        cout << "Press enter to continue.";
        getline(cin,test);
        SortScientistMenu();
    }
    else
    {
        temp = sort.GetComputerScientist(tmp,0);
        scientistTable(temp);
        cout << "Press enter to continue.";
        getline(cin,test);
        SortScientistMenu();
    }
}
