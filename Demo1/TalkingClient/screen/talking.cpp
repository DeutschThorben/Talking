#include "talking.h"
#include "ui_talking.h"

Talking::Talking(QString name, QString otherName, QWidget *parent) :
    QWidget(parent),
    m_name(name),
    f_name(otherName),
    ui(new Ui::Talking)
{
    ui->setupUi(this);
}

Talking::~Talking()
{
    delete ui;
}
