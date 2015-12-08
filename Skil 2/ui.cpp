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
        cout << setw(12) << tmp[i].getMid();
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

void UI::linkTable(vector<ComputerScientist>& temp, vector<computersabstract>& tmp, vector<int>& rowid)
{
    //Header for table
    cout << left << "| " << setw(30) << "Computer Scientist" << "| "
         << setw(4) << "ID" << "| " << setw(4)
         << "ID" << "| " << setw(20) << "Computer" << "| RowID"
         << endl;
    cout << "-----------------------------------------------------------------------" << endl;
    //Input into table
    for(size_t i = 0; i < tmp.size(); i++)
    {
        cout << left << "| "  << setw(30) <<  (temp[i].getFirst() + " " + temp[i].getMid() + " " + temp[i].getLast()) << "| "
             << setw(4) << temp[i].getID() << "| " << setw(4) << tmp[i].getID()
             << "| " << setw(20) << tmp[i].getName() << "| " << rowid[i]
             << endl;
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
    cout << "\t    ~~The super cool Scientist&Computer SQL Program~~\n\n";
    cout << "\t    << This program helps you learn more about the >>\n"
            "\t    <<    amazing Computer Scientist and the       >>\n"
            "\t    <<  Computers they built that have changed the >>\n"
            "\t    <<  world as we know it with their inventions. >>\n";

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
        case '4': {EditCS(); break;}
        case '5': {AddComputer(); break;}
        case '6': {EditComputer(); break;}
        case '7': {LinkMenu(); break;}
        case '8': {SearchMenu(); break;}
        case '9': {DeleteMenu(); break;}
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
    cout << "4.\t\tSort by Gender\n";
    cout << "5.\t\tSort by Birth Year\n";
    cout << "6.\t\tSort by Death Year\n";
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
            SortScientistSwitches("gender");
            break;
        }
        case '5':
        {
            SortScientistSwitches("birth_year");
            break;
        }
        case '6':
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
    cout << "---------------------------------------------------";
    cout << "\nDo you wish to sort in Descending order? y/n: ";
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
        cout << "---------------------------------------------------";
        cout << "\nPress ENTER to continue.";
        getline(cin,test);
        SortScientistMenu();
    }
    else
    {
        temp = sort.GetComputerScientist(tmp,0);
        cout << "\n";
        scientistTable(temp);
        cout << "---------------------------------------------------";
        cout << "\nPress ENTER to continue.";
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
    cout << "---------------------------------------------------";
    cout << "\nDo you wish to sort in Descending order? y/n: ";
    char in = std::cin.get();
    in = tolower(in);
    if(in != 'y' && in != 'n')
    {
        cout << "---------------------------------------------------";
        cout << "\nInvalid input\n";
        SortComputerMenu();
    }
    else if(in == 'y')
    {
        temp = sort.GetComputers(tmp,1);
        cout << "\n";
        computerTable(temp);
        cout << "---------------------------------------------------";
        cout << "\nPress enter to continue.";
        getline(cin,test);
        SortComputerMenu();
    }
    else
    {
        temp = sort.GetComputers(tmp,0);
        cout << "\n";
        computerTable(temp);
        cout << "---------------------------------------------------";
        cout << "\nPress enter to continue.";
        getline(cin,test);
        SortComputerMenu();
    }
}

