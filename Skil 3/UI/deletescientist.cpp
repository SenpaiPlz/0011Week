#include "deletescientist.h"
#include "ui_deletescientist.h"

DeleteScientist::DeleteScientist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteScientist)
{
    ui->setupUi(this);

    d.connect();

    vector<ComputerScientist> css = d.GetComputerScientist("first_name",false);
    showCS(css);
}

DeleteScientist::~DeleteScientist()
{
    delete ui;
}

void DeleteScientist::showCS(vector<ComputerScientist>& css)
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
