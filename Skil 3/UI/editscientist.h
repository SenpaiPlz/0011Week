#ifndef EDITSCIENTIST_H
#define EDITSCIENTIST_H
#include "domain/domain.h"
#include "domain/helper.h"

#include <QDialog>

namespace Ui {
class EditScientist;
}

class EditScientist : public QDialog
{
    Q_OBJECT

public:
    explicit EditScientist(QWidget *parent = 0);
    ~EditScientist();
    void SetID(const QString &str);
    void SetFirst(const QString &str);
    void SetMid(const QString &str);
    void SetLast(const QString &str);
    void SetGender(const QString &str);
    void SetBday(const QString &str);
    void SetDday(const QString &str);

private slots:
    void on_pushButton_Cancel_clicked();

    void on_pushButton_Edit_clicked();

private:
    Ui::EditScientist *ui;
    Domain d;
    helper help;
    void Refresh();
};

#endif // EDITSCIENTIST_H
