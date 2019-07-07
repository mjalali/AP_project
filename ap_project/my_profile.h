#ifndef MY_PROFILE_H
#define MY_PROFILE_H

#include <QDialog>
#include<QTime>
#include<QDebug>
#include<QLabel>
#include<QDate>

namespace Ui {
class my_profile;
}

class my_profile : public QDialog
{
    Q_OBJECT
    QLabel* d;

public:
    explicit my_profile(QWidget *parent = nullptr);
    ~my_profile();


private:
    Ui::my_profile *ui;
public slots:
    void tie(){




         d ->setText(QTime::currentTime().toString(" hh : mm : ss"));
//         qDebug()<<d;


    }
};

#endif // MY_PROFILE_H
