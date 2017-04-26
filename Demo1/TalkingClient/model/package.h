#ifndef PACKAGE
#define PACKAGE

enum PackageType {
    EMPTY = 0,
    User_Regist,
    User_Login,
    User_Talking,
    User_TalkingAll,
    User_IsSameName,
    User_FindFriend,
    User_StateChange,
    User_CreateFriendList
};

struct Package {
    PackageType head;
    char name[20];
    char keyword[10];
    char otherUser[20];
    char message[60];
    int result;
};

#endif // PACKAGE

