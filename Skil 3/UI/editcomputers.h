#ifndef EDITCOMPUTERS_H
#define EDITCOMPUTERS_H
#include "domain/domain.h"
#include "domain/helper.h"

#include <QDialog>

namespace Ui {
class EditComputers;
}

class EditComputers : public QDialog
{
    Q_OBJECT

public:
    explicit EditComputers(QWidget *parent = 0);
    ~EditComputers();

private slots:
    void on_pushButton_edit_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::EditComputers *ui;
    Domain d;
    helper help;
};

#endif // EDITCOMPUTERS_H
