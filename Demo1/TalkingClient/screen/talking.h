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
    explicit Talking(QString name, QString otherName, QWidget *parent = 0);
    ~Talking();

private:
    QString m_name;
    QString f_name;
    Ui::Talking *ui;
};

#endif // TALKING_H