void UI::AddComputerScientist()
{
    ComputerScientist cs;
    string temp;
    int bdaytemp = -1, dday = -1;
    cout << "---------------------------------------------------";
    cout << "\nTo enter a new scientist please fill in \nthe fields with only a single string\n";

    //Checks input for every name to see if it's valid//
    do{
        cout << "---------------------------------------------------";
        cout << "\nEnter First Name: ";
        cin.sync();
        getline(cin,temp);
        if(!CheckValidtyOfString(temp))
        {
            cout << "---------------------------------------------------";
            cout << "\nFound an error in your string\n";
        }
    }while(!CheckValidtyOfString(temp));

    temp[0] = toupper(temp[0]);
    cs.setFirst(temp);
    temp = "";

    do{
        cout << "---------------------------------------------------";
        cout << "\nEnter Middle Name (Type NULL if it's empty): ";
        cin.sync();
        getline(cin,temp);
        if(!CheckValidtyOfString(temp))
        {
            cout << "---------------------------------------------------";
            cout << "\nFound an error in your string\n";
        }
    }while(!CheckValidtyOfString(temp));

    Tolower(temp);
    if(temp == "null")
    {
        temp.clear();
    }
    else
    {
        temp[0] = toupper(temp[0]);
    }
    cs.setMid(temp);
    temp = "";

    do{
        cout << "---------------------------------------------------";
        cout << "\n(You can enter a single space i.e von Neuman)\n";
        cout << "---------------------------------------------------";
        cout << "\nEnter Last Name: ";
        cin.sync();
        getline(cin,temp);
        if(!CheckValidtyOfStringWithASingleSpace(temp))
        {
            cout << "---------------------------------------------------";
            cout << "\nFound an error in your string\n";
        }
    }while(!CheckValidtyOfStringWithASingleSpace(temp));

    temp[0] = toupper(temp[0]);
    cs.setLast(temp);
    temp = "";

    do{
        cout << "---------------------------------------------------";
        cout << "\nEnter the Gender: ";
        cin.sync();
        getline(cin,temp);
        Tolower(temp);
        if(!CheckValidtyOfString(temp) || (temp != "male" && temp != "female"))
        {
            cout << "---------------------------------------------------";
            cout << "\nFound an error in your string\n";
        }
    }while(!CheckValidtyOfString(temp) || (temp != "male" && temp != "female"));

    cs.setgender(temp);

    cout << "---------------------------------------------------";
    cout << "\nEnter the birth year of the Computerscientist: ";

    cin.sync();
    while(!(cin >> bdaytemp) || (bdaytemp < 0 || bdaytemp > 2015))
    {
        cin.clear();
        cin.ignore(1);
        cout << "---------------------------------------------------";
        cout << "\nError: Expected integer OR value is below 0\n";
        cout << "---------------------------------------------------";
        cout << "\nEnter the birth year of the Computerscientist: ";
    }

    cs.setbday(bdaytemp);


    cout << "---------------------------------------------------";
    cout << "\nEnter the death year of the Computerscientist (0 for null): ";
    cin.sync();
    while(!(cin >> dday) || (bdaytemp > dday || dday > 2015))
    {
        if(dday == 0)
        {
            break;
        }
        cin.clear();
        cin.ignore(1);
        cout << "---------------------------------------------------";
        cout << "\nError Expected integer OR less than birth year\n";
        cout << "---------------------------------------------------";
        cout << "\nEnter the death year of the Computerscientist: ";
    }
        cs.setdday(dday);

    domain add;
    if(add.AddComputerScientist(cs))
    {
        cout << "---------------------------------------------------";
        cout << "\nComputerScientist has been added to the database!\n";
    }
    else
    {
        cout << "---------------------------------------------------";
        cout << "\nAn unexpected error occurred Data has not been added";
    }

    MainMenu();
}

void UI::AddComputer()
{
    computersabstract ca;
    string temp;
    int yeartemp = -1;
    bool built = true;
    cout << "---------------------------------------------------";
    cout << "\nTo enter a new computer please fill in the fields\n";

    do{
        cout << "---------------------------------------------------";
        cout << "\nEnter name: ";
        cin.sync();
        getline(cin,temp);
        if(!CheckValidtyOfStringPunct(temp)){
            cout << "---------------------------------------------------";
            cout << "\nFound an error in your string\n";
        }
    }while(!CheckValidtyOfStringPunct(temp));

    temp[0] = toupper(temp[0]);
    ca.setName(temp);
    temp = "";

    cout << "---------------------------------------------------";
    cout << "\nEnter year of discovery: ";
    cin.sync();
    while(!(cin >> yeartemp) || yeartemp < 0){
        cin.clear();
        cin.ignore(1);
        cout << "---------------------------------------------------";
        cout << "\nError Expected integer OR value is below 0\n";
        cout << "---------------------------------------------------";
        cout << "\nEnter year of discovery: ";
    }
    ca.setYear(yeartemp);

    do{
        cout << "---------------------------------------------------";
        cout << "\nEnter type(example: Electronic): ";
        cin.sync();
        getline(cin,temp);
        if(!CheckValidtyOfString(temp))
        {
            cout << "---------------------------------------------------";
            cout << "\nFound an error in your string\n";
        }
    }while(!CheckValidtyOfString(temp));

    temp[0] = toupper(temp[0]);
    ca.setType(temp);
    temp = "";

    cout << "---------------------------------------------------";
    cout << "\nHas it been built yet(write 1 for yes, 0 for no): ";
    cin.sync();
    while(!(cin >> built))
        //Needs fixing, will look at better tomorrow
    {
        cin.clear();
        cin.ignore(1);
        cout << "---------------------------------------------------";
        cout << "\nError Not 0 or 1\n";
        cout << "---------------------------------------------------";
        cout << "\nHas it been built yet(write 1 for yes, 0 for no): ";
    }
    ca.setBuilt(built);

    domain add;
    if(add.AddComputer(ca))
    {
        cout << "---------------------------------------------------";
        cout << "\nComputer has been added to the database!\n";
    }
    else
    {
        cout << "---------------------------------------------------";
        cout << "\nAn unexpected error occurred Data has not been added";
    }

    MainMenu();
}

