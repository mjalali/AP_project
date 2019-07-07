#include "reg.h"
#include "ui_reg.h"
#include"pop.h"

#include"manager_normal_user.h"

#include"image.h"
#include<QDebug>
#include"file.h"
#include"manager_normal_user.h"
reg::reg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reg)
{
    ui->setupUi(this);
    ui->comboBox_kind->addItem("Normal_user");
    ui->comboBox_kind->addItem("Manager");



//    ui->comboBox_kind->

}

reg::~reg()
{
    delete ui;
}

void reg::on_pushButton_clicked()
{
    if(ui->comboBox_kind->currentIndex()==0){
        if(ui->lineEdit_user->text()!=""&&ui->lineEdit_pass->text()!=""&&ui->lineEdit_first_name->text()!=""&&ui->lineEdit_last_name->text()!=""){
            qDebug()<<"salam";
            Date* d=new Date(ui->dateEdit->date().day(),ui->dateEdit->date().month(),ui->dateEdit->date().year());
            Image* u=new Image(fileName);
               QVector<File*> *c=new QVector<File*>;
//               c->reserve(10);
               qDebug()<<"salam";
               Normal_user* s=new Normal_user(ui->lineEdit_user->text(),ui->lineEdit_pass->text(),d,true,ui->lineEdit_user->text(),ui->lineEdit_pass->text(),true,u,*c);
//            list_in_reg->insert(1,s);
            qDebug()<<"salam";

            list_in_reg->push_back(s);
            qDebug()<<"salam2";
//            list_in_reg->reserve(10);

            close();
        }
    }
    else if(ui->comboBox_kind->currentIndex()==1&&ui->goooo_2->text()=="ali1234"){

    }
    else{
        pop a;
        a.exec();
    }
}

void reg::on_comboBox_kind_currentIndexChanged(int index)
{
    if(index==1){
         ui->goooo->setVisible(true);
         ui->goooo_2->setVisible(true);

    }
    if(index==0){
        ui->goooo_2->clear();
        ui->goooo->setVisible(false);
        ui->goooo_2->setVisible(false);
    }
}

void reg::on_pushButton_2_clicked()
{
    close();
}

void reg::on_pushButton_4_clicked()
{
//    QString filename=QFileDialog::getOpenFileName(this,tr("chose"),"/home",tr("Images (*.png,*.jpg,*.tfif)"));

     fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "/home",
                                                    tr("Images (*.png *.xpm *.jpg)"));
    QPixmap s(fileName);

    ui->label_3->setPixmap(s);
     ui->label_3->setScaledContents(true);

    qDebug()<<fileName;
}
