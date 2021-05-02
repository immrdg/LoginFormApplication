#include "dialog.h"
#include "ui_dialog.h"
#include<QSqlQuery>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setFixedSize(590,431);
}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::setData(const int regno,const QString &pass)
{
    user=QString::number(regno);
    password=pass;
}

void Dialog::on_pushButton_clicked()
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("students");;
    db.setUserName("postgres");
    db.setPassword("immrdg");
    bool ok = db.open();
    if(ok)
    {
        QSqlQuery query("SELECT * FROM users where regno="+user+";",db);
        QString regno,name,age,dept,year;
                while (query.next())
                {
                  regno=QString::number(query.value(0).toInt());
                  name=query.value(1).toString();
                  age=QString::number(query.value(2).toInt());
                  dept=query.value(3).toString();
                  year=QString::number(query.value(4).toInt());
                }
                QString con=db.connectionName();
                db.close();
                db=QSqlDatabase();
                QSqlDatabase::removeDatabase(con);
                QString det=("Register Number:"+regno+"\n");
                det+="Name:"+name+"\n"+"Age:"+age+"\n"+"Department:"+dept+"</b>\nYear Of Study:"+year;

                ui->plainTextEdit->setPlainText(det);
                ui->label->setText("Your Profile");
    }
    else
       qDebug()<<"Shit";

}
