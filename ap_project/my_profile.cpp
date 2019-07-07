#include "my_profile.h"
#include "ui_my_profile.h"
#include<QMovie>
#include<QtMultimedia/QAudio>
#include<QTimer>
#include<QLabel>
my_profile::my_profile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::my_profile)
{
    ui->setupUi(this);
    ui->tabWidget->setTabText(0,"Profile setting");
    ui->tabWidget->setTabText(1,"Inset building");
    ui->tabWidget->setTabText(2,"List building");
    ui->tabWidget->setTabText(3,"List File");
//    QMovie* ss=new QMovie("C:/Users/Ali/Desktop/tenor.gif");
//ui->move->setMovie(ss);
//ui->move->setScaledContents(true);
//ss->start();
    ui->TIME->setText(QTime::currentTime().toString(" hh : mm : ss"));
    QTimer* ff;
    ff=new QTimer(this);
    connect(ff,SIGNAL(timeout()),this,SLOT(tie()));
    ff->start(1000);
d=ui->TIME;
ui->DATE->setText(QDate::currentDate().toString("yyyy/ MM/ dd :"));

}

my_profile::~my_profile()
{
    delete ui;
}
