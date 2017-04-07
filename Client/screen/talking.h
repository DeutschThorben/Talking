#ifndef TALKING_H
#define TALKING_H

#include <QWidget>
#include <QMessageBox>

#include "model/package.h"
#include "model/clientcommon.h"

namespace Ui {
class Talking;
}

class Talking : public QWidget
{
    Q_OBJECT

public:
    explicit Talking(QTcpSocket *sockfd, QString name, QString otherName, QWidget *parent = 0);
    ~Talking();


private slots:
    void onFeedBackTalking();

    void onSendMessageToServerClicked();

private:
    Ui::Talking *ui;
    ClientCommon *m_clientCommon;
    QTcpSocket *m_socked;
    QString m_name;
    QString m_otherName;
};

#endif // TALKING_H
