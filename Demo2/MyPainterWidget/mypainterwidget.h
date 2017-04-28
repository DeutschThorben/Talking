#ifndef MYPAINTERWIDGET_H
#define MYPAINTERWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include <QFontDatabase>
#include <ctime>

namespace Ui {
class MyPainterWidget;
}

class MyPainterWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyPainterWidget(QWidget *parent = 0);
    ~MyPainterWidget();

    QPixmap onQPixmapChange(int);

    int getRandNumber(int, int);

    void onQStringQFontSet();

private slots:
    void onBtnOkClicked();
    void onBtnClearClicked();

private:
    Ui::MyPainterWidget *ui;
    QString word;

    void onDrawText(QPainter, QImage);
    void onDrawLine(QPainter);
    void onDrawArc(QPainter);

    void createWord();
};

#endif // MYPAINTERWIDGET_H
