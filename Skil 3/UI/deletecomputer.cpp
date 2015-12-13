#include "deletecomputer.h"
#include "ui_deletecomputer.h"

DeleteComputer::DeleteComputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteComputer)
{
    ui->setupUi(this);

    d.connect();

    vector<Computer> computer = d.GetComputers("name",false);
    showComputer(computer);
}

DeleteComputer::~DeleteComputer()
{
    delete ui;
}

void DeleteComputer::showComputer(vector<Computer>& computer)
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
