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
    explicit Talking(QString name, QString otherName, QWidget *parent = 0);
    ~Talking();

    void MessageFromOther(QString);

private slots:
    void onSendMessageToServerClicked();
    void onWordOverStriking();
    void onWordColorChange();

protected:
    virtual void closeEvent(QCloseEvent *);

private:
    Ui::Talking *ui;
    ClientCommon *m_clientCommon;
    QString m_name;
    QString m_otherName;
    QString m_message;
};

#endif // TALKING_H
