#include "deletelink.h"
#include "ui_deletelink.h"

DeleteLink::DeleteLink(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteLink)
{
    ui->setupUi(this);

    d.connect();

    vector<ComputerScientist> cssinner = d.GetCSInnerJoin();
    vector<Computer> compinner = d.GetComputerInnerJoin();
    vector<int> rowid = d.GetRowID();
    showLink(cssinner, compinner, rowid);
}

DeleteLink::~DeleteLink()
{
    delete ui;
}

void DeleteLink::showLink(vector<ComputerScientist>& cssinner, vector<Computer>& compinner, vector<int>& rowid)
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
