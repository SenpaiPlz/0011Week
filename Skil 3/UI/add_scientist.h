#ifndef ADD_SCIENTIST_H
#define ADD_SCIENTIST_H

#include "domain/helper.h"
#include "domain/domain.h"
#include "The_Children/computerscientist.h"
#include <string>
#include <QDialog>

namespace Ui {
class Add_Scientist;
}

class Add_Scientist : public QDialog
{
    Q_OBJECT

public:
    explicit Add_Scientist(QWidget *parent = 0);
    ~Add_Scientist();

private slots:
    void on_cancel_clicked();

    void on_add_clicked();

private:
    helper help;
    Domain d;
    Ui::Add_Scientist *ui;
    void Refresh();
};

#endif // ADD_SCIENTIST_H
