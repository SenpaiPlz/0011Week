#include "addlink.h"
#include "ui_addlink.h"

AddLink::AddLink(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddLink)
{
    ui->setupUi(this);
    ui->button_select->setDisabled(true);
    ui->button_Link->setDisabled(true);
    vector<ComputerScientist> css = d.GetComputerScientist("first_name",false);
    displayCSS(css);
}

AddLink::~AddLink()
{
    delete ui;
}

void AddLink::displayCSS(vector<ComputerScientist>& css)
{
    ui->table_linking->setSortingEnabled(false);

    ui->table_linking->clearContents();
    ui->table_linking->setColumnCount(7);
    ui->table_linking->setRowCount(css.size());

    ui->table_linking->setHorizontalHeaderItem(0,new QTableWidgetItem(QString("Id")));
    ui->table_linking->setHorizontalHeaderItem(1,new QTableWidgetItem(QString("First Name")));
    ui->table_linking->setHorizontalHeaderItem(2,new QTableWidgetItem(QString("Middle Name")));
    ui->table_linking->setHorizontalHeaderItem(3,new QTableWidgetItem(QString("Last Name")));
    ui->table_linking->setHorizontalHeaderItem(4,new QTableWidgetItem(QString("Gender")));
    ui->table_linking->setHorizontalHeaderItem(5,new QTableWidgetItem(QString("Birth Year")));
    ui->table_linking->setHorizontalHeaderItem(6,new QTableWidgetItem(QString("Death Year")));

    for(size_t i = 0; i < css.size(); i++)
    {
        ComputerScientist temp = css[i];

        QTableWidgetItem* id = new QTableWidgetItem;
        QTableWidgetItem* yearborn = new QTableWidgetItem;
        QTableWidgetItem* yeardied = new QTableWidgetItem;
        id->setData(Qt::DisplayRole,temp.getID());
        yearborn->setData(Qt::DisplayRole,temp.getBday());
        yeardied->setData(Qt::DisplayRole,temp.getDday());

        ui->table_linking->setItem(i,0, id);
        ui->table_linking->setItem(i,1, new QTableWidgetItem(QString::fromStdString(temp.getFirst())));
        ui->table_linking->setItem(i,2, new QTableWidgetItem(QString::fromStdString(temp.getMid())));
        ui->table_linking->setItem(i,3, new QTableWidgetItem(QString::fromStdString(temp.getLast())));
        ui->table_linking->setItem(i,4, new QTableWidgetItem(QString::fromStdString(temp.getGender())));
        ui->table_linking->setItem(i,5, yearborn);
        ui->table_linking->setItem(i,6, yeardied);
    }

    ui->table_linking->setSortingEnabled(true);
}

void AddLink::displayComp(vector<Computer>& computer)
{
    ui->table_linking->setSortingEnabled(false);

    ui->table_linking->clearContents();
    ui->table_linking->setColumnCount(5);
    ui->table_linking->setRowCount(computer.size());

    ui->table_linking->setHorizontalHeaderItem(0,new QTableWidgetItem(QString("id")));
    ui->table_linking->setHorizontalHeaderItem(1,new QTableWidgetItem(QString("Name")));
    ui->table_linking->setHorizontalHeaderItem(2,new QTableWidgetItem(QString("Year")));
    ui->table_linking->setHorizontalHeaderItem(3,new QTableWidgetItem(QString("Type")));
    ui->table_linking->setHorizontalHeaderItem(4,new QTableWidgetItem(QString("Built")));

    for(size_t i = 0; i < computer.size(); i++)
    {
        Computer temp = computer[i];

        QTableWidgetItem* id = new QTableWidgetItem;
        id->setData(Qt::DisplayRole,temp.getID());

        ui->table_linking->setItem(i,0, id);
        ui->table_linking->setItem(i,1, new QTableWidgetItem(QString::fromStdString(temp.getName())));
        ui->table_linking->setItem(i,2, new QTableWidgetItem(QString::number(temp.getYear())));
        ui->table_linking->setItem(i,3, new QTableWidgetItem(QString::fromStdString(temp.getType())));
        ui->table_linking->setItem(i,4, new QTableWidgetItem(QString::number(temp.getBuilt())));
    }

    ui->table_linking->setSortingEnabled(true);
}

void AddLink::on_table_linking_clicked(const QModelIndex &index)
{
    ui->button_select->setEnabled(true);
    if(TableCount > 1)
    {
        ui->button_select->setDisabled(true);
        ui->button_Link->setEnabled(true);
    }
}

void AddLink::on_button_select_clicked()
{
    ui->button_select->setDisabled(true);
    int rowidx = ui->table_linking->selectionModel()->currentIndex().row();
    CSID = ui->table_linking->item(rowidx,0)->text().toInt();
    TableCount++;
    vector<Computer> comp = d.GetComputers("name",false);
    displayComp(comp);
}

void AddLink::on_button_Link_clicked()
{
    int rowidx = ui->table_linking->selectionModel()->currentIndex().row();
    int id = ui->table_linking->item(rowidx,0)->text().toInt();
    d.AddLink(CSID,id);
    this->done(1);
}