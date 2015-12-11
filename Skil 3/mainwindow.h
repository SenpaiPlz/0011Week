#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <QTableView>

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

private:
    Ui::MainWindow *ui;
    int GetCurrentTable();
    void displayAll(int index);
    void displayCS();
    void displayComputer();
    void displayLink();
};

#endif // MAINWINDOW_H
