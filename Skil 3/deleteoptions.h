#ifndef DELETEOPTIONS_H
#define DELETEOPTIONS_H
#include "ui/mainwindow.h"
#include "domain/domain.h"
#include "domain/helper.h"
#include "The_Children/computer.h"
#include "The_Children/computerscientist.h"

#include <QDialog>
#include <QTableWidget>

namespace Ui {
class DeleteOptions;
}

class DeleteOptions : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteOptions(QWidget *parent = 0);
    ~DeleteOptions();

private:
    Ui::DeleteOptions *ui;
    Domain d;
    void ShowTable();
    int GetTables();
    void showCS(vector<ComputerScientist> &css);
    void showComputer(vector<Computer> &computer);
    void showLink(vector<ComputerScientist>& cssinner, vector<Computer>& compinner, vector<int>& rowid);
    void ShowAll(int index);
};

#endif // DELETEOPTIONS_H
