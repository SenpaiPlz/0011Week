#include "deletescientist.h"
#include "ui_deletescientist.h"

DeleteScientist::DeleteScientist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteScientist)
{
    ui->setupUi(this);
    ui->button_mark->setEnabled(false);
    ui->button_unmark->setEnabled(false);
    Refresh();

}

DeleteScientist::~DeleteScientist()
{
    delete ui;
}

void DeleteScientist::Refresh()
{
    vector<ComputerScientist> css = d.GetComputerScientist("first_name",false);
    showCS(css);
    vector<ComputerScientist> del = d.GetDeletedCS();
    showDELCS(del);
}

void DeleteScientist::showCS(vector<ComputerScientist>& css)
{
    ui->table_original->setSortingEnabled(false);

    ui->table_original->clearContents();
    ui->table_original->setColumnCount(7);
    ui->table_original->setRowCount(css.size());

    ui->table_original->setHorizontalHeaderItem(0,new QTableWidgetItem(QString("Id")));
    ui->table_original->setHorizontalHeaderItem(1,new QTableWidgetItem(QString("First Name")));
    ui->table_original->setHorizontalHeaderItem(2,new QTableWidgetItem(QString("Middle Name")));
    ui->table_original->setHorizontalHeaderItem(3,new QTableWidgetItem(QString("Last Name")));
    ui->table_original->setHorizontalHeaderItem(4,new QTableWidgetItem(QString("Gender")));
    ui->table_original->setHorizontalHeaderItem(5,new QTableWidgetItem(QString("Birth Year")));
    ui->table_original->setHorizontalHeaderItem(6,new QTableWidgetItem(QString("Death Year")));

    for(size_t i = 0; i < css.size(); i++)
    {
        ComputerScientist temp = css[i];

        QTableWidgetItem* id = new QTableWidgetItem;
        QTableWidgetItem* yearborn = new QTableWidgetItem;
        QTableWidgetItem* yeardied = new QTableWidgetItem;
        id->setData(Qt::DisplayRole,temp.getID());
        yearborn->setData(Qt::DisplayRole,temp.getBday());
        yeardied->setData(Qt::DisplayRole,temp.getDday());

        ui->table_original->setItem(i,0, id);
        ui->table_original->setItem(i,1, new QTableWidgetItem(QString::fromStdString(temp.getFirst())));
        ui->table_original->setItem(i,2, new QTableWidgetItem(QString::fromStdString(temp.getMid())));
        ui->table_original->setItem(i,3, new QTableWidgetItem(QString::fromStdString(temp.getLast())));
        ui->table_original->setItem(i,4, new QTableWidgetItem(QString::fromStdString(temp.getGender())));
        ui->table_original->setItem(i,5, yearborn);
        ui->table_original->setItem(i,6, yeardied);
    }

    ui->table_original->setSortingEnabled(true);
}

void DeleteScientist::showDELCS(vector<ComputerScientist>& css)
{
    ui->table_delete->setSortingEnabled(false);

    ui->table_delete->clearContents();
    ui->table_delete->setColumnCount(7);
    ui->table_delete->setRowCount(css.size());

    ui->table_delete->setHorizontalHeaderItem(0,new QTableWidgetItem(QString("Id")));
    ui->table_delete->setHorizontalHeaderItem(1,new QTableWidgetItem(QString("First Name")));
    ui->table_delete->setHorizontalHeaderItem(2,new QTableWidgetItem(QString("Middle Name")));
    ui->table_delete->setHorizontalHeaderItem(3,new QTableWidgetItem(QString("Last Name")));
    ui->table_delete->setHorizontalHeaderItem(4,new QTableWidgetItem(QString("Gender")));
    ui->table_delete->setHorizontalHeaderItem(5,new QTableWidgetItem(QString("Birth Year")));
    ui->table_delete->setHorizontalHeaderItem(6,new QTableWidgetItem(QString("Death Year")));

    for(size_t i = 0; i < css.size(); i++)
    {
        ComputerScientist temp = css[i];

        QTableWidgetItem* id = new QTableWidgetItem;
        QTableWidgetItem* yearborn = new QTableWidgetItem;
        QTableWidgetItem* yeardied = new QTableWidgetItem;
        id->setData(Qt::DisplayRole,temp.getID());
        yearborn->setData(Qt::DisplayRole,temp.getBday());
        yeardied->setData(Qt::DisplayRole,temp.getDday());

        ui->table_delete->setItem(i,0, id);
        ui->table_delete->setItem(i,1, new QTableWidgetItem(QString::fromStdString(temp.getFirst())));
        ui->table_delete->setItem(i,2, new QTableWidgetItem(QString::fromStdString(temp.getMid())));
        ui->table_delete->setItem(i,3, new QTableWidgetItem(QString::fromStdString(temp.getLast())));
        ui->table_delete->setItem(i,4, new QTableWidgetItem(QString::fromStdString(temp.getGender())));
        ui->table_delete->setItem(i,5, yearborn);
        ui->table_delete->setItem(i,6, yeardied);
    }

    ui->table_delete->setSortingEnabled(true);
}

void DeleteScientist::on_table_original_clicked(const QModelIndex &index)
{
    ui->button_mark->setEnabled(true);
    ui->button_unmark->setEnabled(false);
}

void DeleteScientist::on_table_delete_clicked(const QModelIndex &index)
{
    ui->button_mark->setEnabled(false);
    ui->button_unmark->setEnabled(true);
}

void DeleteScientist::on_button_mark_clicked()
{
    if(ui->table_original->selectionModel()->currentIndex().isValid())
    {
        int rowidx = ui->table_original->selectionModel()->currentIndex().row();
        int id = ui->table_original->item(rowidx,0)->text().toInt();
        d.MarkDeleted("scientists",id);
        Refresh();
    }
}

void DeleteScientist::on_button_unmark_clicked()
{
    if(ui->table_delete->selectionModel()->currentIndex().isValid())
    {
        int rowidx = ui->table_delete->selectionModel()->currentIndex().row();
        int id = ui->table_delete->item(rowidx,0)->text().toInt();
        d.UnmarkDeleted("scientists",id);
        Refresh();
    }
}

void DeleteScientist::on_button_delete_all_clicked()
{
    d.DeleteAllMarked();
    Refresh();
}

void DeleteScientist::on_table_original_doubleClicked(const QModelIndex &index)
{
    on_button_mark_clicked();
}

void DeleteScientist::on_table_delete_doubleClicked(const QModelIndex &index)
{
    on_button_unmark_clicked();
}
