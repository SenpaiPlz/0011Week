#ifndef ADDLINK_H
#define ADDLINK_H
#include "domain/domain.h"
#include "domain/helper.h"
#include "The_Children/computer.h"
#include "The_Children/computerscientist.h"

#include <QDialog>

namespace Ui {
class AddLink;
}

class AddLink : public QDialog
{
    Q_OBJECT

public:
    explicit AddLink(QWidget *parent = 0);
    ~AddLink();

private slots:

    //activate buttons
    void on_table_linking_clicked();

    void on_button_select_clicked();

    void on_button_Link_clicked();

    //automatic select/link on double click
    void on_table_linking_doubleClicked();

private:
    int CSID;
    int TableCount = 1;
    Ui::AddLink *ui;
    Domain d;
    helper help;
    void displayCSS(vector<ComputerScientist>& css);
    void displayComp(vector<Computer>& computer);
};

#endif // ADDLINK_H
