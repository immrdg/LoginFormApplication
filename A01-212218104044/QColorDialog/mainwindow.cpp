#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFontDialog>
#include<QColorDialog>
#include<QPalette>
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


void MainWindow::on_pushButton_clicked()
{
    QPalette palette = ui->text->palette();
    palette.color(QPalette::WindowText);
    palette.color(QPalette::Window);
    ui->text->setStyleSheet("font-weight:normal;");
    ui->text->setFont(QFontDialog::getFont(0,ui->text->font()));
    QFont f(ui->text->font());
    ui->status->setText("Font Changed To "+f.toString().split(",")[0]+" With Font Size "+f.toString().split(",")[1]);
    ui->text->setPalette(palette);
}

void MainWindow::on_pushButton_2_clicked()
{
        QPalette palette = ui->text->palette();
        QColor color = palette.color(QPalette::WindowText);
        QColor selectedColor = QColorDialog::getColor(color, this, "Choose Text Color");

        if(selectedColor.isValid())
        {
            palette.setColor(QPalette::WindowText, selectedColor);
            ui->text->setPalette(palette);
            ui->status->setText("Text Color Changed To: "+selectedColor.name());


        }
        else
        {
            ui->status->setText("User choosen an invalid color");
        }
}

void MainWindow::on_pushButton_3_clicked()
{
    QPalette palette = ui->text->palette();
    QColor color = palette.color(ui->text->backgroundRole());
    QColor selectedColor = QColorDialog::getColor(color, this, "Choose Background Color");
    if(selectedColor.isValid())
        {
            palette.setColor(ui->text->backgroundRole(),selectedColor);
            ui->text->setPalette(palette);
            ui->status->setText("BackGround Color Changed To: "+selectedColor.name());
        }
        else
        {
           ui->status->setText("User choosen an invalid color");
        }
}

void MainWindow::on_pushButton_4_clicked()
{
    QPalette palette = ui->text->palette();
    palette.color(QPalette::WindowText);
    palette.color(QPalette::Window);
    ui->text->setStyleSheet("font-weight:bold;");
    ui->text->setPalette(palette);
    ui->status->setText("Font Forced to bold");
}

void MainWindow::on_pushButton_5_clicked()
{
    QPalette palette = ui->text->palette();
    palette.color(QPalette::WindowText);
    palette.color(QPalette::Window);
    ui->text->setStyleSheet("font-weight:normal;");
    ui->status->setText("Font Back To Normal");
    ui->text->setPalette(palette);
}
