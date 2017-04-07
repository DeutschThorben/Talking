#include "makemasses.h"
#include "ui_makemasses.h"

MakeMasses::MakeMasses(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MakeMasses)
{
    ui->setupUi(this);
}

MakeMasses::~MakeMasses()
{
    delete ui;
}
