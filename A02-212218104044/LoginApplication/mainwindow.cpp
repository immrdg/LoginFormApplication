#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QtSql/QSqlDatabase>
#include<QSqlQuery>
#include<dialog.h>
#include<QMessageBox>
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
        QString username,password;
        username=ui->lineEdit->text();
        password=ui->lineEdit_2->text();
        QSqlDatabase db=QSqlDatabase::addDatabase("QPSQL");
        db.setHostName("127.0.0.1");
        db.setDatabaseName("students");;
        db.setUserName("postgres");
        db.setPassword("immrdg");
        bool ok = db.open();
        if(ok)
        {
            QSqlQuery query("SELECT * FROM users where regno="+username+"and password='"+password+"';");
            if(query.size()==1)
            {
                hide();
                QString con=db.connectionName();
                db.close();
                db=QSqlDatabase();
                QSqlDatabase::removeDatabase(con);
                    Dialog *dbdialog=new Dialog(this);
                    dbdialog->setData(username.toInt(),password);
                    dbdialog->exec();
                    if(dbdialog->Rejected)
                        show();
              }
            else
               QMessageBox::warning(this,"Incorrect Credentials","Please Provide Valid User Name And Password");
        }
        else
          QMessageBox::information(this,"Server Problem","Failed To Connect Contact Admin");
}
