#include "pop.h"
#include "ui_pop.h"

pop::pop(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pop)
{
    ui->setupUi(this);
}

pop::~pop()
{
    delete ui;
}
