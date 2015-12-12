#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    d.connect();
    ui->setupUi(this);

    ui->SELECT_TABLE->addItem("Computer Scientists");
    ui->SELECT_TABLE->addItem("Computers");
    ui->SELECT_TABLE->addItem("Link between computers and scientists");

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
    ui->MainTable->setColumnCount(6);
    ui->MainTable->setRowCount(css.size());

    ui->MainTable->setHorizontalHeaderItem(0,new QTableWidgetItem(QString("First Name")));
    ui->MainTable->setHorizontalHeaderItem(1,new QTableWidgetItem(QString("Middle Name")));
    ui->MainTable->setHorizontalHeaderItem(2,new QTableWidgetItem(QString("Last Name")));
    ui->MainTable->setHorizontalHeaderItem(3,new QTableWidgetItem(QString("Gender")));
    ui->MainTable->setHorizontalHeaderItem(4,new QTableWidgetItem(QString("Birth Year")));
    ui->MainTable->setHorizontalHeaderItem(5,new QTableWidgetItem(QString("Death Year")));

    for(size_t i = 0; i < css.size(); i++)
    {
        ComputerScientist temp = css[i];

        ui->MainTable->setItem(i,0, new QTableWidgetItem(QString::fromStdString(temp.getFirst())));
        ui->MainTable->setItem(i,1, new QTableWidgetItem(QString::fromStdString(temp.getMid())));
        ui->MainTable->setItem(i,2, new QTableWidgetItem(QString::fromStdString(temp.getLast())));
        ui->MainTable->setItem(i,3, new QTableWidgetItem(QString::fromStdString(temp.getGender())));
        ui->MainTable->setItem(i,4, new QTableWidgetItem(QString::number(temp.getBday())));
        ui->MainTable->setItem(i,5, new QTableWidgetItem(QString::number(temp.getDday())));
    }

    ui->MainTable->setSortingEnabled(true);
}

void MainWindow::displayComputer(vector<Computer>& computer)
{
    ui->MainTable->setSortingEnabled(false);

    ui->MainTable->clearContents();
    ui->MainTable->setColumnCount(4);
    ui->MainTable->setRowCount(computer.size());

    ui->MainTable->setHorizontalHeaderItem(0,new QTableWidgetItem(QString("Name")));
    ui->MainTable->setHorizontalHeaderItem(1,new QTableWidgetItem(QString("Year")));
    ui->MainTable->setHorizontalHeaderItem(2,new QTableWidgetItem(QString("Type")));
    ui->MainTable->setHorizontalHeaderItem(3,new QTableWidgetItem(QString("Built")));

    for(size_t i = 0; i < computer.size(); i++)
    {
        Computer temp = computer[i];

        ui->MainTable->setItem(i,0, new QTableWidgetItem(QString::fromStdString(temp.getName())));
        ui->MainTable->setItem(i,1, new QTableWidgetItem(QString::number(temp.getYear())));
        ui->MainTable->setItem(i,2, new QTableWidgetItem(QString::fromStdString(temp.getType())));
        ui->MainTable->setItem(i,3, new QTableWidgetItem(QString::number(temp.getBuilt())));
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
        QString csname = QString::fromStdString(cssinner[i].getFirst()) + " "
                + QString::fromStdString(cssinner[i].getMid()) + " "
                + QString::fromStdString(cssinner[i].getLast());

        ui->MainTable->setItem(i,0, new QTableWidgetItem(csname));
        ui->MainTable->setItem(i,1, new QTableWidgetItem(QString::number(cssinner[i].getID())));
        ui->MainTable->setItem(i,2, new QTableWidgetItem(QString::number(compinner[i].getID())));
        ui->MainTable->setItem(i,3, new QTableWidgetItem(QString::fromStdString(compinner[i].getName())));
        ui->MainTable->setItem(i,4, new QTableWidgetItem(QString::number(rowid[i])));
    }

    ui->MainTable->setSortingEnabled(true);
}

void MainWindow::on_SELECT_TABLE_currentIndexChanged(int index)
{
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

void MainWindow::on_Filter_textChanged(const QString &arg1)
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

void MainWindow::on_actionDelete_Options_triggered()
{
    DeleteOptions deleteOptions;
    deleteOptions.exec();

}