void UI::EditCS()
{
    string str;
    int id = 0;
    bool valid = false;
    domain d;
    vector<ComputerScientist> allcs = d.GetComputerScientist("id",0);
    scientistTable(allcs);
    do
    {
        cin.sync();
        cout << "---------------------------------------------------";
        cout << "\nEnter an ID to overwrite: ";
        getline(cin,str);
        if(ValidNumber(str))
        {
            id = stoi(str);
            if(ValidCSId(allcs,id))
            {
                valid = true;
            }
            else
            {
                cout << "---------------------------------------------------";
                cout << "\nError: not really an valid ID input is it?\n";
            }
        }
        else
        {
            cout << "---------------------------------------------------";
            cout << "\nError: not really an valid ID input is it?\n";
        }
    }while(!valid);

    string tempfirst = "";
    int bdaytemp = -1, dday = -1;
    cout << "---------------------------------------------------";
    cout << "\nTo edit the scientist please fill in \nall the fields.\n";

    do{
        cout << "---------------------------------------------------";
        cout << "\nEnter First Name: ";
        cin.sync();
        getline(cin,tempfirst);
        if(!CheckValidtyOfString(tempfirst))
        {
            cout << "---------------------------------------------------";
            cout << "\nFound an error in your string\n";
        }
    }while(!CheckValidtyOfString(tempfirst));

    tempfirst[0] = toupper(tempfirst[0]);
    string  tempmid;

    do{
        cout << "---------------------------------------------------";
        cout << "\nEnter Middle Name (Type NULL if it's empty): ";
        cin.sync();
        getline(cin,tempmid);
        if(!CheckValidtyOfString(tempmid))
        {
            cout << "---------------------------------------------------";
            cout << "\nFound an error in your string\n";
        }
    }while(!CheckValidtyOfString(tempmid));

    Tolower(tempmid);
    if(tempmid == "null")
    {
        tempmid.clear();
    }
    else
    {
        tempmid[0] = toupper(tempmid[0]);
    }
    string tmplast;

    do{
        cout << "---------------------------------------------------";
        cout << "\n(You can enter a single space i.e von Neuman)\n";
        cout << "---------------------------------------------------";
        cout << "\nEnter Last Name: ";
        cin.sync();
        getline(cin,tmplast);
        if(!CheckValidtyOfStringWithASingleSpace(tmplast))
        {
            cout << "---------------------------------------------------";
            cout << "\nFound an error in your string\n";
        }
    }while(!CheckValidtyOfStringWithASingleSpace(tmplast));

    tmplast[0] = toupper(tmplast[0]);
    string tempgender;

    do{
        cout << "---------------------------------------------------";
        cout << "\nEnter the Gender: ";
        cin.sync();
        getline(cin,tempgender);
        Tolower(tempgender);
        if(!CheckValidtyOfString(tempgender) || (tempgender != "male" && tempgender != "female"))
        {
            cout << "---------------------------------------------------";
            cout << "\nFound an error in your string\n";
        }
    }while(!CheckValidtyOfString(tempgender) || (tempgender != "male" && tempgender != "female"));

    cout << "---------------------------------------------------";
    cout << "\nEnter the birth year of the Computerscientist: ";

    cin.sync();
    while(!(cin >> bdaytemp) || (bdaytemp < 0 || bdaytemp > 2015))
    {
        cin.clear();
        cin.ignore(1);
        cout << "---------------------------------------------------";
        cout << "\nError: Expected integer OR value is below 0\n";
        cout << "---------------------------------------------------";
        cout << "\nEnter the birth year of the Computerscientist: ";
    }

    cout << "---------------------------------------------------";
    cout << "\nEnter the death year of the Computerscientist (0 for null): ";
    cin.sync();
    while(!(cin >> dday) || (bdaytemp > dday || dday > 2015))
    {
        if(dday == 0)
        {
            break;
        }
        cin.clear();
        cin.ignore(1);
        cout << "---------------------------------------------------";
        cout << "\nError Expected integer OR less than birth year\n";
        cout << "---------------------------------------------------";
        cout << "\nEnter the death year of the Computerscientist: ";
    }

    if(d.UpdateCS(QString::fromStdString(tempfirst),QString::fromStdString(tempmid),
                  QString::fromStdString(tmplast),QString::fromStdString(tempgender),bdaytemp,dday,id))
    {
        cout << "---------------------------------------------------";
        cout << "\nComputerScientist id: " << id << " has been edited!";
    }
    else
    {
        cout << "---------------------------------------------------";
        cout << "\nAn unexpected error occurred Data has not been added";
    }
    MainMenu();
}

