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
    User_CreateFriendList,
    User_FriendList
};

struct Package {
    PackageType head;
    char name[20];
    char keyword[10];
    char otherUser[20];
    char message[60];
    int result;
};

struct ShowFriendList {
    PackageType head;
    char f_name[20][20];
    int f_state[20];
    int i;
};

#endif // PACKAGE

