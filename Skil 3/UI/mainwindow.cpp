#include "UI/mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    d.connect();
    ui->setupUi(this);
    //Initial Setup
    QMainWindow::showMaximized();
    Keybinds();

    ui->SELECT_TABLE->addItem("Computer Scientists");
    ui->SELECT_TABLE->addItem("Computers");
    ui->SELECT_TABLE->addItem("Link between computers and scientists");

    //Create a custom context menu
    ui->MainTable->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->MainTable, SIGNAL(customContextMenuRequested(const QPoint&)),
            this, SLOT(on_MainTable_ShowContextMenu(const QPoint&)));

    displayAll(GetCurrentTable());
}

MainWindow::~MainWindow()
{
    delete ui;
}


//----------    Display Functions    ----------//

void MainWindow::displayAll(int index)
{
    //Index refers to which table is active determined by GetCurrentTable
    /* 1 = cs
     * 2 = computers
     * 3 = linking
     */

    if(index == 1)
    {
        vector<ComputerScientist> css = d.GetComputerScientist("first_name",false);
        displayCS(css);
    }
    else if(index == 2)
    {
        vector<Computer> computer = d.GetComputers("name",false);
        displayComputer(computer);
    }
    else if(index == 3)
    {
        vector<ComputerScientist> cssinner = d.GetCSInnerJoin();
        vector<Computer> compinner = d.GetComputerInnerJoin();
        vector<int> rowid = d.GetRowID();
        displayLink(cssinner, compinner, rowid);
    }
}

void MainWindow::displayCS(vector<ComputerScientist>& css)
{
    ui->MainTable->setSortingEnabled(false);

    ui->MainTable->clearContents();
    ui->MainTable->setColumnCount(7);
    ui->MainTable->setRowCount(css.size());

    ui->MainTable->setHorizontalHeaderItem(0,new QTableWidgetItem(QString("Id")));
    ui->MainTable->setHorizontalHeaderItem(1,new QTableWidgetItem(QString("First Name")));
    ui->MainTable->setHorizontalHeaderItem(2,new QTableWidgetItem(QString("Middle Name")));
    ui->MainTable->setHorizontalHeaderItem(3,new QTableWidgetItem(QString("Last Name")));
    ui->MainTable->setHorizontalHeaderItem(4,new QTableWidgetItem(QString("Gender")));
    ui->MainTable->setHorizontalHeaderItem(5,new QTableWidgetItem(QString("Birth Year")));
    ui->MainTable->setHorizontalHeaderItem(6,new QTableWidgetItem(QString("Death Year")));

    for(size_t i = 0; i < css.size(); i++)
    {
        ComputerScientist temp = css[i];

        //We use set data for numbers so that the sort works properly i.e 1,2,3 instead of 1,10,11.
        QTableWidgetItem* id = new QTableWidgetItem;
        QTableWidgetItem* yearborn = new QTableWidgetItem;
        QTableWidgetItem* yeardied = new QTableWidgetItem;
        id->setData(Qt::DisplayRole,temp.getID());
        yearborn->setData(Qt::DisplayRole,temp.getBday());
        yeardied->setData(Qt::DisplayRole,temp.getDday());

        ui->MainTable->setItem(i,0, id);
        ui->MainTable->setItem(i,1, new QTableWidgetItem(QString::fromStdString(temp.getFirst())));
        ui->MainTable->setItem(i,2, new QTableWidgetItem(QString::fromStdString(temp.getMid())));
        ui->MainTable->setItem(i,3, new QTableWidgetItem(QString::fromStdString(temp.getLast())));
        ui->MainTable->setItem(i,4, new QTableWidgetItem(QString::fromStdString(temp.getGender())));
        ui->MainTable->setItem(i,5, yearborn);
        if(temp.getDday() != 0)
        {
            ui->MainTable->setItem(i,6, yeardied);
        }
        else
        {
            ui->MainTable->setItem(i,6,new QTableWidgetItem(QString("Alive")));
        }
    }

    ui->MainTable->setSortingEnabled(true);
}

