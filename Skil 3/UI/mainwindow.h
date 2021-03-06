#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <QTableView>
#include <vector>
#include <QShortcut>
#include "domain/domain.h"
#include "domain/helper.h"
#include "The_Children/computer.h"
#include "The_Children/computerscientist.h"
#include "UI/add_scientist.h"
#include "UI/add_computer.h"
#include "UI/deletecomputer.h"
#include "UI/deletelink.h"
#include "UI/deletescientist.h"
#include "UI/editscientist.h"
#include "UI/editcomputers.h"
#include "UI/addlink.h"

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
    //Generic triggers
    void on_SELECT_TABLE_currentIndexChanged();

    void on_Filter_textChanged();

    void on_actionDelete_Scientists_triggered();

    void on_actionDelete_Computers_triggered();

    void on_actionDelete_Link_triggered();

    void on_MainTable_ShowContextMenu(const QPoint& pos);

    void on_actionAdd_Computer_Scientist_triggered();

    void on_actionAdd_Computer_triggered();

    void on_actionEdit_ComputerScientist_triggered();

    void on_actionEdit_Computer_triggered();

    void on_MainTable_doubleClicked();

    void on_actionAdd_Link_triggered();

    void on_actionShortcuts_triggered();

    //custom triggers and functions
    void Edit_Triggered();

    void Delete_Triggered();

    void Add_Triggered();

    void quit();

private:
    Domain d;
    Ui::MainWindow *ui;
    int GetCurrentTable();
    void Keybinds();
    void displayAll(int index);
    void displayCS(vector<ComputerScientist> &css);
    void displayComputer(vector<Computer> &computer);
    void displayLink(vector<ComputerScientist>& cssinner, vector<Computer>& compinner, vector<int>& rowid);
};

#endif // MAINWINDOW_H
