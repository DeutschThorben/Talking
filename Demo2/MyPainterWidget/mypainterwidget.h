#ifndef MYPAINTERWIDGET_H
#define MYPAINTERWIDGET_H

#include <QWidget>

namespace Ui {
class MyPainterWidget;
}

class MyPainterWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyPainterWidget(QWidget *parent = 0);
    ~MyPainterWidget();

private:
    Ui::MyPainterWidget *ui;
};

#endif // MYPAINTERWIDGET_H
