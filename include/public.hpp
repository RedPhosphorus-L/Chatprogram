#ifndef PUBLIC_H
#define PUBLIC_H

// server和client的公共头文件

enum EnMsgType
{
    LOGIN_MSG = 1,
    LOGIN_MSG_ACK,
    REG_MSG,
    REG_MSG_ACK,
    ONE_CHAT_MSG,
    ADD_FRIEND_MSG, // 添加好友

    CREATE_GROUP_MSG,
    ADD_GROUP_MSG,
    GROUP_CHAT_MSG,
    LOGINOUT_MSG, // 注销
};

#endif