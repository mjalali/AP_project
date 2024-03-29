#include "my_profile.h"
#include "ui_my_profile.h"
#include<QMovie>
#include<QtMultimedia/QAudio>
#include<QTimer>
#include<QLabel>
#include<QVector>
#include<building.h>
#include"pop.h"
#include"house.h"
#include<windows.h>

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
    if(ui->base_price_le->text()!="" && ui->hole_area_le->text()!="" && ui->address_le->text()!=""){
    if((ui->built_area_notrh->text()!="" && ui->rooms_north->text()!="" && ui->front_area_north->text()!="" && ui->back_area_north->text()!=""&&ui->building_mode->currentIndex()==0)){
        Image* g=new Image(picture);
//        Northern_villa* sss=new Northern_villa(1,1,"1",g,1,1,1,1);
                Northern_villa* ss=new  Northern_villa(ui->base_price_le->text().toFloat(),ui->hole_area_le->text().toFloat(),ui->address_le->text(),g,ui->built_area_notrh->text().toFloat(),ui->rooms_north->text().toInt(),ui->front_area_north->text().toFloat(),ui->back_area_north->text().toFloat());
                pop* w=new pop();
                connect(this,SIGNAL(set_pop(QString)),w,SLOT(get_string(QString)));
                emit set_pop("New Northern villa added");
                qDebug()<<list_bulding->size();
                qDebug()<<"d";
                list_bulding->push_back(ss);

                w->exec();
    }
    if(ui->built_area_south->text()!="" && ui->rooms_south->text()!="" && ui->yard_area_south->text()!="" && ui->parking_area_south->text()!=""&&ui->building_mode->currentIndex()==1){
        Image* gg=new Image(picture);
            Southern_villa* dd=new Southern_villa(ui->base_price_le->text().toFloat(),ui->hole_area_le->text().toFloat(),ui->address_le->text(),gg,ui->built_area_south->text().toFloat(),ui->rooms_south->text().toInt(),ui->yard_area_south->text().toFloat(),ui->parking_area_south->text().toFloat());
            pop* ww=new pop();
            connect(this,SIGNAL(set_pop(QString)),ww,SLOT(get_string(QString)));
            emit set_pop("New Southern villa added");
            qDebug()<<list_bulding->size();
            qDebug()<<"d";
            list_bulding->push_back(dd);

            ww->exec();
    }
    if(ui->floors_ap->text()!="")
    {
          Image* ggg=new Image(picture);

          class::Apartment* re=new class::Apartment(ui->base_price_le->text().toFloat(),ui->hole_area_le->text().toFloat(),ui->address_le->text(),ggg,ui->have_elevator->isTristate(),ui->floors_ap->text().toInt(),list_house);

          pop* ww=new pop();
          connect(this,SIGNAL(set_pop(QString)),ww,SLOT(get_string(QString)));
          emit set_pop("New Apartment added");
          qDebug()<<list_bulding->size();
          qDebug()<<"d";
          list_bulding->push_back(re);

          ww->exec();

    }
    }
}

void my_profile::on_tabWidget_currentChanged(int index)
{
    if(index==2){
        ui->list_buildig->clear();
        int i=0;
//        ui->list_buildig->append("Number    kind        Adress  Price");


        QVector<Building*>::iterator j=list_bulding->begin();
//        qDebug()<<(*j)->Address();
        while(j!=list_bulding->end()){
            i++;
            QString d=QString::number(i);
            d+="\t";
            {
                Northern_villa* to=dynamic_cast<Northern_villa*>(*j);
                if(to){
                    d+="Northen villa";
                }
                else{
                    Southern_villa* yo=dynamic_cast<Southern_villa*>(*j);
                    if(yo){
                        d+="Southern villa";
                    }
                    else{
                        d+="apartment";
                    }
                }
            }
            d+="\t\t";
            d+=(*j)->Address();
            d+="\t";
            d+=QString::number(static_cast<double>((*j)->Price()));
            ui->list_buildig->append(d);

            j++;
        }


    }
}

void my_profile::on_add_house_pb_clicked()
{
    house * hh=new house;

    connect(this,SIGNAL(send_house(QVector<House*>&)),hh,SLOT(get_house(QVector<House*>&)));
    emit send_house(list_house);
//    Sleep(10000);
    hh->exec();

}

void my_profile::on_pushButton_clicked()
{
    if(ui->spinBox->text().toInt()<=list_bulding->size()){

    }
}
