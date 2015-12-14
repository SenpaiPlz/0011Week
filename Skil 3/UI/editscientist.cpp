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

void EditScientist::on_pushButton_Cancel_clicked()
{
    this->done(0);
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
    if((!help.CheckValidtyOfString(tmpname)) || (!help.CheckValidtyOfString(tmplast))
      || ((!help.CheckValidtyOfString(tmpmid)) && (!tmpmid.empty()))
      || (!help.CheckValidtyOfString(tmpgender)))
    {
        valid = false;
    }

    if(!tmpyearborn.toInt() || (tmpyearborn.toInt() > 2015) || (tmpyearborn.toInt() < 0)
      || (!tmpyeardied.toInt() && !tmpyeardied.isEmpty()) || (tmpyearborn.toInt() > tmpyeardied.toInt()))
    {
        valid = false;
    }

    help.Tolower(tmpgender);
    if(!((tmpgender == "male") || (tmpgender == "female")))
    {
        valid = false;
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

        int yearborn = tmpyearborn.toInt(0,10);
        int yeardead = tmpyeardied.toInt(0,10);
        int id = tmpid.toInt(0,10);

        d.UpdateCS(QString::fromStdString(tmpname),QString::fromStdString(tmpmid), QString::fromStdString(tmplast), QString::fromStdString(tmpgender), yearborn, yeardead, id);
        this->done(1);
    }
}
//Just need to set for errors
