#ifndef POP_H
#define POP_H

#include <QDialog>

namespace Ui {
class pop;
}

class pop : public QDialog
{
    Q_OBJECT

public:
    explicit pop(QWidget *parent = nullptr);
    ~pop();

private:
    Ui::pop *ui;
};

#endif // POP_H
