#include "editscientist.h"
#include "ui_editscientist.h"

EditScientist::EditScientist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditScientist)
{
    ui->setupUi(this);
}

EditScientist::~EditScientist()
{
    delete ui;
}

void EditScientist::Refresh()
{
    //Reset label colour.

    ui->id_label->setText("ID");
    ui->first_label->setText("First Name");
    ui->middle_label->setText("Middle Name");
    ui->last_label->setText("Last Name");
    ui->gender_label->setText("Gender");
    ui->born_label->setText("Year Born");
    ui->dead_label->setText("Year Died");
}

void EditScientist::on_pushButton_Edit_clicked()
{
    bool valid = true;
    QString tmpid = ui->edit_id->text();
    string tmpname = ui->edit_first_name->text().toStdString();
    string tmpmid = ui->edit_middle_name->text().toStdString();
    string tmplast = ui->edit_last_name->text().toStdString();
    string tmpgender = ui->edit_gender->text().toStdString();
    QString tmpyearborn = ui->edit_bday->text();
    QString tmpyeardied = ui->edit_dday->text();
    vector<ComputerScientist> css = d.GetComputerScientist("first_name",false);
    Refresh();

    //ErrorCheck

    if(!help.ValidCSId(css,tmpid.toInt()))
    {
        valid = false;
        ui->id_label->setText("<font color='red'>ID</font>");
    }
    if((!help.CheckValidtyOfString(tmpname)))
    {
        valid = false;
        ui->first_label->setText("<font color='red'>First Name</font>");
    }
    if((!help.CheckValidtyOfString(tmplast)))
    {
        valid = false;
        ui->last_label->setText("<font color='red'>Last Name</font>");
    }
    if((!help.CheckValidtyOfString(tmpmid))&& (!tmpmid.empty()))
    {
        valid = false;
        ui->middle_label->setText("<font color='red'>Middle Name</font>");
    }
    if(!tmpyearborn.toInt())
    {
        valid = false;
        ui->born_label->setText("<font color='red'>Birth Year</font>");
    }
    if((tmpyearborn.toInt() > help.CurrentYear()) || (tmpyearborn.toInt() < 0))
    {
        valid = false;
        ui->born_label->setText("<font color='red'>Birth Year</font>");
    }
    if((!tmpyeardied.toInt() && !tmpyeardied.isEmpty())
            || ((tmpyearborn.toInt() > tmpyeardied.toInt()) && !tmpyeardied.isEmpty()))
    {
        valid = false;
        ui->dead_label->setText("<font color='red'>Death Year</font>");
    }
    help.Tolower(tmpgender);
    if(!((tmpgender == "male") || (tmpgender == "female")))
    {
        valid = false;
        ui->gender_label->setText("<font color='red'>Gender</font>");
    }


    if(valid == true)
    {
        ComputerScientist cstemp;
        cstemp.setFirst(tmpname);
        cstemp.setMid(tmpmid);
        cstemp.setLast(tmplast);
        cstemp.setgender(tmpgender);
        cstemp.setbday(tmpyearborn.toInt());
        cstemp.setdday(tmpyeardied.toInt());

        int yearborn = tmpyearborn.toInt();
        int yeardead = tmpyeardied.toInt();
        int id = tmpid.toInt();

        d.UpdateCS(QString::fromStdString(tmpname),QString::fromStdString(tmpmid), QString::fromStdString(tmplast), QString::fromStdString(tmpgender), yearborn, yeardead, id);
        this->done(0);
    }
}

void EditScientist::on_pushButton_Cancel_clicked()
{
    this->done(0);
}

//Set functions to set the values to what is selected in the table, if double clicked/shortcut used.

void EditScientist::SetID(const QString& str)
{
    ui->edit_id->setText(str);
    ui->edit_id->setDisabled(true);
}

void EditScientist::SetFirst(const QString &str)
{
    ui->edit_first_name->setText(str);
}

void EditScientist::SetMid(const QString &str)
{
    ui->edit_middle_name->setText(str);
}

void EditScientist::SetLast(const QString &str)
{
    ui->edit_last_name->setText(str);
}

void EditScientist::SetGender(const QString &str)
{
    ui->edit_gender->setText(str);
}

void EditScientist::SetBday(const QString &str)
{
    ui->edit_bday->setText(str);
}

void EditScientist::SetDday(const QString &str)
{
    ui->edit_dday->setText(str);
}