void UI::EditComputer()
{
    string temp;
    string type;
    int yeartemp = -1;
    bool built = true;
    int id = 0;

    string tmp;
    bool valid = false;
    vector<computersabstract> list = d.GetComputers("id",0);
    computerTable(list);
    do
    {
        cout << "---------------------------------------------------";
        cout << "\nEnter an ID to overwrite: ";
        cin.sync();
        getline(cin,tmp);
        if(ValidNumber(tmp))
        {
            id = stoi(tmp);
            if(ValidComputerId(list,id))
            {
                valid = true;
            }
            else
            {
                cout << "---------------------------------------------------";
                cout << "\nError: not really an valid ID input is it?\n";
            }
        }
        else
        {
            cout << "---------------------------------------------------";
            cout << "\nError: not really an valid ID input is it?\n";
        }
    }while(!valid);

    do{
        cout << "---------------------------------------------------";
        cout << "\nEnter name: ";
        cin.sync();
        getline(cin,temp);
        if(!CheckValidtyOfStringPunct(temp)){
            cout << "---------------------------------------------------";
            cout << "\nFound an error in your string\n";
        }
    }while(!CheckValidtyOfStringPunct(temp));

    temp[0] = toupper(temp[0]);

    cout << "---------------------------------------------------";
    cout << "\nEnter year of discovery: ";
    cin.sync();
    while(!(cin >> yeartemp) || yeartemp < 0){
        cin.clear();
        cin.ignore(1);
        cout << "---------------------------------------------------";
        cout << "\nError Expected integer OR value is below 0\n";
        cout << "---------------------------------------------------";
        cout << "\nEnter year of discovery: ";
    }

    do{
        cout << "---------------------------------------------------";
        cout << "\nEnter type(example: Electronic): ";
        cin.sync();
        getline(cin,type);
        if(!CheckValidtyOfString(type))
        {
            cout << "---------------------------------------------------";
            cout << "\nFound an error in your string\n";
        }
    }while(!CheckValidtyOfString(type));

    type[0] = toupper(type[0]);

    cout << "---------------------------------------------------";
    cout << "\nHas it been built yet(write 1 for yes, 0 for no): ";
    cin.sync();
    while(!(cin >> built))
    {
        cin.clear();
        cin.ignore(1);
        cout << "---------------------------------------------------";
        cout << "\nError Not 0 or 1\n";
        cout << "---------------------------------------------------";
        cout << "\nHas it been built yet(write 1 for yes, 0 for no): ";
    }


    if(d.UpdateComputer(QString::fromStdString(temp), yeartemp, QString::fromStdString(type), built, id))
    {
        cout << "---------------------------------------------------";
        cout << "\nComputer has been edited!\n";
    }
    else
    {
        cout << "---------------------------------------------------";
        cout << "\nAn unexpected error occurred Data has not been edited";
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

bool UI::CheckValidtyOfStringWithASingleSpace(string& tmp)
{
    int count = 0;
    for(size_t i = 0; i < tmp.size(); i++)
    {
        if(tmp[i] == ' ')
        {
            count++;
        }
        if(count >= 2)
        {
            return false;
        }
    }
    for(size_t i = 0; i < tmp.size(); i++)
    {
        if(!isalpha(tmp[i]) && count >= 2)
        {
            return false;
        }
    }
    return !tmp.empty();
}

bool UI::CheckValidtyOfStringPunct(string& tmp)
{
    int count = 0;
    for(size_t i = 0; i < tmp.size(); i++)
    {
        if(tmp[i] == ' ')
        {
            count++;
        }
        if(ispunct(tmp[i]) || count > 1)
        {
            return false;
        }
    }
    return !tmp.empty();
}
//Made it so that the can have 1 space, no more.

void UI::Tolower(string &temp)
{
    for(unsigned int i = 0; i < temp.size(); i++)
    {
        temp[i] = tolower(temp[i]);
    }
}

bool UI::ValidNumber(string &temp)
{
    for(unsigned int i = 0; i < temp.size(); i++)
    {
        if(!isdigit(temp[i]))
        {
            return false;
        }
    }
    return !temp.empty();
}

void UI::DeleteMenu()
{
    domain del;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "\n#######-----------      Delete Menu     -----------#######\n";
    cout << "1.\t\tMark Scientist for Deletion\n";
    cout << "2.\t\tUn-Mark Scientist for Deletion\n";
    cout << "3.\t\tMark Computer for Deletion\n";
    cout << "4.\t\tUn-Mark Computer for Deletion\n";
    cout << "5.\t\tView Scientists Marked for Deletion\n";
    cout << "6.\t\tView Computers Marked for Deletion\n";
    cout << "7.\t\tDelete all marked items! #WARNING#\n";
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
            int stoitemp = 0;
            string tmp;
            bool valid = false;
            vector<ComputerScientist> temp = del.GetComputerScientist("id",0);
            scientistTable(temp);
            do
            {
                cout << "---------------------------------------------------";
                cout << "\nEnter an ID to Mark: ";
                cin.sync();
                getline(cin,tmp);
                if(ValidNumber(tmp))
                {
                    stoitemp = stoi(tmp);
                    if(!ValidCSId(temp,stoitemp))
                    {
                        cout << "---------------------------------------------------";
                        cout << "\nNo scientist matching that ID.\n";
                    }
                    else
                    {
                        valid = true;
                    }
                }
                else
                {
                    cout << "---------------------------------------------------";
                    cout << "\nError: Unexpect input in baggage area\n";
                    stoitemp = 0;
                }
            }while(!valid);

            if(del.MarkDeleted("scientists",stoitemp))
            {
                cout << "---------------------------------------------------";
                cout << "\nMarked ID: " << stoitemp << " for deletion\n";
                cout << "---------------------------------------------------";
                cout << "\nPress ENTER to go back to DELETE MENU.";
            }
            else
            {
                cout << "---------------------------------------------------";
                cout << "\nERROR: something went wrong here.\n";
                cout << "---------------------------------------------------";
                cout << "\nPress ENTER to go back to DELETE MENU.";
            }
            DeleteMenu();
            break;
        }
        case '2':
        {
            int stoitemp;
            string tmp;
            bool valid = false;
            vector<ComputerScientist> temp = del.GetDeletedCS();
            scientistTable(temp);
            do
            {
                cout << "---------------------------------------------------";
                cout << "\nEnter an ID to Un-Mark: ";
                cin.sync();
                getline(cin,tmp);
                if(ValidNumber(tmp))
                {
                    stoitemp = stoi(tmp);
                    if(!ValidCSId(temp,stoitemp))
                    {
                        cout << "---------------------------------------------------";
                        cout << "\nNo scientist matching that ID.\n";
                    }
                    else
                    {
                        valid = true;
                    }
                }
                else
                {
                    cout << "---------------------------------------------------";
                    cout << "\nError: Unexpect input in baggage area\n";
                    stoitemp = 0;
                }
            }while(!valid);

            if(del.UnmarkDeleted("scientists",stoitemp))
            {
                cout << "---------------------------------------------------";
                cout << "\nUn-Marked ID: " << stoitemp << " for deletion\n";
                cout << "---------------------------------------------------";
                cout << "\nPress ENTER to go back to DELETE MENU.";
            }
            else
            {
                cout << "---------------------------------------------------";
                cout << "\nERROR: something went wrong here.\n";
                cout << "---------------------------------------------------";
                cout << "\nPress ENTER to go back to DELETE MENU.";
            }
            DeleteMenu();
            break;
        }
        case '3':
        {
            int stoitemp;
            string tmp;
            bool valid = false;
            vector<computersabstract> temp = del.GetComputers("id",0);
            computerTable(temp);
            do
            {
                cout << "---------------------------------------------------";
                cout << "\nEnter an ID to Mark: ";
                cin.sync();
                getline(cin,tmp);
                if(ValidNumber(tmp))
                {
                    stoitemp = stoi(tmp);
                    if(!ValidComputerId(temp,stoitemp))
                    {
                        cout << "---------------------------------------------------";
                        cout << "\nNo computer matching that ID.\n";
                    }
                    else
                    {
                        valid = true;
                    }
                }
                else
                {
                    cout << "---------------------------------------------------";
                    cout << "\nError: Unexpect input in baggage area\n";
                    stoitemp = 0;
                }
            }while(!valid);

            if(del.MarkDeleted("computers",stoitemp))
            {
                cout << "---------------------------------------------------";
                cout << "\nMarked ID: " << stoitemp << " for deletion\n";
                cout << "---------------------------------------------------";
                cout << "\nPress ENTER to go back to DELETE MENU.";
            }
            else
            {
                cout << "---------------------------------------------------";
                cout << "\nERROR: something went wrong here.\n";
                cout << "---------------------------------------------------";
                cout << "\nPress ENTER to go back to DELETE MENU.";
            }
            DeleteMenu();
            break;
        }
        case '4':
        {
            int stoitemp;
            string tmp;
            bool valid = false;
            vector<computersabstract> temp = del.GetDeletedComputers();
            computerTable(temp);
            do
            {
                cout << "---------------------------------------------------";
                cout << "\nEnter an ID to Un-Mark: ";
                cin.sync();
                getline(cin,tmp);
                if(ValidNumber(tmp))
                {
                    stoitemp = stoi(tmp);
                    if(!ValidComputerId(temp,stoitemp))
                    {
                        cout << "---------------------------------------------------";
                        cout << "\nNo computer matching that ID.\n";
                    }
                    else
                    {
                        valid = true;
                    }
                }
                else
                {
                    cout << "---------------------------------------------------";
                    cout << "\nError: Unexpect input in baggage area\n";
                    stoitemp = 0;
                }
            }while(!valid);

            if(del.UnmarkDeleted("computers",stoitemp))
            {
                cout << "---------------------------------------------------";
                cout << "\nUn-Marked ID: " << stoitemp << " for deletion\n";
                cout << "---------------------------------------------------";
                cout << "\nPress ENTER to go back to DELETE MENU.";
            }
            else
            {
                cout << "---------------------------------------------------";
                cout << "\nERROR: something went wrong here.\n";
                cout << "---------------------------------------------------";
                cout << "\nPress ENTER to go back to DELETE MENU.";
            }
            DeleteMenu();
            break;
        }
        case '5':
        {
            vector<ComputerScientist> temp = del.GetDeletedCS();
            scientistTable(temp);
            cout << "---------------------------------------------------";
            cout << "\nPress ENTER to continue";
            DeleteMenu();
            break;
        }
        case '6':
        {
            vector<computersabstract> temp = del.GetDeletedComputers();
            computerTable(temp);
            cout << "---------------------------------------------------";
            cout << "\nPress ENTER to continue";
            DeleteMenu();
            break;
        }
        case '7':
        {
            domain del;

            if(del.DeleteAllMarked())
            {
                cout << "\n######  DELETING ALL MARKED  ######\n";
            }
            else
            {
                cout << "---------------------------------------------------";
                cout << "\nSomething went wrong\n";
            }
            cout << "---------------------------------------------------";
            cout << "\nPress ENTER to go back to DELETE MENU.";
            DeleteMenu();
            break;
        }
        case '0': {MainMenu(); break;}
        default: {cout << "Invalid choice\n"; cin.sync(); break;}
        }
    }
}

