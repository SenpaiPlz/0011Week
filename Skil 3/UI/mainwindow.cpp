#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->SELECT_TABLE->addItem("CS");
    ui->SELECT_TABLE->addItem("Computer");
    ui->SELECT_TABLE->addItem("Link");

    displayAll(GetCurrentTable());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayAll(int index)
{
    if(index == 1)
    {
        displayCS();
    }
    else if(index == 2)
    {
        displayComputer();
    }
    else if(index == 3)
    {
        displayLink();
    }
}

void MainWindow::displayCS()
{
    ui->MainTable->setSortingEnabled(false);

    ui->MainTable->clearContents();
    ui->MainTable->setColumnCount(6);
    ui->MainTable->setHorizontalHeaderItem(0,new QTableWidgetItem(QString("First Name")));
    ui->MainTable->setHorizontalHeaderItem(1,new QTableWidgetItem(QString("Middle Name")));
    ui->MainTable->setHorizontalHeaderItem(2,new QTableWidgetItem(QString("Last Name")));
    ui->MainTable->setHorizontalHeaderItem(3,new QTableWidgetItem(QString("Gender")));
    ui->MainTable->setHorizontalHeaderItem(4,new QTableWidgetItem(QString("Birth Year")));
    ui->MainTable->setHorizontalHeaderItem(5,new QTableWidgetItem(QString("Death Year")));

    ui->MainTable->setSortingEnabled(true);
}

void MainWindow::displayComputer()
{
    ui->MainTable->setSortingEnabled(false);

    ui->MainTable->clearContents();
    ui->MainTable->setColumnCount(4);
    ui->MainTable->setHorizontalHeaderItem(0,new QTableWidgetItem(QString("Name")));
    ui->MainTable->setHorizontalHeaderItem(1,new QTableWidgetItem(QString("Year")));
    ui->MainTable->setHorizontalHeaderItem(2,new QTableWidgetItem(QString("Type")));
    ui->MainTable->setHorizontalHeaderItem(3,new QTableWidgetItem(QString("Built")));

    ui->MainTable->setSortingEnabled(true);
}

void MainWindow::displayLink()
{
    ui->MainTable->setSortingEnabled(false);

    ui->MainTable->clearContents();
    ui->MainTable->setColumnCount(4);
    ui->MainTable->setHorizontalHeaderItem(0,new QTableWidgetItem(QString("CS name")));
    ui->MainTable->setHorizontalHeaderItem(1,new QTableWidgetItem(QString("CS_id")));
    ui->MainTable->setHorizontalHeaderItem(2,new QTableWidgetItem(QString("Computer_id")));
    ui->MainTable->setHorizontalHeaderItem(3,new QTableWidgetItem(QString("Computer name")));

    ui->MainTable->setSortingEnabled(true);
}

void MainWindow::on_SELECT_TABLE_currentIndexChanged(int index)
{
    displayAll(GetCurrentTable());
}

int MainWindow::GetCurrentTable()
{
    string temp = ui->SELECT_TABLE->currentText().toStdString();

    if(temp == "CS")
    {
        return 1;
    }
    else if(temp == "Computer")
    {
        return 2;
    }
    else if(temp == "Link")
    {
        return 3;
    }
    return 1;
}
