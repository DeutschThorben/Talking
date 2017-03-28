#include "talking.h"
#include "ui_talking.h"

Talking::Talking(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Talking)
{
    ui->setupUi(this);
}

Talking::~Talking()
{
    delete ui;
}