bool UI::ValidCSId(vector<ComputerScientist>& tmp, const int& id)
{
    for(size_t i = 0; i < tmp.size(); i++)
    {
        if(tmp[i].getID() == id)
        {
            return true;
        }
    }
    return false;
}

bool UI::ValidComputerId(vector<computersabstract>& tmp, const int& id)
{
    for(size_t i = 0; i < tmp.size(); i++)
    {
        if(tmp[i].getID() == id)
        {
            return true;
        }
    }
    return false;
}

void UI::LinkMenu()
{
    cin.sync();
    domain inner;
    vector<ComputerScientist> cstemp = inner.GetCSInnerJoin();
    vector<computersabstract> computertemp = inner.GetComputerInnerJoin();
    vector<int> rowid = inner.GetRowID();

    cout << "\n#######-----------      Linking Menu     -----------#######\n";
    cout << "1.\tView Linked ComputerScientists & computers.\n";
    cout << "2.\tDelete A link between Computerscientist & computer.\n";
    cout << "3.\tAdd A Link between computerscientist & computer\n";
    cout << "0.\tMAIN MENU\n\n";
    cout << "choice: ";
    while(true)
    {
        cin.sync();
        char choice = cin.get();
        switch(choice)
        {
        case '1':
        {
            linkTable(cstemp,computertemp,rowid);
            LinkMenu();
            break;
        }
        case '2':
        {
            string tmp;
            int choice;
            bool valid = false;
            int count = 0;
            linkTable(cstemp,computertemp,rowid);
            do
            {
                valid = false;
                if(count > 0)
                {
                    cout << "---------------------------------------------------";
                    cout << "\nThese are not the Row-ID's we are looking for\n";
                }

                cout << "---------------------------------------------------";
                cout << "\nEnter a ID of a row to delete: ";
                cin.sync();
                getline(cin,tmp);
                if(ValidNumber(tmp))
                {
                    choice = stoi(tmp);
                    for(unsigned int i = 0; i < rowid.size(); i++)
                    {
                        if(choice == rowid[i])
                        {
                            valid = true;
                        }
                    }
                }
                count++;
            }while(!valid);
            if(inner.DeleteLink(choice))
            {
                cout << "---------------------------------------------------";
                cout << "\nDelete successful\n";
            }
            else
            {
                cout << "---------------------------------------------------";
                cout << "\nSomething happened here I'm not sure what.\n";
            }
            LinkMenu();
            break;
        }
        case '3':
        {
            string str;
            int cs;
            int comp;
            vector<ComputerScientist> temp = inner.GetComputerScientist("id",0);
            bool valid = false;
            scientistTable(temp);
            do
            {
                cout << "---------------------------------------------------";
                cout << "\nEnter an ID to LINK: ";
                cin.sync();
                getline(cin,str);
                if(ValidNumber(str))
                {
                    cs = stoi(str);
                    if(!ValidCSId(temp,cs))
                    {
                        cout << "---------------------------------------------------";
                        cout << "\nNo computer matching that ID.\n";
                    }
                    else
                    {
                        valid = true;
                    }
                }
                else
                {
                    cout << "---------------------------------------------------";
                    cout << "\nError: Unexpect input in baggage area\n";
                    cs = 0;
                }
            }while(!valid);
            vector<computersabstract> tmp = inner.GetComputers("id",0);
            valid = false;
            computerTable(tmp);
            do
            {
                cout << "---------------------------------------------------";
                cout << "\nEnter an ID to LINK: ";
                cin.sync();
                getline(cin,str);
                if(ValidNumber(str))
                {
                    comp = stoi(str);
                    if(!ValidComputerId(tmp,comp))
                    {
                        cout << "---------------------------------------------------";
                        cout << "\nNo computer matching that ID.\n";
                    }
                    else
                    {
                        valid = true;
                    }
                }
                else
                {
                    cout << "---------------------------------------------------";
                    cout << "\Error: Unexpect input in baggage area\n";
                    comp = 0;
                }
            }while(!valid);
            if(inner.AddLink(cs,comp))
            {
                cout << "---------------------------------------------------";
                cout << "\n\nSuccessfully linked ComputerScientist & Computer.\n";
            }
            else
            {
                cout << "---------------------------------------------------";
                cout << "\n\nSomething Bad happened, probably!";
            }
            LinkMenu();
            break;
        }
        case '0': {MainMenu(); break;}
        default: {cout << "Invalid choice\n"; break;}
        }
    }
}

