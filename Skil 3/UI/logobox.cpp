#include "logobox.h"
#include "ui_logobox.h"

//Really only here to popup at start

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
    QMessageBox::information(this,"Shortcuts",
    "<p><b><font size='4'><font color ='#1f5f2c'> Current Keybindings for MainWindow</font></b></p> \n\n "
    "<p><font color ='#1f5f2c'> CTRL + Q = Quit</font></p>\n\n "
    "<p><font color ='#1f5f2c'>CTRL + E = Edit Currently selected item</font></p>\n\n "
    "<p><font color ='#1f5f2c'>CTRL + A = Add Item of currently selected table</font></p>\n\n "
    "<p><font color ='#1f5f2c'>CTRL + D = Mark for deletion/Delete currently selected item</font></p>\n\n "
    "<p><font color ='#1f5f2c'>CTRL + ALT + D = Delete Menu for Computers</font></p>\n\n "
    "<p><font color ='#1f5f2c'>SHIFT + ALT + D = Delete Menu for ComputerScientists</font><p>\n\n"
    "<p><font color ='#1f5f2c'>CTRL + S = Opens Shortcut Box</font><p>\n");
}
