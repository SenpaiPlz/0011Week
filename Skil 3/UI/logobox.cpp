#include "logobox.h"
#include "ui_logobox.h"

LogoBox::LogoBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogoBox)
{
    ui->setupUi(this);
}

LogoBox::~LogoBox()
{
    delete ui;
}

void LogoBox::on_start_button_clicked()
{
    this->done(1);
}

void LogoBox::on_shortcut_button_clicked()
{

}