void MainWindow::displayComputer(vector<Computer>& computer)
{
    ui->MainTable->setSortingEnabled(false);

    ui->MainTable->clearContents();
    ui->MainTable->setColumnCount(5);
    ui->MainTable->setRowCount(computer.size());

    ui->MainTable->setHorizontalHeaderItem(0,new QTableWidgetItem(QString("id")));
    ui->MainTable->setHorizontalHeaderItem(1,new QTableWidgetItem(QString("Name")));
    ui->MainTable->setHorizontalHeaderItem(2,new QTableWidgetItem(QString("Year")));
    ui->MainTable->setHorizontalHeaderItem(3,new QTableWidgetItem(QString("Type")));
    ui->MainTable->setHorizontalHeaderItem(4,new QTableWidgetItem(QString("Built")));

    for(size_t i = 0; i < computer.size(); i++)
    {
        Computer temp = computer[i];

        //We use set data for numbers so that the sort works properly i.e 1,2,3 instead of 1,10,11.
        QTableWidgetItem* id = new QTableWidgetItem;
        id->setData(Qt::DisplayRole,temp.getID());

        ui->MainTable->setItem(i,0, id);
        ui->MainTable->setItem(i,1, new QTableWidgetItem(QString::fromStdString(temp.getName())));
        ui->MainTable->setItem(i,2, new QTableWidgetItem(QString::number(temp.getYear())));
        ui->MainTable->setItem(i,3, new QTableWidgetItem(QString::fromStdString(temp.getType())));
        ui->MainTable->setItem(i,4, new QTableWidgetItem(QString::number(temp.getBuilt())));
    }

    ui->MainTable->setSortingEnabled(true);
}

void MainWindow::displayLink(vector<ComputerScientist>& cssinner, vector<Computer>& compinner, vector<int>& rowid)
{
    ui->MainTable->setSortingEnabled(false);

    ui->MainTable->clearContents();
    ui->MainTable->setColumnCount(5);
    ui->MainTable->setRowCount(cssinner.size());

    ui->MainTable->setHorizontalHeaderItem(0,new QTableWidgetItem(QString("CS name")));
    ui->MainTable->setHorizontalHeaderItem(1,new QTableWidgetItem(QString("CS_id")));
    ui->MainTable->setHorizontalHeaderItem(2,new QTableWidgetItem(QString("Computer_id")));
    ui->MainTable->setHorizontalHeaderItem(3,new QTableWidgetItem(QString("Computer name")));
    ui->MainTable->setHorizontalHeaderItem(4,new QTableWidgetItem(QString("Row_id")));

    for(size_t i = 0; i < cssinner.size(); i++)
    {
        //combine the name into a single string
        QString csname = QString::fromStdString(cssinner[i].getFirst()) + " "
                + QString::fromStdString(cssinner[i].getMid()) + " "
                + QString::fromStdString(cssinner[i].getLast());

        //We use set data for numbers so that the sort works properly i.e 1,2,3 instead of 1,10,11.
        QTableWidgetItem* roid = new QTableWidgetItem;
        QTableWidgetItem* csid = new QTableWidgetItem;
        QTableWidgetItem* compid = new QTableWidgetItem;
        roid->setData(Qt::DisplayRole, rowid[i]);
        csid->setData(Qt::DisplayRole, cssinner[i].getID());
        compid->setData(Qt::DisplayRole, compinner[i].getID());

        ui->MainTable->setItem(i,0, new QTableWidgetItem(csname));
        ui->MainTable->setItem(i,1, csid);
        ui->MainTable->setItem(i,2, compid);
        ui->MainTable->setItem(i,3, new QTableWidgetItem(QString::fromStdString(compinner[i].getName())));
        ui->MainTable->setItem(i,4, roid);
    }

    ui->MainTable->setSortingEnabled(true);
}


//----------    SELECT TABLE combobox    ----------//


void MainWindow::on_SELECT_TABLE_currentIndexChanged()
{
    //clear filter, disable filter if on link table, refresh tables
    ui->Filter->clear();
    ui->Filter->setEnabled(true);
    if(GetCurrentTable() == 3)
    {
        ui->Filter->setEnabled(false);
    }
    displayAll(GetCurrentTable());
}

int MainWindow::GetCurrentTable()
{
    string temp = ui->SELECT_TABLE->currentText().toStdString();

    if(temp == "Computer Scientists")
    {
        return 1;
    }
    else if(temp == "Computers")
    {
        return 2;
    }
    else if(temp == "Link between computers and scientists")
    {
        return 3;
    }
    return 1;
}


