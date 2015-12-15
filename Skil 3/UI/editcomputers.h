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

    //Set functions to automaticly get info from table if edit is selected from table
    //with right click or shortcut
    void SetID(const QString& str);
    void SetName(const QString& str);
    void SetYear(const QString& str);
    void SetType(const QString& str);
    void SetBuilt(const bool& built);

private slots:
    void on_pushButton_edit_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::EditComputers *ui;
    Domain d;
    helper help;
    void Refresh();
};

#endif // EDITCOMPUTERS_H
