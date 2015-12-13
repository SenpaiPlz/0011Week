#ifndef ADD_COMPUTER_H
#define ADD_COMPUTER_H

#include "The_Children/computer.h"
#include "domain/helper.h"
#include "domain/domain.h"
#include <string>
#include <QDialog>

namespace Ui {
class add_computer;
}

class add_computer : public QDialog
{
    Q_OBJECT

public:
    explicit add_computer(QWidget *parent = 0);
    ~add_computer();

private slots:
    void on_cancel_clicked();

    void on_Add_clicked();

private:
    helper help;
    Domain d;
    Ui::add_computer *ui;
};

#endif // ADD_COMPUTER_H
