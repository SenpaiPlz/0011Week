/*#include "computerui.h"

ComputerUI::ComputerUI()
{
    ComputerDomain c;
}

void ComputerUI::computerTable(vector<Computer>& tmp)
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


//--------------- Sort Menu and Functions Related ---------------//             //SRT

void ComputerUI::SortComputerMenu()
{
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
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
        case '0': {m.MainMenu(); break;}
        default: {cout << "Invalid choice\n"; break;}
        }
    }
}

void ComputerUI::SortComputerSwitches(const QString& tmp)
{
    string test;
    vector<Computer> temp;
    cout << "------------------------------------------------------------";
    cout << "\nDo you wish to sort in Descending order? y/n: ";
    char in = std::cin.get();
    in = tolower(in);
    if(in != 'y' && in != 'n')
    {
        cout << "------------------------------------------------------------";
        cout << "\nInvalid input\n";
        SortComputerMenu();
    }
    else if(in == 'y')
    {
        temp = c.GetComputers(tmp,1);
        cout << "\n";
        computerTable(temp);
        cout << "------------------------------------------------------------";
        cout << "\nPress enter to continue.";
        getline(cin,test);
        SortComputerMenu();
    }
    else
    {
        temp = c.GetComputers(tmp,0);
        cout << "\n";
        computerTable(temp);
        cout << "------------------------------------------------------------";
        cout << "\nPress enter to continue.";
        getline(cin,test);
        SortComputerMenu();
    }
}


//---------------   Adding  functions   ---------------//       //ADDF

void ComputerUI::AddComputer()
{
    Computer ca;
    string temp;
    int yeartemp = -1;
    bool built = true;
    cout << "------------------------------------------------------------";
    cout << "\nTo enter a new computer please fill in the fields\n";

    do{
        cout << "------------------------------------------------------------";
        cout << "\nEnter name: ";
        cin.sync();
        getline(cin,temp);
        if(!h.CheckValidtyOfString(temp)){
            cout << "------------------------------------------------------------";
            cout << "\nFound an error in your string\n";
        }
    }while(!h.CheckValidtyOfString(temp));

    temp[0] = toupper(temp[0]);
    ca.setName(temp);
    temp = "";

    cout << "------------------------------------------------------------";
    cout << "\nEnter year of discovery: ";
    cin.sync();
    while(!(cin >> yeartemp) || yeartemp < 0){
        cin.clear();
        cin.ignore(1);
        cout << "------------------------------------------------------------";
        cout << "\nError Expected integer OR value is below 0\n";
        cout << "------------------------------------------------------------";
        cout << "\nEnter year of discovery: ";
    }
    ca.setYear(yeartemp);

    do{
        cout << "------------------------------------------------------------";
        cout << "\nEnter type(example: Electronic): ";
        cin.sync();
        getline(cin,temp);
        if(!h.CheckValidtyOfString(temp))
        {
            cout << "------------------------------------------------------------";
            cout << "\nFound an error in your string\n";
        }
    }while(!h.CheckValidtyOfString(temp));

    temp[0] = toupper(temp[0]);
    ca.setType(temp);
    temp = "";

    cout << "------------------------------------------------------------";
    cout << "\nHas it been built yet(write 1 for yes, 0 for no): ";
    cin.sync();
    while(!(cin >> built))
        //Needs fixing, will look at better tomorrow
    {
        cin.clear();
        cin.ignore(1);
        cout << "------------------------------------------------------------";
        cout << "\nError Not 0 or 1\n";
        cout << "------------------------------------------------------------";
        cout << "\nHas it been built yet(write 1 for yes, 0 for no): ";
    }
    ca.setBuilt(built);

    if(c.AddComputer(ca))
    {
        cout << "------------------------------------------------------------";
        cout << "\nComputer has been added to the database!\n";
    }
    else
    {
        cout << "------------------------------------------------------------";
        cout << "\nAn unexpected error occurred Data has not been added";
    }

    m.MainMenu();
}


//---------------  Editing functions  ---------------//     //EDF

void ComputerUI::EditComputer()
{
    string temp;
    string type;
    int yeartemp = -1;
    bool built = true;
    int id = 0;

    string tmp;
    bool valid = false;
    vector<Computer> list = c.GetComputers("id",0);
    computerTable(list);
    do
    {
        cout << "------------------------------------------------------------";
        cout << "Enter an ID to overwrite: ";
        cin.sync();
        getline(cin,tmp);
        if(h.ValidNumber(tmp))
        {
            id = stoi(tmp);
            if(h.ValidComputerId(list,id))
            {
                valid = true;
            }
            else
            {
                cout << "Error: not really an valid ID input is it?\n";
            }
        }
        else
        {
            cout << "Error: not really an valid ID input is it?\n";
        }
    }while(!valid);

    do{
        cout << "------------------------------------------------------------";
        cout << "\nEnter name: ";
        cin.sync();
        getline(cin,temp);
        if(!h.CheckValidtyOfString(temp)){
            cout << "------------------------------------------------------------";
            cout << "\nFound an error in your string\n";
        }
    }while(!h.CheckValidtyOfString(temp));

    temp[0] = toupper(temp[0]);

    cout << "------------------------------------------------------------";
    cout << "\nEnter year of discovery: ";
    cin.sync();
    while(!(cin >> yeartemp) || yeartemp < 0){
        cin.clear();
        cin.ignore(1);
        cout << "------------------------------------------------------------";
        cout << "\nError Expected integer OR value is below 0\n";
        cout << "------------------------------------------------------------";
        cout << "\nEnter year of discovery: ";
    }

    do{
        cout << "------------------------------------------------------------";
        cout << "\nEnter type(example: Electronic): ";
        cin.sync();
        getline(cin,type);
        if(!h.CheckValidtyOfString(type))
        {
            cout << "------------------------------------------------------------";
            cout << "\nFound an error in your string\n";
        }
    }while(!h.CheckValidtyOfString(type));

    type[0] = toupper(type[0]);

    cout << "------------------------------------------------------------";
    cout << "\nHas it been built yet(write 1 for yes, 0 for no): ";
    cin.sync();
    while(!(cin >> built))
    {
        cin.clear();
        cin.ignore(1);
        cout << "------------------------------------------------------------";
        cout << "\nError Not 0 or 1\n";
        cout << "------------------------------------------------------------";
        cout << "\nHas it been built yet(write 1 for yes, 0 for no): ";
    }


    if(c.UpdateComputer(QString::fromStdString(temp), yeartemp, QString::fromStdString(type), built, id))
    {
        cout << "------------------------------------------------------------";
        cout << "\nComputer has been edited!\n";
    }
    else
    {
        cout << "------------------------------------------------------------";
        cout << "\nAn unexpected error occurred Data has not been edited";
    }

    m.MainMenu();
}
*/
