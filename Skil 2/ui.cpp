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
             << tmp[i].getFirst() << "| " ;
        if(tmp[i].getMid() != "NULL")
        {
        cout << setw(12) << tmp[i].getMid();
        }
        else
        {
            cout << "            ";
        }
        cout << "| " << setw(14) << tmp[i].getLast() << "| " << setw(7)
             << tmp[i].getGender() << "| " << setw(6) << tmp[i].getBday()
             << "| ";
        if (tmp[i].getDday() != 0)
        {
            cout << setw(6) << tmp[i].getDday() << "|" << endl;;
        }
        else
        {
            cout<< setw(6) << "      |" << endl;
        }
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
             << "| " << setw(11) << tmp[i].getType() << "| ";
        if(tmp[i].getBuilt() == 1)
        {
             cout << setw(7) << "Yes" << "|" << endl;
        }
        else
        {
             cout << setw(7) << "No" << "|" << endl;
        }
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
    cout << "3.\t\tAdd Computerscientists\n";
    cout << "4.\t\tEdit Computerscientists\n";
    cout << "5.\t\tAdd Computers\n";
    cout << "6.\t\tEdit Computers\n";
    cout << "7.\t\tLink Menu\n";
    cout << "8.\t\tSearch Menu\n";
    cout << "9.\t\tDelete Menu\n";
    cout << "0.\t\tQUIT\n\n";
    cout << "choice: ";
    while(true)
    {
        char choice;
        cin >> choice;
        switch(choice)
        {
        case '1': {SortScientistMenu(); break;}
        case '2': {SortComputerMenu(); break;}
        case '3': {AddComputerScientist(); break;}
        case '4': {break;}
        case '5': {AddComputer(); break;}
        case '6': {break;}
        case '7': {break;}
        case '8': {break;}
        case '9': {break;}
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
        cout << "\n";
        scientistTable(temp);
        cout << "Press enter to continue.";
        getline(cin,test);
        SortScientistMenu();
    }
    else
    {
        temp = sort.GetComputerScientist(tmp,0);
        cout << "\n";
        scientistTable(temp);
        cout << "Press enter to continue.";
        getline(cin,test);
        SortScientistMenu();
    }
}

void UI::SortComputerMenu()
{
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    vector<ComputerScientist> temp;
    cout << "\n#######-----------      Sort Scientist     -----------#######\n";
    cout << "1.\t\tSort by Name\n";
    cout << "2.\t\tSort by Year\n";
    cout << "3.\t\tSort by Type\n";
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
            SortComputerSwitches("name");
            break;
        }
        case '2':
        {
            SortComputerSwitches("year");
            break;
        }
        case '3':
        {
            SortComputerSwitches("type");
            break;
        }
        case '0': {MainMenu(); break;}
        default: {cout << "Invalid choice\n"; break;}
        }
    }
}

void UI::SortComputerSwitches(const QString& tmp)
{
    domain sort;
    string test;
    vector<computersabstract> temp;
    cout << "Do you wish to sort in Descending order? y/n: ";
    char in = std::cin.get();
    in = tolower(in);
    if(in != 'y' && in != 'n')
    {
        cout << "Invalid input\n";
        SortComputerMenu();
    }
    else if(in == 'y')
    {
        temp = sort.GetComputers(tmp,1);
        cout << "\n";
        computerTable(temp);
        cout << "Press enter to continue.";
        getline(cin,test);
        SortComputerMenu();
    }
    else
    {
        temp = sort.GetComputers(tmp,0);
        cout << "\n";
        computerTable(temp);
        cout << "Press enter to continue.";
        getline(cin,test);
        SortComputerMenu();
    }
}

