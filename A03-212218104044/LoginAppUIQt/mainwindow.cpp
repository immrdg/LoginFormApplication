#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QCoreApplication>
#include<QMessageBox>
#include<dialog.h>
#include<QDateTime>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_restartButton_clicked()
{
ui->username->setText("");
ui->password->setText("");
}

void MainWindow::on_shutdownButton_clicked()
{
    QCoreApplication::quit();
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->username->text()=="root" && ui->password->text()=="admin")
    {
        Dialog *succees=new Dialog(this);
        succees->exec();
    }
    else
        QMessageBox::warning(this,"Invalid Credentials","<b style='color:red'>Plaese Provide correct details<b>");
}
