#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <QTableView>
#include <vector>
#include "domain/domain.h"
#include "domain/helper.h"
#include "The_Children/computer.h"
#include "The_Children/computerscientist.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_SELECT_TABLE_currentIndexChanged(int index);

    void on_Filter_textChanged(const QString &arg1);

private:
    Domain d;
    Ui::MainWindow *ui;
    int GetCurrentTable();
    void displayAll(int index);
    void displayCS(vector<ComputerScientist> &css);
    void displayComputer(vector<Computer> &computer);
    void displayLink(vector<ComputerScientist>& cssinner, vector<Computer>& compinner, vector<int>& rowid);
};

#endif // MAINWINDOW_H
