#ifndef PACKAGE
#define PACKAGE

#include <QString>

enum PackageType {
    EMPTY = 0,
    USER_Regist,
    USER_Login,
    USER_Regist_IsSameName,
    USER_Talking,
    USER_TalkingAll,
    USER_FindFriend,
    USER_Online,
    USER_Exit
};

struct Package {
    PackageType head;
    char name[20];
    char otherUser[20];
    char keyword[20];
    char talkingInformation[40];
//    QString name;
//    QString otherUser;
//    QString keyword;
//    QString talkingInformation;
    int result;
};

#endif // PACKAGE

