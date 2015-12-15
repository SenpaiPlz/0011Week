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

void Add_Scientist::Refresh()
{
    ui->first_label->setText("First Name*");
    ui->middle_label->setText("Middle Name");
    ui->last_lable->setText("Last Name*");
    ui->gender_lable->setText("Gender*");
    ui->born_lable->setText("Year Born*");
    ui->dead_lable->setText("Year Died");

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
    Refresh();
    if(!help.CheckValidtyOfString(tmpname))
    {
        valid = false;
        ui->first_label->setText("<font color='red'>First Name*</font>");
    }
    if(!help.CheckValidtyOfString(tmplast))
    {
        valid = false;
        ui->last_lable->setText("<font color='red'>Last Name*</font>");
    }
    if((!help.CheckValidtyOfString(tmpmid)) && (!tmpmid.empty()))
    {
        valid = false;
        ui->middle_label->setText("<font color='red'>Middle Name</font>");
    }
    if(!(tmpyearborn.toInt()) || (tmpyearborn.toInt() > help.CurrentYear()) || (tmpyearborn.toInt() < 0))
    {
        valid = false;
        ui->born_lable->setText("<font color='red'>Year Born*</font>");
    }
    if((tmpyearborn.toInt() > tmpyeardied.toInt()) && !tmpyeardied.isEmpty())
    {
        valid = false;
        ui->dead_lable->setText("<font color='red'>Year Died</font>");
    }

    help.Tolower(tmpgender);
    if(!((tmpgender == "male") || (tmpgender == "female")))
    {
        valid = false;
        ui->gender_lable->setText("<font color='red'>Gender*</font>");
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
