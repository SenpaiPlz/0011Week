#include "editcomputers.h"
#include "ui_editcomputers.h"

EditComputers::EditComputers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditComputers)
{
    ui->setupUi(this);
}

EditComputers::~EditComputers()
{
    delete ui;
}

void EditComputers::Refresh()
{
    //Reset label colour.

    ui->id_lable->setText("ID");
    ui->name_label->setText("Name");
    ui->type_label->setText("Type");
    ui->year_label->setText("Year Built");
}


void EditComputers::on_pushButton_edit_clicked()
{
    bool valid = true;
    int tmpid;
    string tmpname = ui->edit_name->text().toStdString();
    string tmptype = ui->edit_type->text().toStdString();
    bool built = ui->check_built->isChecked();
    int tmpyear;
    vector<Computer> css = d.GetComputers("name",false);
    Refresh();


    //Error check
    if(!help.ValidComputerId(css,ui->edit_id->text().toInt()))
    {
        valid = false;
        ui->id_lable->setText("<font color='red'>ID</font>");
    }
    if(!help.CheckValidtyOfString(tmpname))
    {
        valid = false;
        ui->name_label->setText("<font color='red'>Name</font>");
    }
    if(!help.CheckValidtyOfString(tmptype))
    {
        valid = false;
        ui->type_label->setText("<font color='red'>Type</font>");
    }
    if(!(ui->edit_year->text().toInt()) || ui->edit_year->text().toInt() < 0 || ui->edit_year->text().toInt() > help.CurrentYear())
    {
        valid = false;
        ui->year_label->setText("<font color='red'>Year Built</font>");
    }
    tmpyear = ui->edit_year->text().toInt();
    tmpid = ui->edit_id->text().toInt();


    if(valid)
    {
        Computer comptemp;
        comptemp.setName(tmpname);
        comptemp.setType(tmptype);
        comptemp.setYear(tmpyear);
        comptemp.setBuilt(built);

        d.UpdateComputer(QString::fromStdString(tmpname),tmpyear,QString::fromStdString(tmptype),built,tmpid);

        this->done(0);
    }
}

void EditComputers::on_pushButton_cancel_clicked()
{
    this->done(0);
}


//Set functions to set the values to what is selected in the table, if double clicked/shortcut used.

void EditComputers::SetID(const QString& str)
{
    ui->edit_id->setText(str);
    ui->edit_id->setDisabled(true);
}

void EditComputers::SetName(const QString& str)
{
    ui->edit_name->setText(str);
}

void EditComputers::SetYear(const QString& str)
{
    ui->edit_year->setText(str);
}

void EditComputers::SetType(const QString& str)
{
    ui->edit_type->setText(str);
}

void EditComputers::SetBuilt(const bool& built)
{
    ui->check_built->setChecked(built);
}