//----------    Filter Line Edit    ----------//

void MainWindow::on_Filter_textChanged()
{
    QString userinput = ui->Filter->text();
    if(GetCurrentTable() == 1)
    {
        vector<ComputerScientist> css = d.SearchCS(userinput);
        displayCS(css);
    }
    else if(GetCurrentTable() == 2)
    {
        vector<Computer> computer = d.SearchComputer(userinput);
        displayComputer(computer);
    }
}


//----------    Add dropdown triggers    ----------//


void MainWindow::on_actionAdd_Computer_Scientist_triggered()
{
    Add_Scientist add;
    add.exec();
    ui->Filter->clear();
    displayAll(GetCurrentTable());
}

void MainWindow::on_actionAdd_Computer_triggered()
{
    add_computer add;
    add.exec();
    ui->Filter->clear();
    displayAll(GetCurrentTable());
}

void MainWindow::on_actionAdd_Link_triggered()
{
    AddLink add;
    add.exec();
    ui->Filter->clear();
    displayAll(GetCurrentTable());
}


//----------    Delete dropdown triggers    ----------//


void MainWindow::on_actionDelete_Scientists_triggered()
{
    DeleteScientist deleteScientist;
    deleteScientist.exec();
    ui->Filter->clear();
    displayAll(GetCurrentTable());
}

void MainWindow::on_actionDelete_Computers_triggered()
{
    DeleteComputer deleteComputer;
    deleteComputer.exec();
    ui->Filter->clear();
    displayAll(GetCurrentTable());
}

void MainWindow::on_actionDelete_Link_triggered()
{
    DeleteLink deleteLink;
    deleteLink.exec();
    ui->Filter->clear();
    displayAll(GetCurrentTable());
}


//----------    Edit dropdown triggers    ----------//


void MainWindow::on_actionEdit_ComputerScientist_triggered()
{
    EditScientist edit;
    edit.exec();
    ui->Filter->clear();
    displayAll(GetCurrentTable());
}

void MainWindow::on_actionEdit_Computer_triggered()
{
    EditComputers edit;
    edit.exec();
    ui->Filter->clear();
    displayAll(GetCurrentTable());
}


//----------    help dropdown triggers    ----------//


void MainWindow::on_actionShortcuts_triggered()
{
    QMessageBox::information(this,"Shortcuts",
    "<p><b><font size='4'><font color ='#1f5f2c'> Current Keybindings for MainWindow</font></b></p> \n\n "
    "<p><font color ='#1f5f2c'> CTRL + Q = Quit</font></p>\n\n "
    "<p><font color ='#1f5f2c'>CTRL + E = Edit Currently selected item</font></p>\n\n "
    "<p><font color ='#1f5f2c'>CTRL + A = Add Item of currently selected table</font></p>\n\n "
    "<p><font color ='#1f5f2c'>CTRL + D = Mark for deletion/Delete currently selected item</font></p>\n\n "
    "<p><font color ='#1f5f2c'>CTRL + ALT + D = Delete Menu for Computers</font></p>\n\n "
    "<p><font color ='#1f5f2c'>SHIFT + ALT + D = Delete Menu for ComputerScientists</font><p>\n\n"
    "<p><font color ='#1f5f2c'>CTRL + S = Opens Shortcut Box</font><p>\n");
}


//----------     Right Click triggers and custom context menu    ----------//

void MainWindow::on_MainTable_ShowContextMenu(const QPoint& pos)
{
    QPoint globpos = ui->MainTable->mapToGlobal(pos);

    QMenu menu;

    menu.addAction("Add",this,SLOT(Add_Triggered()));
    menu.addAction("Edit",this,SLOT(Edit_Triggered()));
    menu.addAction("Delete",this,SLOT(Delete_Triggered()));

    if(GetCurrentTable() == 3)
    {
        menu.actions().at(1)->setEnabled(false);
    }
    menu.exec(globpos);
}

void MainWindow::Add_Triggered()
{
    if(GetCurrentTable() == 1)
    {
        on_actionAdd_Computer_Scientist_triggered();
    }
    else if(GetCurrentTable() == 2)
    {
        on_actionAdd_Computer_triggered();
    }
    else if(GetCurrentTable() == 3)
    {
        on_actionAdd_Link_triggered();
    }
}


