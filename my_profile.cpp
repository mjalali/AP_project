#include "my_profile.h"
#include "ui_my_profile.h"
#include<QMovie>
#include<QtMultimedia/QAudio>
#include<QTimer>
#include<QLabel>

#include<QFileDialog>

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

user=ui->lineEdit_user;
pass=ui->lineEdit_user_;
first=ui->lineEdit_first_name;
last=ui->lineEdit_first_name_2;
profile=ui->label_3;
profile->setScaledContents(true);
date=ui->dateEdit;
gif=ui->move;
ui->building_mode->addItem("Northern villa");
ui->building_mode->addItem("Sothern villa");
ui->building_mode->addItem("Apartment");


}

my_profile::~my_profile()
{
    delete ui;
}

void my_profile::on_pushButton_2_clicked()
{
    Date* t=new Date(date->date().day(),date->date().month(),date->date().year());
    Image* id=new Image(filename);
   this_User->edit_user(first->text(),last->text(),t,true,user->text(),pass->text(),true,id);
}

void my_profile::on_pushButton_4_clicked()
{

    filename = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                   "/home",
                                                   tr("Images (*.png *.xpm *.jpg)"));
   QPixmap s(filename);

   ui->label_3->setPixmap(s);
    ui->label_3->setScaledContents(true);

   qDebug()<<filename;
}

void my_profile::on_building_mode_currentIndexChanged(int index)
{
    if(index==0){
        ui->n_villa_gp->setEnabled(true);
        ui->s_villa_gp->setEnabled(false);
        ui->apartment_gp->setEnabled(false);
    }
    if(index==1){
        ui->n_villa_gp->setEnabled(false);
        ui->s_villa_gp->setEnabled(true);
        ui->apartment_gp->setEnabled(false);
    }
    if(index==2){
        ui->n_villa_gp->setEnabled(false);
        ui->s_villa_gp->setEnabled(false);
        ui->apartment_gp->setEnabled(true);
    }
}

void my_profile::on_add_picture_clicked()
{
    picture = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                   "/home",
                                                   tr("Images (*.png *.xpm *.jpg)"));





}

void my_profile::on_Insert_clicked()
{

}
