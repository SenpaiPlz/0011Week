#ifndef DELETESCIENTIST_H
#define DELETESCIENTIST_H
#include "domain/domain.h"
#include "domain/helper.h"
#include "The_Children/computerscientist.h"

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

private:
    Ui::DeleteScientist *ui;
    Domain d;
    void showCS(vector<ComputerScientist> &css);
};

#endif // DELETESCIENTIST_H
