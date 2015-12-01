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
            break;
        }
        case '3':
        {
            break;
        }
        case '4':
        {
            break;
        }
    default: cout << "how did you even get here?"; break;
    }
}

void UI::printData(vector<ComputerScientist> css)
{
    for(size_t i = 0; i != css.size(); i++)
    {
        cout << css[i].getName() << "\t" << css[i].getGender() << "\t" <<
                css[i].getBday() << "\t" << css[i].getDday() << endl;
    }
}

void UI::addUI()
{
    printData(Mainframe.GetDataBank());
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
        else if(stoi(tmpdday) >= 0 && stoi(tmpdday) <= 2015)
        {
            valid = true;
        }
        else
        {
            cout << "Wow we have a timetraveler?.\n";
        }
    }while(valid == false);
    Mainframe.AddToDataBank(tmpname,tmpbday,tmpdday,tmpgender);
    printData(Mainframe.GetDataBank());
}
