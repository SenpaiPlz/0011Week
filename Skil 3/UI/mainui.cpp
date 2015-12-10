/*#include "mainui.h"

MainUI::MainUI()
{

}

UI::UI()
{
    cout << "############ PARSING SQL FILE AND CONNECTING TO DATABASE ############\n\n";
    ScientistUI d;
    ComputerUI c;
    InitialMenu();
}

void MainUI::InitialMenu()
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
            "\t    <<    amazing Computer Scientists and the      >>\n"
            "\t    <<  Computers they built that have changed the >>\n"
            "\t    <<  world as we know it with their inventions. >>\n\n"
            "\t    Do Note: We allow you to enter as long of a string as\n"
            "\t    You would like, A first and middle name of length 12\n"
            "\t    or greater will likelly not fit in cmd. Be warned!\n";

    MainMenu();
}

void MainUI::MainMenu()
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
        case '1': {ds.SortScientistMenu(); break;}
        case '2': {cs.SortComputerMenu(); break;}
        case '3': {ds.AddComputerScientist(); break;}
        case '4': {ds.EditCS(); break;}
        case '5': {cs.AddComputer(); break;}
        case '6': {cs.EditComputer(); break;}
        case '7': {ds.LinkMenu(); break;}
        case '8': {SearchMenu(); break;}
        case '9': {DeleteMenu(); break;}
        case '0': {exit(0); break;}
        default: break;
        }
    }
}

//---------------  Search menu  ---------------//       //SEM

void MainUI::SearchMenu()
{
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

            vector<ComputerScientist> list = d.GetComputerScientist("id",0);
            string str;
            bool valid = false;
            do{
                cout << "------------------------------------------------------------";
                cout << "\nEnter any info you have on your beloved Scientist: ";
                cin.sync();
                getline(cin, str);
                if(str.empty())
                {
                    ds.scientistTable(list);
                    cout << "------------------------------------------------------------";
                    cout << "\nWrite out any info you have to find it in the list.\n";
                }

                else
                {
                    valid = true;
                }

            }while(!valid);

            QString newstr = QString::fromUtf8(str.c_str());
            vector<ComputerScientist> tmp = d.SearchCS(newstr);
            ds.scientistTable(tmp);
            cout << "------------------------------------------------------------";
            cout << "\nPress ENTER to go back to SEARCH MENU.";

            SearchMenu();
            break;
        }
        case '2':
        {
            int stoitemp = 0;
            vector<ComputerScientist> list = d.GetComputerScientist("id",0);
            string str;
            bool valid = false;
            do{
                cout << "------------------------------------------------------------";
                cout << "\nEnter Scientist ID: ";
                cin.sync();
                getline(cin, str);
                if(str.empty())
                {
                    ds.scientistTable(list);
                    cout << "------------------------------------------------------------";
                    cout << "\nChoose an ID from the list.\n";
                }
                else if(h.ValidNumber(str))
                {
                    stoitemp = stoi(str);
                    if(!h.ValidCSId(list,stoitemp))
                    {
                        cout << "------------------------------------------------------------";
                        cout << "\nNo scientist with that ID.\n";
                    }
                    else
                    {
                        valid = true;
                    }
                }
                else
                {
                    cout << "------------------------------------------------------------";
                    cout << "\nError: Unexpected input.\n";
                    stoitemp = 0;
                }

            }while(!valid);
            //Need to be able to show only nr. 1, not all with 1 in them...

            vector<ComputerScientist> tmp = d.SearchCSID(stoitemp);
            ds.scientistTable(tmp);
            cout << "------------------------------------------------------------";
            cout << "\nPress ENTER to go back to SEARCH MENU.";

            SearchMenu();
            break;
        }
        case '3':
        {
            vector<Computer> list = c.GetComputers("id",0);
            string str;
            bool valid = false;
            do{
                cout << "------------------------------------------------------------";
                cout << "\nEnter any info you have on a Computer: ";
                cin.sync();
                getline(cin, str);
                if(str.empty())
                {
                    cs.computerTable(list);
                    cout << "------------------------------------------------------------";
                    cout << "\nWrite out any info you have to find it in the list.\n";
                }

                else
                {
                    valid = true;
                }

            }while(!valid);

            QString newstr = QString::fromUtf8(str.c_str());
            vector<computersabstract> tmp = c.SearchComputer(newstr);
            cs.computerTable(tmp);
            cout << "------------------------------------------------------------";
            cout << "\nPress ENTER to go back to SEARCH MENU.";

            SearchMenu();
            break;
        }
        case '4':
        {
            int stoitemp = 0;
            vector<Computer> list = c.GetComputers("id",0);
            string str;
            bool valid = false;
            do{
                cout << "------------------------------------------------------------";
                cout << "\nEnter Computer ID: ";
                cin.sync();
                getline(cin, str);
                if(str.empty())
                {
                    cs.computerTable(list);
                    cout << "------------------------------------------------------------";
                    cout << "\nChoose an ID from the list.\n";
                }
                else if(h.ValidNumber(str))
                {
                    stoitemp = stoi(str);
                    if(!h.ValidComputerId(list,stoitemp))
                    {
                        cout << "------------------------------------------------------------";
                        cout << "\nNo computer with that ID.\n";
                    }
                    else
                    {
                        valid = true;
                    }
                }
                else
                {
                    cout << "------------------------------------------------------------";
                    cout << "\nError: Unexpected input.\n";
                    stoitemp = 0;
                }

            }while(!valid);
            //Need to be able to show only nr. 1, not all with 1 in them...

            vector<Computer> tmp = c.SearchComputerID(stoitemp);

            cs.computerTable(tmp);

            cout << "------------------------------------------------------------";
            cout << "\nPress ENTER to go back to SEARCH MENU.";

            SearchMenu();
            break;
        }
        case '0': {MainMenu(); break;}
        default: {cout << "Invalid choice\n---------------------------------------------------\nPress ENTER for Search Menu!"; SearchMenu(); break;}
        }
    }
}

//---------------  Deletion menu  ---------------//     //DEM

void MainUI::DeleteMenu()
{
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
            vector<ComputerScientist> temp = d.GetComputerScientist("id",0);
            ds.scientistTable(temp);
            do
            {
                cout << "------------------------------------------------------------";
                cout << "\nEnter an ID to Mark: ";
                cin.sync();
                getline(cin,tmp);
                if(h.ValidNumber(tmp))
                {
                    stoitemp = stoi(tmp);
                    if(!h.ValidCSId(temp,stoitemp))
                    {
                        cout << "------------------------------------------------------------";
                        cout << "\nNo scientist matching that ID.\n";
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
                    stoitemp = 0;
                }
            }while(!valid);

            if(d.MarkDeleted("scientists",stoitemp))
            {
                cout << "------------------------------------------------------------";
                cout << "\nMarked ID: " << stoitemp << " for deletion\n";
                cout << "------------------------------------------------------------";
                cout << "\nPress ENTER to go back to DELETE MENU.";
            }
            else
            {
                cout << "------------------------------------------------------------";
                cout << "\nERROR: something went wrong here.\n";
                cout << "------------------------------------------------------------";
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
            vector<ComputerScientist> temp = d.GetDeletedCS();
            ds.scientistTable(temp);
            do
            {
                cout << "------------------------------------------------------------";
                cout << "\nEnter an ID to Un-Mark: ";
                cin.sync();
                getline(cin,tmp);
                if(h.ValidNumber(tmp))
                {
                    stoitemp = stoi(tmp);
                    if(!h.ValidCSId(temp,stoitemp))
                    {
                        cout << "------------------------------------------------------------";
                        cout << "\nNo scientist matching that ID.\n";
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
                    stoitemp = 0;
                }
            }while(!valid);

            if(d.UnmarkDeleted("scientists",stoitemp))
            {
                cout << "------------------------------------------------------------";
                cout << "\nUn-Marked ID: " << stoitemp << " for deletion\n";
                cout << "------------------------------------------------------------";
                cout << "\nPress ENTER to go back to DELETE MENU.";
            }
            else
            {
                cout << "------------------------------------------------------------";
                cout << "\nERROR: something went wrong here.\n";
                cout << "------------------------------------------------------------";
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
            vector<Computer> temp = c.GetComputers("id",0);
            cs.computerTable(temp);
            do
            {
                cout << "------------------------------------------------------------";
                cout << "\nEnter an ID to Mark: ";
                cin.sync();
                getline(cin,tmp);
                if(h.ValidNumber(tmp))
                {
                    stoitemp = stoi(tmp);
                    if(!h.ValidComputerId(temp,stoitemp))
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
                    stoitemp = 0;
                }
            }while(!valid);

            if(d.MarkDeleted("computers",stoitemp))
            {
                cout << "------------------------------------------------------------";
                cout << "\nMarked ID: " << stoitemp << " for deletion\n";
                cout << "------------------------------------------------------------";
                cout << "\nPress ENTER to go back to DELETE MENU.";
            }
            else
            {
                cout << "------------------------------------------------------------";
                cout << "\nERROR: something went wrong here.\n";
                cout << "------------------------------------------------------------";
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
            vector<Computer> temp = c.GetDeletedComputers();
            cs.computerTable(temp);
            do
            {
                cout << "------------------------------------------------------------";
                cout << "\nEnter an ID to Un-Mark: ";
                cin.sync();
                getline(cin,tmp);
                if(h.ValidNumber(tmp))
                {
                    stoitemp = stoi(tmp);
                    if(!h.ValidComputerId(temp,stoitemp))
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
                    stoitemp = 0;
                }
            }while(!valid);

            if(d.UnmarkDeleted("computers",stoitemp))
            {
                cout << "------------------------------------------------------------";
                cout << "\nUn-Marked ID: " << stoitemp << " for deletion\n";
                cout << "------------------------------------------------------------";
                cout << "\nPress ENTER to go back to DELETE MENU.";
            }
            else
            {
                cout << "------------------------------------------------------------";
                cout << "\nERROR: something went wrong here.\n";
                cout << "------------------------------------------------------------";
                cout << "\nPress ENTER to go back to DELETE MENU.";
            }
            DeleteMenu();
            break;
        }
        case '5':
        {
            vector<ComputerScientist> temp = d.GetDeletedCS();
            ds.scientistTable(temp);
            cout << "------------------------------------------------------------";
            cout << "\nPress ENTER to continue";
            DeleteMenu();
            break;
        }
        case '6':
        {
            vector<Computer> temp = c.GetDeletedComputers();
            cs.computerTable(temp);
            cout << "------------------------------------------------------------";
            cout << "\nPress ENTER to continue";
            DeleteMenu();
            break;
        }
        case '7':
        {
            if(d.DeleteAllMarked())
            {
                cout << "\n######  DELETING ALL MARKED  ######\n";
            }
            else
            {
                cout << "------------------------------------------------------------";
                cout << "\nSomething went wrong\n";
            }
            cout << "------------------------------------------------------------";
            cout << "\nPress ENTER to go back to DELETE MENU.";
            DeleteMenu();
            break;
        }
        case '0': {MainMenu(); break;}
        default: {cout << "Invalid choice\n"; cin.sync(); break;}
        }
    }
}
*/
