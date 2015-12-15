#ifndef DELETESCIENTIST_H
#define DELETESCIENTIST_H
#include "domain/domain.h"
#include "domain/helper.h"
#include "The_Children/computerscientist.h"
#include "QMessageBox"

#include <QDialog>

namespace Ui {
class DeleteScientist;
}

class DeleteScientist : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteScientist(QWidget *parent = 0);
    ~DeleteScientist();

private slots:


    //Unlocks buttons
    void on_table_original_clicked();

    void on_table_delete_clicked();
//-----------------------------------//

    void on_button_mark_clicked();

    void on_button_unmark_clicked();

    void on_button_delete_all_clicked();

    //Automatic for double click
    void on_table_original_doubleClicked();

    void on_table_delete_doubleClicked();

private:
    Ui::DeleteScientist *ui;
    Domain d;
    void showCS(vector<ComputerScientist> &css);
    void showDELCS(vector<ComputerScientist> &css);
    void Refresh();
};

#endif // DELETESCIENTIST_H
