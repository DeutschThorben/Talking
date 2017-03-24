#include "userinformation.h"

UserInformation::UserInformation(QString name, QString keyword, QObject *parent)
: QObject(parent)
, m_userName(name)
, m_userKeyword(keyword)
{

}

/*
 *  getUserID
 *  Introduction: get ID of user
 *  ReturnValue: UserID
 */
int UserInformation::getUserID()
{
    return this->m_userID;
    // getUserID   <-Introduction
}

/*
 *  getUserName
 *  Introduction: get name of user
 *  ReturnValue: UserName
 */
QString UserInformation::getUserName()
{
    return this->m_userName;
    // getUserName   <-Introduction
}

/*
 *  getUserKeyword
 *  Introduction: get keyword of user
 *  ReturnValue: UserKeyword
 */
QString UserInformation::getUserKeyword()
{
    return this->m_userKeyword;
    // getUserKeyword   <-Introduction
}

/*
 *  getUserState
 *  Introduction: get state of user
 *  ReturnValue: UserState
 */
QString UserInformation::getUserState()
{
    return this->m_userState;
    // getUserState   <-Introduction
}


