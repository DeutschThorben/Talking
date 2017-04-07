#ifndef MAKEMASSES_H
#define MAKEMASSES_H

#include <QWidget>

namespace Ui {
class MakeMasses;
}

class MakeMasses : public QWidget
{
    Q_OBJECT

public:
    explicit MakeMasses(QWidget *parent = 0);
    ~MakeMasses();

private:
    Ui::MakeMasses *ui;
};

#endif // MAKEMASSES_H
