#include "deletecomputer.h"
#include "ui_deletecomputer.h"

DeleteComputer::DeleteComputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteComputer)
{
    ui->setupUi(this);

    ui->button_mark->setEnabled(false);
    ui->button_unmark->setEnabled(false);
    Refresh();
}

DeleteComputer::~DeleteComputer()
{
    delete ui;
}

void DeleteComputer::Refresh()
{
    vector<Computer> css = d.GetComputers("name", false);
    showComputer(css);
    vector<Computer> del = d.GetDeletedComputers();
    showDelComputer(del);
}

void DeleteComputer::showComputer(vector<Computer>& computer)
{
    ui->table_original->setSortingEnabled(false);

    ui->table_original->clearContents();
    ui->table_original->setColumnCount(5);
    ui->table_original->setRowCount(computer.size());

    ui->table_original->setHorizontalHeaderItem(0,new QTableWidgetItem(QString("id")));
    ui->table_original->setHorizontalHeaderItem(1,new QTableWidgetItem(QString("Name")));
    ui->table_original->setHorizontalHeaderItem(2,new QTableWidgetItem(QString("Year")));
    ui->table_original->setHorizontalHeaderItem(3,new QTableWidgetItem(QString("Type")));
    ui->table_original->setHorizontalHeaderItem(4,new QTableWidgetItem(QString("Built")));

    for(size_t i = 0; i < computer.size(); i++)
    {
        Computer temp = computer[i];

        QTableWidgetItem* id = new QTableWidgetItem;
        id->setData(Qt::DisplayRole,temp.getID());

        ui->table_original->setItem(i,0, id);
        ui->table_original->setItem(i,1, new QTableWidgetItem(QString::fromStdString(temp.getName())));
        ui->table_original->setItem(i,2, new QTableWidgetItem(QString::number(temp.getYear())));
        ui->table_original->setItem(i,3, new QTableWidgetItem(QString::fromStdString(temp.getType())));
        ui->table_original->setItem(i,4, new QTableWidgetItem(QString::number(temp.getBuilt())));
    }

    ui->table_original->setSortingEnabled(true);
}

void DeleteComputer::showDelComputer(vector<Computer>& computer)
{
    ui->table_delete->setSortingEnabled(false);

    ui->table_delete->clearContents();
    ui->table_delete->setColumnCount(5);
    ui->table_delete->setRowCount(computer.size());

    ui->table_delete->setHorizontalHeaderItem(0,new QTableWidgetItem(QString("id")));
    ui->table_delete->setHorizontalHeaderItem(1,new QTableWidgetItem(QString("Name")));
    ui->table_delete->setHorizontalHeaderItem(2,new QTableWidgetItem(QString("Year")));
    ui->table_delete->setHorizontalHeaderItem(3,new QTableWidgetItem(QString("Type")));
    ui->table_delete->setHorizontalHeaderItem(4,new QTableWidgetItem(QString("Built")));

    for(size_t i = 0; i < computer.size(); i++)
    {
        Computer temp = computer[i];

        QTableWidgetItem* id = new QTableWidgetItem;
        id->setData(Qt::DisplayRole,temp.getID());

        ui->table_delete->setItem(i,0, id);
        ui->table_delete->setItem(i,1, new QTableWidgetItem(QString::fromStdString(temp.getName())));
        ui->table_delete->setItem(i,2, new QTableWidgetItem(QString::number(temp.getYear())));
        ui->table_delete->setItem(i,3, new QTableWidgetItem(QString::fromStdString(temp.getType())));
        ui->table_delete->setItem(i,4, new QTableWidgetItem(QString::number(temp.getBuilt())));
    }

    ui->table_delete->setSortingEnabled(true);
}

void DeleteComputer::on_table_original_clicked(const QModelIndex &index)
{
    ui->button_mark->setEnabled(true);
    ui->button_unmark->setEnabled(false);
}

void DeleteComputer::on_table_delete_clicked(const QModelIndex &index)
{
    ui->button_mark->setEnabled(false);
    ui->button_unmark->setEnabled(true);
}

void DeleteComputer::on_button_mark_clicked()
{
    int rowindex = ui->table_original->selectionModel()->currentIndex().row();
    int id = ui->table_original->item(rowindex,0)->text().toInt();

    d.MarkDeleted("computers", id);
    Refresh();
}

void DeleteComputer::on_button_unmark_clicked()
{
    int rowindex = ui->table_delete->selectionModel()->currentIndex().row();
    int id = ui->table_delete->item(rowindex,0)->text().toInt();

    d.UnmarkDeleted("computers", id);
    Refresh();
}

void DeleteComputer::on_button_delete_all_clicked()
{
    d.DeleteAllMarked();
    Refresh();
}
