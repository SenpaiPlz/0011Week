#ifndef DELETELINK_H
#define DELETELINK_H
#include "domain/domain.h"
#include "domain/helper.h"
#include "The_Children/computer.h"
#include "The_Children/computerscientist.h"

#include <QDialog>

namespace Ui {
class DeleteLink;
}

class DeleteLink : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteLink(QWidget *parent = 0);
    ~DeleteLink();

private slots:
    void on_button_delete_clicked();

    void on_table_link_itemSelectionChanged();

    void on_table_link_doubleClicked(const QModelIndex &index);

private:
    Ui::DeleteLink *ui;
    Domain d;
    void showLink(vector<ComputerScientist>& cssinner, vector<Computer>& compinner, vector<int>& rowid);
    void Refresh();
};

#endif // DELETELINK_H
