/*#include "scientistui.h"

ScientistUI::ScientistUI()
{
    ScientistDomain d;
}

void ScientistUI::scientistTable(vector<ComputerScientist>& tmp)
{
    //Header for table
    cout << left << "| " << setw(3) << "ID" << "| "
             << setw(14) << "First Name" << "| " << setw(14)
             << "Middle N." << "| " << setw(14) << "Last Name" << "| "
             << setw(7) << "Gender" << "| " << setw(6) << "Birth" << "| "
             << setw(6) << "Death" <<  "|"
             << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
    //Input into table
    for(size_t i = 0; i < tmp.size(); i++)
    {
        cout << left << "| " << setw(3) << tmp[i].getID() << "| " << setw(14)
             << tmp[i].getFirst() << "| " ;
        cout << setw(14) << tmp[i].getMid();
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

void ScientistUI::linkTable(vector<ComputerScientist>& temp, vector<Computer>& tmp, vector<int>& rowid)
{
    //Header for table
    cout << left << "| " << setw(30) << "Computer Scientist" << "| "
         << setw(4) << "ID" << "| " << setw(4)
         << "ID" << "| " << setw(20) << "Computer" << "| RowID"
         << endl;
    cout << "------------------------------------------------------------" << endl;
    //Input into table
    for(size_t i = 0; i < tmp.size(); i++)
    {
        cout << left << "| "  << setw(30) <<  (temp[i].getFirst() + " " + temp[i].getMid() + " " + temp[i].getLast()) << "| "
             << setw(4) << temp[i].getID() << "| " << setw(4) << tmp[i].getID()
             << "| " << setw(20) << tmp[i].getName() << "| " << rowid[i]
             << endl;
    }
}

void ScientistUI::SortScientistMenu()
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

void ScientistUI::SortScientistSwitches(const QString& tmp)
{
    string test;
    vector<ComputerScientist> temp;
    cout << "------------------------------------------------------------";
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
        temp = d.GetComputerScientist(tmp,1);
        cout << "\n";
        scientistTable(temp);
        cout << "------------------------------------------------------------";
        cout << "\nPress ENTER to continue.";
        getline(cin,test);
        SortScientistMenu();
    }
    else
    {
        temp = d.GetComputerScientist(tmp,0);
        cout << "\n";
        scientistTable(temp);
        cout << "------------------------------------------------------------";
        cout << "\nPress ENTER to continue.";
        getline(cin,test);
        SortScientistMenu();
    }
}

//---------------   Adding  functions   ---------------//       //ADDF


void ScientistUI::AddComputerScientist()
{
    ComputerScientist cs;
    string temp;
    int bdaytemp = -1, dday = -1;
    cout << "------------------------------------------------------------";
    cout << "\nTo enter a new scientist please fill out this form\n";

    //Checks input for every name to see if it's valid//
    do{
        cout << "------------------------------------------------------------";
        cout << "\nEnter First Name: ";
        cin.sync();
        getline(cin,temp);
        if(!h.CheckValidtyOfString(temp))
        {
            cout << "------------------------------------------------------------";
            cout << "\nFound an error in your string\n";
        }
    }while(!h.CheckValidtyOfString(temp));

    temp[0] = toupper(temp[0]);
    cs.setFirst(temp);
    temp = "";

    do{
        cout << "------------------------------------------------------------";
        cout << "\nEnter Middle Name (Type NULL if it's empty): ";
        cin.sync();
        getline(cin,temp);
        if(!h.CheckValidtyOfString(temp))
        {
            cout << "------------------------------------------------------------";
            cout << "\nFound an error in your string\n";
        }
    }while(!h.CheckValidtyOfString(temp));

    h.Tolower(temp);
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
        cout << "------------------------------------------------------------";
        cout << "\nEnter Last Name: ";
        cin.sync();
        getline(cin,temp);
        if(!h.CheckValidtyOfString(temp))
        {
            cout << "------------------------------------------------------------";
            cout << "\nFound an error in your string\n";
        }
    }while(!h.CheckValidtyOfString(temp));

    temp[0] = toupper(temp[0]);
    cs.setLast(temp);
    temp = "";

    do{
        cout << "------------------------------------------------------------";
        cout << "\nEnter the Gender: ";
        cin.sync();
        getline(cin,temp);
        h.Tolower(temp);
        if(!h.CheckValidtyOfString(temp) || (temp != "male" && temp != "female"))
        {
            cout << "------------------------------------------------------------";
            cout << "\nFound an error in your string\n";
        }
    }while(!h.CheckValidtyOfString(temp) || (temp != "male" && temp != "female"));

    cs.setgender(temp);

    cout << "------------------------------------------------------------";
    cout << "\nEnter the birth year of the Computerscientist: ";

    cin.sync();
    while(!(cin >> bdaytemp) || (bdaytemp < 0 || bdaytemp > 2015))
    {
        cin.clear();
        cin.ignore(1);
        cout << "------------------------------------------------------------";
        cout << "\nError: Expected integer OR value is below 0\n";
        cout << "------------------------------------------------------------";
        cout << "\nEnter the birth year of the Computerscientist: ";
    }

    cs.setbday(bdaytemp);


    cout << "------------------------------------------------------------";
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
        cout << "------------------------------------------------------------";
        cout << "\nError Expected integer OR less than birth year\n";
        cout << "------------------------------------------------------------";
        cout << "\nEnter the death year of the Computerscientist: ";
    }
        cs.setdday(dday);

    if(d.AddComputerScientist(cs))
    {
        cout << "------------------------------------------------------------";
        cout << "\nComputerScientist has been added to the database!\n";
    }
    else
    {
        cout << "------------------------------------------------------------";
        cout << "\nAn unexpected error occurred Data has not been added";
    }

    MainMenu();
}

//---------------  Editing functions  ---------------//     //EDF


void ScientistUI::EditCS()
{
    string str;
    int id = 0;
    bool valid = false;
    vector<ComputerScientist> allcs = d.GetComputerScientist("id",0);
    scientistTable(allcs);
    do
    {
        cin.sync();
        cout << "Enter an ID to overwrite: ";
        getline(cin,str);
        if(h.ValidNumber(str))
        {
            id = stoi(str);
            if(h.ValidCSId(allcs,id))
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

    string tempfirst = "";
    int bdaytemp = -1, dday = -1;
    cout << "------------------------------------------------------------";
    cout << "\nTo edit the scientist please fill in all the fields.\n";

    do{
        cout << "------------------------------------------------------------";
        cout << "\nEnter First Name: ";
        cin.sync();
        getline(cin,tempfirst);
        if(!h.CheckValidtyOfString(tempfirst))
        {
            cout << "------------------------------------------------------------";
            cout << "\nFound an error in your string\n";
        }
    }while(!h.CheckValidtyOfString(tempfirst));

    tempfirst[0] = toupper(tempfirst[0]);
    string  tempmid;

    do{
        cout << "------------------------------------------------------------";
        cout << "\nEnter Middle Name (Type NULL if it's empty): ";
        cin.sync();
        getline(cin,tempmid);
        if(!h.CheckValidtyOfString(tempmid))
        {
            cout << "------------------------------------------------------------";
            cout << "\nFound an error in your string\n";
        }
    }while(!h.CheckValidtyOfString(tempmid));

    h.Tolower(tempmid);
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
        cout << "------------------------------------------------------------";
        cout << "\nEnter Last Name: ";
        cin.sync();
        getline(cin,tmplast);
        if(!h.CheckValidtyOfString(tmplast))
        {
            cout << "------------------------------------------------------------";
            cout << "\nFound an error in your string\n";
        }
    }while(!h.CheckValidtyOfString(tmplast));

    tmplast[0] = toupper(tmplast[0]);
    string tempgender;

    do{
        cout << "------------------------------------------------------------";
        cout << "\nEnter the Gender: ";
        cin.sync();
        getline(cin,tempgender);
        h.Tolower(tempgender);
        if(!h.CheckValidtyOfString(tempgender) || (tempgender != "male" && tempgender != "female"))
        {
            cout << "------------------------------------------------------------";
            cout << "\nFound an error in your string\n";
        }
    }while(!h.CheckValidtyOfString(tempgender) || (tempgender != "male" && tempgender != "female"));

    cout << "------------------------------------------------------------";
    cout << "\nEnter the birth year of the Computerscientist: ";

    cin.sync();
    while(!(cin >> bdaytemp) || (bdaytemp < 0 || bdaytemp > 2015))
    {
        cin.clear();
        cin.ignore(1);
        cout << "------------------------------------------------------------";
        cout << "\nError: Expected integer OR value is below 0\n";
        cout << "------------------------------------------------------------";
        cout << "\nEnter the birth year of the Computerscientist: ";
    }

    cout << "------------------------------------------------------------";
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
        cout << "------------------------------------------------------------";
        cout << "\nError Expected integer OR less than birth year\n";
        cout << "------------------------------------------------------------";
        cout << "\nEnter the death year of the Computerscientist: ";
    }

    if(d.UpdateCS(QString::fromStdString(tempfirst),QString::fromStdString(tempmid),
                  QString::fromStdString(tmplast),QString::fromStdString(tempgender),bdaytemp,dday,id))
    {
        cout << "------------------------------------------------------------";
        cout << "\nComputerScientist id: " << id << " has been edited!";
    }
    else
    {
        cout << "------------------------------------------------------------";
        cout << "\nAn unexpected error occurred Data has not been added";
    }
    MainMenu();
}

//---------------  Linking menu ---------------//           //LMQ

void UI::LinkMenu()
{
    cin.sync();
    vector<ComputerScientist> cstemp = d.GetCSInnerJoin();
    vector<Computer> computertemp = c.GetComputerInnerJoin();
    vector<int> rowid = d.GetRowID();

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
                    cout << "------------------------------------------------------------";
                    cout << "\nThese are not the Row-ID's we are looking for\n";
                }

                cout << "------------------------------------------------------------";
                cout << "\nEnter a ID of a row to delete: ";
                cin.sync();
                getline(cin,tmp);
                if(h.ValidNumber(tmp))
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
            if(d.DeleteLink(choice))
            {
                cout << "------------------------------------------------------------";
                cout << "\nDelete successful\n";
            }
            else
            {
                cout << "------------------------------------------------------------";
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
            vector<ComputerScientist> temp = d.GetComputerScientist("id",0);
            bool valid = false;
            scientistTable(temp);
            do
            {
                cout << "------------------------------------------------------------";
                cout << "\nEnter an ID to LINK: ";
                cin.sync();
                getline(cin,str);
                if(h.ValidNumber(str))
                {
                    cs = stoi(str);
                    if(!h.ValidCSId(temp,cs))
                    {
                        cout << "------------------------------------------------------------";
                        cout << "\nNo computer matching that ID.\n";
                    }
                    else
                    {
                        valid = true;
                    }
                }
                else
                {
                    cout << "------------------------------------------------------------";
                    cout << "\nError: Unexpect input in baggage area\n";
                    cs = 0;
                }
            }while(!valid);
            vector<Computer> tmp = c.GetComputers("id",0);
            valid = false;
            cs.computerTable(tmp);
            do
            {
                cout << "------------------------------------------------------------";
                cout << "\nEnter an ID to LINK: ";
                cin.sync();
                getline(cin,str);
                if(h.ValidNumber(str))
                {
                    comp = stoi(str);
                    if(!h.ValidComputerId(tmp,comp))
                    {
                        cout << "------------------------------------------------------------";
                        cout << "\nNo computer matching that ID.\n";
                    }
                    else
                    {
                        valid = true;
                    }
                }
                else
                {
                    cout << "------------------------------------------------------------";
                    cout << "\Error: Unexpect input in baggage area\n";
                    comp = 0;
                }
            }while(!valid);
            if(d.AddLink(cs,comp))
            {
                cout << "------------------------------------------------------------";
                cout << "\n\nSuccessfully linked ComputerScientist & Computer.\n";
            }
            else
            {
                cout << "------------------------------------------------------------";
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
*/
