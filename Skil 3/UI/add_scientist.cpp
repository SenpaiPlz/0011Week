#include "add_scientist.h"
#include "ui_add_scientist.h"

Add_Scientist::Add_Scientist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_Scientist)
{
    ui->setupUi(this);
}

Add_Scientist::~Add_Scientist()
{
    delete ui;
}

void Add_Scientist::on_pushButton_2_clicked()
{
    this->done(0);
}

void Add_Scientist::on_pushButton_clicked()
{
    bool valid = true;
    string tmpname = ui->FirstName->text().toStdString();
    string tmpmid = ui->MidName->text().toStdString();
    string tmplast = ui->LastName->text().toStdString();
    string tmpgender = ui->Gender->text().toStdString();
    QString tmpyearborn = ui->YearBorn->text();
    QString tmpyeardied = ui->Yeardied->text();
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

        d.AddComputerScientist(cstemp);
        this->done(1);
    }
}