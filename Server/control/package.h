#ifndef PACKAGE
#define PACKAGE

#include <QString>

enum PackageType {
    EMPTY = 0,
    USER_Regist,
    USER_Login,
    USER_Login_IsSameName,
    USER_Talking,
    USER_TalkingAll,
};

struct Package {
    PackageType head;
    QString name;
    QString otherUser;
    QString keyword;
    QString talkingInformation;
    int result;
};

#endif // PACKAGE

