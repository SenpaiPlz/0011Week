#include "add_computer.h"
#include "ui_add_computer.h"

add_computer::add_computer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_computer)
{
    ui->setupUi(this);
}

add_computer::~add_computer()
{
    delete ui;
}

void add_computer::on_cancel_clicked()
{
    this->done(0);
}

void add_computer::on_Add_clicked()
{
    bool valid = true;
    string tmpname = ui->Name->text().toStdString();
    string tmptype = ui->Type->text().toStdString();
    bool built = ui->BuiltCheckBox->isChecked();
    int tmpyear;
    if(!help.CheckValidtyOfString(tmpname) || !help.CheckValidtyOfString(tmptype))
    {
        valid = false;
    }
    if(!(ui->Year->text().toInt()) || (ui->Year->text().toInt() < 0 || ui->Year->text().toInt() > 2015))
    {
        valid = false;
    }
    tmpyear = ui->Year->text().toInt();

    if(valid)
    {
        Computer comptemp;
        comptemp.setName(tmpname);
        comptemp.setType(tmptype);
        comptemp.setYear(tmpyear);
        comptemp.setBuilt(built);

        d.AddComputer(comptemp);

        this->done(0);
    }
}
