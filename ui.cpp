#include "ui.h"

using namespace std;

UI::UI()
{

}

void UI::clrscr()
{
    cout << string(50,'\n');
}

void UI::InitializeUI()
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
         << "|________________________________________________|\n\n\n";
    cout << "Loading Databank from file...\n"
         << "Populating Databank with CSV file.\n";
            Mainframe.PopulateWithCSV();
}

void UI::MainMenu()
{
    cout << "1. Add to Databank.\n"
         << "2. Delete from Databank.\n"
         << "3. View contents of Databank.\n"
         << "4. Search in Databank.\n"
         << "Enter your choice: ";
    char choice;
    bool valid = false;
    do
    {
        valid = false;
        cin >> choice;
        if(choice == '1' || choice == '2' || choice == '3' || choice == '4')
        {
            valid = true;
        }
        else
        {
            cout << "Please Enter a valid choice: ";
        }
    }while(valid == false);
    switch(choice)
    {
        case '1':
        {
            addUI();
            break;
        }
        case '2':
        {
            deleteUI();
            break;
        }
        case '3':
        {
            displayUI();
            break;
        }
        case '4':
        {
            searchUI();
            break;
        }
    default: cout << "how did you even get here?"; break;
    }
}

void UI::Print(vector<ComputerScientist> css)
{
    unsigned int tempsize = 0;
    for(unsigned int i = 0; i < css.size(); i++)
    {
        if(css[i].getName().size() > tempsize)
        {
            tempsize = css[i].getName().size();
        }
    }
    cout << "index\t";
    cout << left << setw(tempsize) << "Name" << "\t";
    cout << "BDay" << "\t" << "Dday" << "\t" << "Gender\n";
    for(unsigned int i = 0; i < css.size(); i++)
    {
        cout << i+1 << "\t";
        cout << left << setw(tempsize) << css[i].getName() << "\t";
        cout << css[i].getBday() << "\t" << css[i].getDday()
             << "\t" << css[i].getGender() << endl;
    }
}

void UI::addUI()
{
    string tmpname;
    string tmpbday;
    string tmpdday;
    string tmpgender;
    cout << "Enter the name of the person you would like to add: ";
    cin.ignore();
    getline (cin, tmpname);
    bool valid = false;

    do
    {
        cout << "Enter his/her birth year(Example 1999): ";
        cin >> tmpbday;
        valid = false;
        if(stoi(tmpbday) >= 0 && stoi(tmpbday) <= 2015)
        {
            valid = true;
        }
        else
        {
            cout << "Wow we have a timetraveler?.\n";
        }
    }while(valid == false);

    do
    {
        cout << "Enter his/her year of Death.\n"
                "Type NA in caps if he has not died yet(Example 1999): ";
        cin >> tmpdday;
        valid = false;
        if(tmpdday == "NA")
        {
            valid = true;
        }
        else if(stoi(tmpdday) >= 0 && stoi(tmpdday) <= 2015 && (stoi(tmpdday) > stoi(tmpbday)))
        {
            valid = true;
        }
        else
        {
            cout << "Wow we have a timetraveler?.\n";
        }
    }while(valid == false);

    do
    {
        cout << "Enter his/her Gender (Male/Female): ";
        cin >> tmpgender;
        valid = false;
        if(tmpgender == "Male" || tmpgender == "male" || tmpgender == "Female" || tmpgender == "female")
        {
            valid = true;
        }
        else
        {
            cout << "I dont know the gender you're trying to enter.\n";
        }
    }while(valid == false);


    Mainframe.AddToDataBank(tmpname,tmpbday,tmpdday,tmpgender);
    cout << tmpname << ", " << tmpbday << ", " << tmpdday << ", and " << tmpgender << " was added to DataBank\n";
}

void UI::deleteUI()
{
    Print(Mainframe.GetDataBank());
    cout << "\nThis is the unsorted Databank, please select a index to delete: ";
    int temp;
    while(!(cin >> temp))
    {
        cin.clear();
        cin.ignore(1);
        cout << "Expected integer fatal error, just joking, please select an integer: ";
    }
    bool valid = false;
    do
    {
        if(temp > 0 && static_cast<unsigned>(temp) <= Mainframe.GetDataBank().size())
        {
            valid = true;
        }
        else
        {
            cout << "Please Select an integer that is within index range: ";
            cin >> temp;
        }
    }while(valid == false);
    Mainframe.DeleteFromDataBank(temp);
    cout << "\n ComputerScientist at index " << temp << " successfully deleted!\n";
}

void UI::displayUI()
{
    cout << "How would you like to sort the DataBank?\n"
         << "\nn/N(Primary sort name, no secondary sort)\n"
         << "g/G(Primary sort gender, secondary sort name)\n"
         << "b/B(Primary sort birth year, secondary sort name)\n"
         << "d/D(Primary sort death year, secondary sort name)\n"
         << "\nEnter one of the above letters to choose your sorting method: ";
    char temp;
    bool valid = false;
    do{
        valid = false;
        cin >> temp;
        if(temp == 'n' || temp == 'N' || temp == 'g' ||temp == 'G' ||
           temp == 'b' || temp == 'B' || temp == 'd' || temp == 'D')
        {
            char tmp;
            DataManipulation d1;
            d1.Update(Mainframe);
            cout << "Do you wish to sort it in reverse order y/Y: ";
            cin >> tmp;
            if(tmp == 'y' || tmp == 'Y')
            {
                d1.sortChoice(temp, 'y');
            }
            else
            {
                d1.sortChoice(temp,'n');
            }
            cout << "\n";
            Print(d1.ReturnVector());
            valid = true;
        }
        else
        {
            cout << "Please enter one of the options: ";
        }
    }while(valid == false);
}

void UI::searchUI()
{
    cout << "\nPlease choice a searching method!\n"
         << "1. Exact Search(String Search)\n"
         << "2. Partial Search (Substring Search)\n"
         << "Enter your choice here: ";
    char choice;
    bool valid = false;
    do
    {
        valid = false;
        cin >> choice;
        if(choice == '1' || choice == '2')
        {
            cout << "Enter a Search string: ";
            string search;
            cin >> search;
            bool found = false;
            DataManipulation d1;
            d1.Update(Mainframe);
            if(choice == '1')
            {
                found = d1.Search(search);
            }
            else
            {
                found = d1.substringSearch(search);
            }

            if(found == true)
            {
                d1.sortChoice('n','n');
                Print(d1.ReturnVector());
            }
            else
            {
                cout << "Nothing of value was found!!";
            }
            valid = true;
        }
        else
        {
            cout << "That's not a valid choice and you know it!!\n"
                 << "Please Enter a valid choice this time: ";
        }
    }while(valid == false);
}
