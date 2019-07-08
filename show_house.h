#ifndef SHOW_HOUSE_H
#define SHOW_HOUSE_H

#include <QDialog>

namespace Ui {
class show_house;
}

class show_house : public QDialog
{
    Q_OBJECT

public:
    explicit show_house(QWidget *parent = nullptr);
    ~show_house();

private:
    Ui::show_house *ui;
};

#endif // SHOW_HOUSE_H
