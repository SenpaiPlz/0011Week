#ifndef DELETECOMPUTER_H
#define DELETECOMPUTER_H
#include "domain/domain.h"
#include "domain/helper.h"
#include "The_Children/computer.h"
#include <vector>
#include <QMessageBox>

#include <QDialog>

namespace Ui {
class DeleteComputer;
}

class DeleteComputer : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteComputer(QWidget *parent = 0);
    ~DeleteComputer();

private slots:
    //activate buttons
    void on_table_original_clicked();

    void on_table_delete_clicked();
//-----------------------------------//

    void on_button_mark_clicked();

    void on_button_unmark_clicked();

    void on_button_delete_all_clicked();

    //Automatic mark/unmark on double click
    void on_table_original_doubleClicked();

    void on_table_delete_doubleClicked();

private:
    Ui::DeleteComputer *ui;
    Domain d;
    void showComputer(vector<Computer> &computer);
    void showDelComputer(vector<Computer>& computer);
    void Refresh();
};

#endif // DELETECOMPUTER_H
