#ifndef RENT_H
#define RENT_H

#include <QDialog>

namespace Ui {
class rent;
}

class rent : public QDialog
{
    Q_OBJECT

public:
    explicit rent(QWidget *parent = nullptr);
    ~rent();

private:
    Ui::rent *ui;
};

#endif // RENT_H
