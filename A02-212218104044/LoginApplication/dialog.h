#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    QString user,password;
    ~Dialog();
    void setData(const int regno,const QString &pass);
private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;

};

#endif // DIALOG_H
