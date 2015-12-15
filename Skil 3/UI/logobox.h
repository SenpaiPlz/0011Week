#ifndef LOGOBOX_H
#define LOGOBOX_H
#include <QMessageBox>

#include <QDialog>

namespace Ui {
class LogoBox;
}

class LogoBox : public QDialog
{
    Q_OBJECT

public:
    explicit LogoBox(QWidget *parent = 0);
    ~LogoBox();

private slots:
    void on_start_button_clicked();

    void on_shortcut_button_clicked();

private:
    Ui::LogoBox *ui;
};

#endif // LOGOBOX_H
