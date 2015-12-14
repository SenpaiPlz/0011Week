#include "deletelink.h"
#include "ui_deletelink.h"

DeleteLink::DeleteLink(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteLink)
{
    ui->setupUi(this);

    ui->button_delete->setEnabled(false);
    Refresh();
}

DeleteLink::~DeleteLink()
{
    delete ui;
}

void DeleteLink::Refresh()
{
    vector<ComputerScientist> cssinner = d.GetCSInnerJoin();
    vector<Computer> compinner = d.GetComputerInnerJoin();
    vector<int> rowid = d.GetRowID();
    showLink(cssinner, compinner, rowid);
}

void DeleteLink::showLink(vector<ComputerScientist>& cssinner, vector<Computer>& compinner, vector<int>& rowid)
{
    ui->table_link->setSortingEnabled(false);

    ui->table_link->clearContents();
    ui->table_link->setColumnCount(5);
    ui->table_link->setRowCount(cssinner.size());

    ui->table_link->setHorizontalHeaderItem(0,new QTableWidgetItem(QString("CS name")));
    ui->table_link->setHorizontalHeaderItem(1,new QTableWidgetItem(QString("CS_id")));
    ui->table_link->setHorizontalHeaderItem(2,new QTableWidgetItem(QString("Computer_id")));
    ui->table_link->setHorizontalHeaderItem(3,new QTableWidgetItem(QString("Computer name")));
    ui->table_link->setHorizontalHeaderItem(4,new QTableWidgetItem(QString("Row_id")));

    for(size_t i = 0; i < cssinner.size(); i++)
    {
        QString csname = QString::fromStdString(cssinner[i].getFirst()) + " "
                + QString::fromStdString(cssinner[i].getMid()) + " "
                + QString::fromStdString(cssinner[i].getLast());

        QTableWidgetItem* roid = new QTableWidgetItem;
        QTableWidgetItem* csid = new QTableWidgetItem;
        QTableWidgetItem* compid = new QTableWidgetItem;
        roid->setData(Qt::DisplayRole, rowid[i]);
        csid->setData(Qt::DisplayRole, cssinner[i].getID());
        compid->setData(Qt::DisplayRole, compinner[i].getID());

        ui->table_link->setItem(i,0, new QTableWidgetItem(csname));
        ui->table_link->setItem(i,1, csid);
        ui->table_link->setItem(i,2, compid);
        ui->table_link->setItem(i,3, new QTableWidgetItem(QString::fromStdString(compinner[i].getName())));
        ui->table_link->setItem(i,4, roid);
    }

    ui->table_link->setSortingEnabled(true);
}

void DeleteLink::on_button_delete_clicked()
{
    int rowindex = ui->table_link->selectionModel()->currentIndex().row();
    int rowid = ui->table_link->item(rowindex,4)->text().toInt();

    d.DeleteLink(rowid);
    Refresh();
}

void DeleteLink::on_table_link_itemSelectionChanged()
{
    ui->button_delete->setEnabled(true);
}
