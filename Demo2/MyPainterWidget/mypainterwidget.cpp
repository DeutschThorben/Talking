#include "mypainterwidget.h"
#include "ui_mypainterwidget.h"

MyPainterWidget::MyPainterWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyPainterWidget)
{
    ui->setupUi(this);

//    createWord();

    onQStringQFontSet();
    connect(ui->btn_ok, SIGNAL(clicked()), this, SLOT(onBtnOkClicked()));
    connect(ui->btn_clear, SIGNAL(clicked()), this, SLOT(onBtnClearClicked()));
}

MyPainterWidget::~MyPainterWidget()
{
    disconnect(ui->btn_ok, SIGNAL(clicked()), this, SLOT(onBtnOkClicked()));
    disconnect(ui->btn_clear, SIGNAL(clicked()), this, SLOT(onBtnClearClicked()));
    delete ui;
}

QPixmap MyPainterWidget::onQPixmapChange(int num)
{
    QSize size(100, 100);
    QImage image(size, QImage::Format_ARGB32);
    image.fill(qRgba(0,0,0,0));
    QPainter painter(&image);
    painter.setCompositionMode(QPainter::CompositionMode_Source);

    QPen pen = painter.pen();
//    painter.setPen(QColor(0, 160, 230));
    pen.setColor(Qt::red);


    QFont font = painter.font();
    font.setFamily("Microsoft YaHei");
    font.setBold(true);
    font.setItalic(true);
    font.setPixelSize(num);

    painter.setPen(pen);
    painter.setFont(font);

    painter.setRenderHint(QPainter::Antialiasing, true);

    // draw a length
//    QRectF rect(10.0, 0.0, 121.0, 41.0);
//    int startAngel = 120 * 16;
//    int spanAngel = 120 * 16;
//    painter.drawArc(rect, startAngel, spanAngel);

//    onDrawArc(painter);

    // draw text
    painter.drawText(image.rect(), Qt::AlignCenter, word);
//    onDrawText(painter, image);

    // draw line
//    painter.drawLine(QPointF(12, 11), QPointF(ui->label_image->width()/2, ui->label_image->height()));
//    onDrawLine(painter);

    QPixmap img = QPixmap::fromImage(image);
    QPixmap fitPixmap = img.scaled(ui->label_image->width()/2, ui->label_image->height()/2, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    return fitPixmap;
}

void MyPainterWidget::onBtnOkClicked()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    ui->label_image->clear();
    word = ui->lineEdit_word->text();
    QPixmap fitPixmap = onQPixmapChange(30);
    ui->label_image->setPixmap(QPixmap(fitPixmap));

    QPixmap aaa = onQPixmapChange(50);
    ui->label_image->setPixmap(QPixmap(aaa));
    qDebug("[%s] 1111", __PRETTY_FUNCTION__);
}

void MyPainterWidget::onBtnClearClicked()
{
    ui->label_image->clear();
}

int  MyPainterWidget::getRandNumber(int num, int minNum)
{
    int rand_num = 0;
    srand((unsigned)time(0));
    rand_num = rand() % num;

    if (rand_num < minNum) {
        rand_num = rand_num + minNum;
    }
    qDebug("[%s] num is [%d]", __PRETTY_FUNCTION__, rand_num);
    return rand_num;
}

void MyPainterWidget::onDrawLine(QPainter m_painter)
{
    m_painter.drawLine(QPointF(getRandNumber(ui->label_image->width(), 3), getRandNumber(ui->label_image->height(), 10)), QPointF(getRandNumber(ui->label_image->width(), 3), getRandNumber(ui->label_image->height(), 10)));
}

void MyPainterWidget::onDrawText(QPainter m_painter, QImage m_image)
{
    m_painter.drawText(m_image.rect(), Qt::AlignCenter, word);
}

void MyPainterWidget::onDrawArc(QPainter m_painter)
{
    QRectF rect(10.0, 0.0, 121.0, 41.0);
    // set startAngel of [50, 90)
    int startAngel = getRandNumber(90, 50) * 16;
    // set spanAngel of [50, 170)
    int spanAngel = getRandNumber(170, 50) * 16;
    // draw the Acr
    m_painter.drawArc(rect, startAngel, spanAngel);
}

void MyPainterWidget::createWord()
{
//    char a = 50;
//    qDebug("[%s] socket is [%s]", __PRETTY_FUNCTION__, a);

}

void MyPainterWidget::onQStringQFontSet()
{
    QString mmm = "sss";
    QFont font1;
    font1.setBold(true);
    font1.setWeight(50);

    ui->label_image->setFont(font1);
    ui->lineEdit_word->setFont(font1);
//    ui->label_image->setText(mmm);



    ui->label_image_2->setText(ui->label_image->text());
}
