#include "mypainterwidget.h"
#include "ui_mypainterwidget.h"

MyPainterWidget::MyPainterWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyPainterWidget)
{
    ui->setupUi(this);
}

MyPainterWidget::~MyPainterWidget()
{
    delete ui;
}
