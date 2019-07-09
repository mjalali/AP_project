#include "rent.h"
#include "ui_rent.h"

rent::rent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rent)
{
    ui->setupUi(this);
}

rent::~rent()
{
    delete ui;
}
