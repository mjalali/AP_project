#ifndef SHOW_APARTEMAN_H
#define SHOW_APARTEMAN_H

#include <QDialog>

namespace Ui {
class show_aparteman;
}

class show_aparteman : public QDialog
{
    Q_OBJECT

public:
    explicit show_aparteman(QWidget *parent = nullptr);
    ~show_aparteman();

private:
    Ui::show_aparteman *ui;
};

#endif // SHOW_APARTEMAN_H