void UI::SearchMenu()
{
    domain search;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "\n#######-----------      Search Menu     -----------#######\n";
    cout << "1.\t\tSearch for a Scientist\n";
    cout << "2.\t\tSearch for a Scientist *ID* only\n";
    cout << "3.\t\tSearch for a Computer\n";
    cout << "4.\t\tSearch for a Computer *ID* only\n";
    cout << "0.\t\tMAIN MENU\n";
    cout << "choice: ";
    char choice = cin.get();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');


    while(true)
    {
        switch(choice)
        {
        case '1':
        {

            vector<ComputerScientist> list = search.GetComputerScientist("id",0);
            string str;
            bool valid = false;
            do{
                cout << "---------------------------------------------------";
                cout << "\nEnter any info you have on your beloved Scientist: ";
                cin.sync();
                getline(cin, str);
                if(str.empty())
                {
                    scientistTable(list);
                    cout << "---------------------------------------------------";
                    cout << "\nWrite out any info you have to find it in the list.\n";
                }

                else
                {
                    valid = true;
                }

            }while(!valid);

            QString newstr = QString::fromUtf8(str.c_str());
            vector<ComputerScientist> tmp = search.SearchCS(newstr);
            scientistTable(tmp);
            cout << "---------------------------------------------------";
            cout << "\nPress ENTER to go back to SEARCH MENU.";

            SearchMenu();
            break;
        }
        case '2':
        {
            int stoitemp = 0;
            vector<ComputerScientist> list = search.GetComputerScientist("id",0);
            string str;
            bool valid = false;
            do{
                cout << "---------------------------------------------------";
                cout << "\nEnter Scientist ID: ";
                cin.sync();
                getline(cin, str);
                if(str.empty())
                {
                    scientistTable(list);
                    cout << "---------------------------------------------------";
                    cout << "\nChoose an ID from the list.\n";
                }
                else if(ValidNumber(str))
                {
                    stoitemp = stoi(str);
                    if(!ValidCSId(list,stoitemp))
                    {
                        cout << "---------------------------------------------------";
                        cout << "\nNo scientist with that ID.\n";
                    }
                    else
                    {
                        valid = true;
                    }
                }
                else
                {
                    cout << "---------------------------------------------------";
                    cout << "\nError: Unexpected input.\n";
                    stoitemp = 0;
                }

            }while(!valid);
            //Need to be able to show only nr. 1, not all with 1 in them...

            vector<ComputerScientist> tmp = search.SearchCSID(stoitemp);
            scientistTable(tmp);
            cout << "---------------------------------------------------";
            cout << "\nPress ENTER to go back to SEARCH MENU.";

            SearchMenu();
            break;
        }
        case '3':
        {
            vector<computersabstract> list = search.GetComputers("id",0);
            string str;
            bool valid = false;
            do{
                cout << "---------------------------------------------------";
                cout << "\nEnter any info you have on a Computer: ";
                cin.sync();
                getline(cin, str);
                if(str.empty())
                {
                    computerTable(list);
                    cout << "---------------------------------------------------";
                    cout << "\nWrite out any info you have to find it in the list.\n";
                }

                else
                {
                    valid = true;
                }

            }while(!valid);

            QString newstr = QString::fromUtf8(str.c_str());
            vector<computersabstract> tmp = search.SearchComputer(newstr);
            computerTable(tmp);
            cout << "---------------------------------------------------";
            cout << "\nPress ENTER to go back to SEARCH MENU.";

            SearchMenu();
            break;
        }
        case '4':
        {
            int stoitemp = 0;
            vector<computersabstract> list = search.GetComputers("id",0);
            string str;
            bool valid = false;
            do{
                cout << "---------------------------------------------------";
                cout << "\nEnter Computer ID: ";
                cin.sync();
                getline(cin, str);
                if(str.empty())
                {
                    computerTable(list);
                    cout << "---------------------------------------------------";
                    cout << "\nChoose an ID from the list.\n";
                }
                else if(ValidNumber(str))
                {
                    stoitemp = stoi(str);
                    if(!ValidComputerId(list,stoitemp))
                    {
                        cout << "---------------------------------------------------";
                        cout << "\nNo computer with that ID.\n";
                    }
                    else
                    {
                        valid = true;
                    }
                }
                else
                {
                    cout << "---------------------------------------------------";
                    cout << "\nError: Unexpected input.\n";
                    stoitemp = 0;
                }

            }while(!valid);
            //Need to be able to show only nr. 1, not all with 1 in them...

            vector<computersabstract> tmp = search.SearchComputerID(stoitemp);

            computerTable(tmp);

            cout << "---------------------------------------------------";
            cout << "\nPress ENTER to go back to SEARCH MENU.";

            SearchMenu();
            break;
        }
        case '0': {MainMenu(); break;}
        default: {cout << "Invalid choice\n---------------------------------------------------\nPress ENTER for Search Menu!"; SearchMenu(); break;}
        }
    }
}
