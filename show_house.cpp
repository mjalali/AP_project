#include "show_house.h"
#include "ui_show_house.h"

show_house::show_house(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::show_house)
{
    ui->setupUi(this);
}

show_house::~show_house()
{
    delete ui;
}