void MainWindow::Edit_Triggered()
{

    //This if sentences checks if the current index is valid. i.e it is still being selected
    //If this check does not occurr, the program will crash trying to work with the invalid index.
    //Everywhere the currentIndex().isValid() check is performed it is to prevent this crash.

    if(ui->MainTable->currentIndex().isValid())
    {
        if(GetCurrentTable() == 1)
        {
            int rowidx = ui->MainTable->selectionModel()->currentIndex().row();
            EditScientist edit;
            edit.SetID(ui->MainTable->item(rowidx,0)->text());
            edit.SetFirst(ui->MainTable->item(rowidx,1)->text());
            edit.SetMid(ui->MainTable->item(rowidx,2)->text());
            edit.SetLast(ui->MainTable->item(rowidx,3)->text());
            edit.SetGender(ui->MainTable->item(rowidx,4)->text());
            edit.SetBday(ui->MainTable->item(rowidx,5)->text());
            if(ui->MainTable->item(rowidx,6)->text() != "Alive")
            {
                edit.SetDday(ui->MainTable->item(rowidx,6)->text());
            }
            edit.exec();
        }
        else if(GetCurrentTable() == 2)
        {
            int rowidx = ui->MainTable->selectionModel()->currentIndex().row();
            EditComputers edit;
            edit.SetID(ui->MainTable->item(rowidx,0)->text());
            edit.SetName(ui->MainTable->item(rowidx,1)->text());
            edit.SetYear(ui->MainTable->item(rowidx,2)->text());
            edit.SetType(ui->MainTable->item(rowidx,3)->text());
            edit.SetBuilt(ui->MainTable->item(rowidx,4)->text().toInt());
            edit.exec();
        }
    }
    ui->Filter->clear();
    displayAll(GetCurrentTable());
}

void MainWindow::Delete_Triggered()
{
    if(ui->MainTable->selectionModel()->currentIndex().isValid())
    {
        int rowidx = ui->MainTable->selectionModel()->currentIndex().row();
        if(GetCurrentTable() == 1)
        {
            int id = ui->MainTable->item(rowidx,0)->text().toInt();
            d.MarkDeleted("scientists",id);
        }
        else if(GetCurrentTable() == 2)
        {
            int id = ui->MainTable->item(rowidx,0)->text().toInt();
            d.MarkDeleted("computers",id);
        }
        else if(GetCurrentTable() == 3)
        {
            int id = ui->MainTable->item(rowidx,4)->text().toInt();
            d.DeleteLink(id);
        }
        ui->Filter->clear();
        displayAll(GetCurrentTable());
    }
}

//----------     Misc functions/trigger    ----------//

void MainWindow::Keybinds()
{
    QShortcut* shortcut = new QShortcut(QKeySequence("ctrl+E"), this);
    connect(shortcut, SIGNAL(activated()), this, SLOT(Edit_Triggered()));
    shortcut = new QShortcut(QKeySequence("ctrl+Q"),this);
    connect(shortcut, SIGNAL(activated()), this, SLOT(quit()));
    shortcut = new QShortcut(QKeySequence("ctrl+A"),this);
    connect(shortcut, SIGNAL(activated()), this, SLOT(Add_Triggered()));
    shortcut = new QShortcut(QKeySequence("ctrl+D"), this);
    connect(shortcut, SIGNAL(activated()), this, SLOT(Delete_Triggered()));
    shortcut = new QShortcut(QKeySequence("alt+ctrl+D"),this);
    connect(shortcut, SIGNAL(activated()), this, SLOT(on_actionDelete_Computers_triggered()));
    shortcut = new QShortcut(QKeySequence("alt+shift+D"),this);
    connect(shortcut, SIGNAL(activated()), this, SLOT(on_actionDelete_Scientists_triggered()));
    shortcut = new QShortcut(QKeySequence("ctrl+S"), this);
    connect(shortcut, SIGNAL(activated()), this, SLOT(on_actionShortcuts_triggered()));
}

void MainWindow::quit()
{
    close();
}

void MainWindow::on_MainTable_doubleClicked()
{
    Edit_Triggered();
}
