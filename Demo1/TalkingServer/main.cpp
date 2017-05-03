#include "talkingserver.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TalkingServer w;
    w.show();

    return a.exec();
}
