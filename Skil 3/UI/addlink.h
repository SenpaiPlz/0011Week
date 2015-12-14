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
    bool on_button_select_clicked();

    void on_table_linking_itemSelectionChanged();

private:
    Ui::AddLink *ui;
    Domain d;
    helper help;
    void displayCS(vector<ComputerScientist>& css);
    void displayComputer(vector<Computer>& computer);
    void ControlLinking();
};

#endif // ADDLINK_H