void UI::AddComputerScientist()
{
    ComputerScientist cs;
    string temp;
    int bdaytemp = -1, dday = -1;
    cout << "To enter a new scientist please fill in the fields with only a single string\n";

    //Checks input for every name to see if it's valid//
    do{
        cout << "Enter First Name: ";
        cin.sync();
        getline(cin,temp);
        if(!CheckValidtyOfString(temp))
        {
            cout << "Found an error in your string\n";
        }
    }while(!CheckValidtyOfString(temp));

    temp[0] = toupper(temp[0]);
    cs.setFirst(temp);
    temp = "";

    do{
        cout << "Enter Middle Name (Type NULL if it's empty): ";
        cin.sync();
        getline(cin,temp);
        if(!CheckValidtyOfString(temp))
        {
            cout << "Found an error in your string\n";
        }
    }while(!CheckValidtyOfString(temp));

    Tolower(temp);
    if(temp == "null")
    {
        temp = "NULL";
        temp.clear();
    }
    else
    {
        temp[0] = toupper(temp[0]);
    }
    cs.setMid(temp);
    temp = "";

    do{
        cout << "Enter Last Name: ";
        cin.sync();
        getline(cin,temp);
        if(!CheckValidtyOfString(temp))
        {
            cout << "Found an error in your string\n";
        }
    }while(!CheckValidtyOfString(temp));

    temp[0] = toupper(temp[0]);
    cs.setLast(temp);
    temp = "";

    do{
        cout << "Enter the Gender: ";
        cin.sync();
        getline(cin,temp);
        Tolower(temp);
        if(!CheckValidtyOfString(temp) || (temp != "male" && temp != "female"))
        {
            cout << "Found an error in your string\n";
        }
    }while(!CheckValidtyOfString(temp) || (temp != "male" && temp != "female"));

    cs.setgender(temp);

    cout << "Enter the birth year of the Computerscientist: ";

    cin.sync();
    while(!(cin >> bdaytemp) || bdaytemp < 0)
    {
        cin.clear();
        cin.ignore(1);
        cout << "Error Expected integer OR below 0\n";
        cout << "Enter the birth year of the Computerscientist: ";
    }

    cs.setbday(bdaytemp);


    cout << "Enter the death year of the Computerscientist (0 for null): ";
    cin.sync();
    while(!(cin >> dday) || bdaytemp > dday)
    {
        if(dday == 0)
        {
            break;
        }
        cin.clear();
        cin.ignore(1);
        cout << "Error Expected integer OR less than birth year\n";
        cout << "Enter the death year of the Computerscientist: ";
    }
        cs.setdday(dday);

    domain add;
    if(add.AddComputerScientist(cs))
    {
        cout << "ComputerScientist has been added to the database!\n";
    }
    else
    {
        cout << "An unexpected error occurred Data has not been added";
        //always prints out this error, check out tomorrow
    }

    MainMenu();
}

void UI::AddComputer()
{
    computersabstract ca;
    string temp;
    int yeartemp = -1;
    bool built = true;
    cout << "To enter a new computer please fill in the fields\n";

    do{
        cout << "Enter name: ";
        cin.sync();
        getline(cin,temp);
        if(!CheckValidtyOfStringPunct(temp)){
            cout << "Found an error in your string\n";
        }
    }while(!CheckValidtyOfStringPunct(temp));

    temp[0] = toupper(temp[0]);
    ca.setName(temp);
    temp = "";

    cout << "Enter year of discovery: ";
    cin.sync();
    while(!(cin >> yeartemp) || yeartemp < 0){
        cin.clear();
        cin.ignore(1);
        cout << "Error Expected integer OR below 0\n";
        cout << "Enter year of discovery: ";
    }
    ca.setYear(yeartemp);

    do{
        cout << "Enter type(example: Electronic): ";
        cin.sync();
        getline(cin,temp);
        if(!CheckValidtyOfString(temp))
        {
            cout << "Found an error in your string\n";
        }
    }while(!CheckValidtyOfString(temp));

    temp[0] = toupper(temp[0]);
    ca.setType(temp);
    temp = "";

    cout << "Has it been built yet(write 1 for yes, 0 for no): ";
    cin.sync();
    while(!(cin >> built))
        //Needs fixing, will look at better tomorrow
    {
        cin.clear();
        cin.ignore(1);
        cout << "Error Not 0 or 1\n";
        cout << "Has it been built yet(write 1 for yes, 0 for no): ";
    }
    ca.setBuilt(built);

    domain add;
    if(add.AddComputer(ca))
    {
        cout << "Computer has been added to the database!\n";
    }
    else
    {
        cout << "An unexpected error occurred Data has not been added";
        //Always prints out this error, check out tomorrow
    }

    MainMenu();
}

bool UI::CheckValidtyOfString(string& tmp)
{
    for(size_t i = 0; i < tmp.size(); i++)
    {
        if(!isalpha(tmp[i]))
        {
            return false;
        }
    }
    return !tmp.empty();
}

bool UI::CheckValidtyOfStringPunct(string& tmp)
{
    for(size_t i = 0; i < tmp.size(); i++)
    {
        if(ispunct(tmp[i]))
        {
            return false;
        }
    }
    return !tmp.empty();
}
//not sure if correct, but allows to make space, maybe max to 3 spaces

void UI::Tolower(string &temp)
{
    for(unsigned int i = 0; i < temp.size(); i++)
    {
        temp[i] = tolower(temp[i]);
    }
}
