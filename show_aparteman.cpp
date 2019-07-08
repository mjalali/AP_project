#include "show_aparteman.h"
#include "ui_show_aparteman.h"

show_aparteman::show_aparteman(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::show_aparteman)
{
    ui->setupUi(this);
}

show_aparteman::~show_aparteman()
{
    delete ui;
}
