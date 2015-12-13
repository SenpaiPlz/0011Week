#ifndef DELETECOMPUTER_H
#define DELETECOMPUTER_H
#include "domain/domain.h"
#include "domain/helper.h"
#include "The_Children/computer.h"

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

private:
    Ui::DeleteComputer *ui;
    Domain d;
    void showComputer(vector<Computer> &computer);
};

#endif // DELETECOMPUTER_H
