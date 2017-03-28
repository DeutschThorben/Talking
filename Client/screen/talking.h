#ifndef TALKING_H
#define TALKING_H

#include <QWidget>

namespace Ui {
class Talking;
}

class Talking : public QWidget
{
    Q_OBJECT

public:
    explicit Talking(QWidget *parent = 0);
    ~Talking();

private:
    Ui::Talking *ui;
};

#endif // TALKING_H
