#include "UI/deleteoptions.h"
#include "ui_deleteoptions.h"

DeleteOptions::DeleteOptions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteOptions)
{
    ui->setupUi(this);
    d.connect();
    ui->select_deletion->addItem("Computer Scientists");
    ui->select_deletion->addItem("Computers");
    ui->select_deletion->addItem("Link between computers and scientists");
    ShowAll(GetTables());
}

DeleteOptions::~DeleteOptions()
{
    delete ui;
}

int DeleteOptions::GetTables()
{
    string temp = ui->select_deletion->currentText().toStdString();

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

void DeleteOptions::ShowAll(int index)
{
    if(index == 1)
    {
        vector<ComputerScientist> css = d.GetComputerScientist("first_name",false);
        showCS(css);
    }
    else if(index == 2)
    {
        vector<Computer> computer = d.GetComputers("name",false);
        showComputer(computer);
    }
    else if(index == 3)
    {
        vector<ComputerScientist> cssinner = d.GetCSInnerJoin();
        vector<Computer> compinner = d.GetComputerInnerJoin();
        vector<int> rowid = d.GetRowID();
        showLink(cssinner, compinner, rowid);
    }
}

void DeleteOptions::showCS(vector<ComputerScientist>& css)
{
    ui->table_original->setSortingEnabled(false);

    ui->table_original->clearContents();
    ui->table_original->setColumnCount(6);
    ui->table_original->setRowCount(css.size());

    ui->table_original->setHorizontalHeaderItem(0,new QTableWidgetItem(QString("First Name")));
    ui->table_original->setHorizontalHeaderItem(1,new QTableWidgetItem(QString("Middle Name")));
    ui->table_original->setHorizontalHeaderItem(2,new QTableWidgetItem(QString("Last Name")));
    ui->table_original->setHorizontalHeaderItem(3,new QTableWidgetItem(QString("Gender")));
    ui->table_original->setHorizontalHeaderItem(4,new QTableWidgetItem(QString("Birth Year")));
    ui->table_original->setHorizontalHeaderItem(5,new QTableWidgetItem(QString("Death Year")));

    for(size_t i = 0; i < css.size(); i++)
    {
        ComputerScientist temp = css[i];

        ui->table_original->setItem(i,0, new QTableWidgetItem(QString::fromStdString(temp.getFirst())));
        ui->table_original->setItem(i,1, new QTableWidgetItem(QString::fromStdString(temp.getMid())));
        ui->table_original->setItem(i,2, new QTableWidgetItem(QString::fromStdString(temp.getLast())));
        ui->table_original->setItem(i,3, new QTableWidgetItem(QString::fromStdString(temp.getGender())));
        ui->table_original->setItem(i,4, new QTableWidgetItem(QString::number(temp.getBday())));
        ui->table_original->setItem(i,5, new QTableWidgetItem(QString::number(temp.getDday())));
    }

    ui->table_original->setSortingEnabled(true);
}

void DeleteOptions::showComputer(vector<Computer>& computer)
{
    ui->table_original->setSortingEnabled(false);

    ui->table_original->clearContents();
    ui->table_original->setColumnCount(4);
    ui->table_original->setRowCount(computer.size());

    ui->table_original->setHorizontalHeaderItem(0,new QTableWidgetItem(QString("Name")));
    ui->table_original->setHorizontalHeaderItem(1,new QTableWidgetItem(QString("Year")));
    ui->table_original->setHorizontalHeaderItem(2,new QTableWidgetItem(QString("Type")));
    ui->table_original->setHorizontalHeaderItem(3,new QTableWidgetItem(QString("Built")));

    for(size_t i = 0; i < computer.size(); i++)
    {
        Computer temp = computer[i];

        ui->table_original->setItem(i,0, new QTableWidgetItem(QString::fromStdString(temp.getName())));
        ui->table_original->setItem(i,1, new QTableWidgetItem(QString::number(temp.getYear())));
        ui->table_original->setItem(i,2, new QTableWidgetItem(QString::fromStdString(temp.getType())));
        ui->table_original->setItem(i,3, new QTableWidgetItem(QString::number(temp.getBuilt())));
    }

    ui->table_original->setSortingEnabled(true);
}

void DeleteOptions::showLink(vector<ComputerScientist>& cssinner, vector<Computer>& compinner, vector<int>& rowid)
{
    ui->table_original->setSortingEnabled(false);

    ui->table_original->clearContents();
    ui->table_original->setColumnCount(5);
    ui->table_original->setRowCount(cssinner.size());

    ui->table_original->setHorizontalHeaderItem(0,new QTableWidgetItem(QString("CS name")));
    ui->table_original->setHorizontalHeaderItem(1,new QTableWidgetItem(QString("CS_id")));
    ui->table_original->setHorizontalHeaderItem(2,new QTableWidgetItem(QString("Computer_id")));
    ui->table_original->setHorizontalHeaderItem(3,new QTableWidgetItem(QString("Computer name")));
    ui->table_original->setHorizontalHeaderItem(4,new QTableWidgetItem(QString("Row_id")));

    for(size_t i = 0; i < cssinner.size(); i++)
    {
        QString csname = QString::fromStdString(cssinner[i].getFirst()) + " "
                + QString::fromStdString(cssinner[i].getMid()) + " "
                + QString::fromStdString(cssinner[i].getLast());

        ui->table_original->setItem(i,0, new QTableWidgetItem(csname));
        ui->table_original->setItem(i,1, new QTableWidgetItem(QString::number(cssinner[i].getID())));
        ui->table_original->setItem(i,2, new QTableWidgetItem(QString::number(compinner[i].getID())));
        ui->table_original->setItem(i,3, new QTableWidgetItem(QString::fromStdString(compinner[i].getName())));
        ui->table_original->setItem(i,4, new QTableWidgetItem(QString::number(rowid[i])));
    }

    ui->table_original->setSortingEnabled(true);
}
