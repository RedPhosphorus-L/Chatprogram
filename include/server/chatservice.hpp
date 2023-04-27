#ifndef CHATSERVICE_H
#define CHATSERVICE_H
#include "usermodel.hpp"
#include <muduo/net/TcpConnection.h>
#include <unordered_map>
#include <functional>
#include "json.hpp"
#include <mutex>
#include "offlinemessagemodel.hpp"
#include "friendmodel.hpp"
#include "groupmodel.hpp"
#include "redis.hpp"
using json = nlohmann::json;
using namespace std;
using namespace muduo;
using namespace muduo::net;

using MsgHandler = std::function<void(const TcpConnectionPtr &conn, json &js, Timestamp)>;
// 聊天服务器业务类 单例模式

class ChatService
{
public:
    // 获取单例对象
    static ChatService *instance();
    // 处理登陆
    void login(const TcpConnectionPtr &conn, json &js, Timestamp time);
    // 处理注册
    void reg(const TcpConnectionPtr &conn, json &js, Timestamp);
    // 获取消息对应的处理器
    MsgHandler getHandler(int msgid);
    // 处理客户端异常退出
    void clientCloseException(const TcpConnectionPtr &conn);
    // 服务器异常 业务重置
    void reset();
    // 一对一聊天
    void oneChat(const TcpConnectionPtr &conn, json &js, Timestamp time);
    // 添加好友
    void addFriend(const TcpConnectionPtr &conn, json &js, Timestamp time);

    void createGroup(const TcpConnectionPtr &conn, json &js, Timestamp time);

    void addGroup(const TcpConnectionPtr &conn, json &js, Timestamp time);

    void groupChat(const TcpConnectionPtr &conn, json &js, Timestamp time);

    void loginout(const TcpConnectionPtr &conn, json &js, Timestamp time);

    void handleRedisSubscribeMessage(int userid, string msg);

private:
    ChatService();
    unordered_map<int, MsgHandler> _msgHandlerMap;

    // 存储在线用户的通信连接
    unordered_map<int, TcpConnectionPtr> _userConnMap;
    UserModel _usermodel;
    // 定义互斥所,保证_userConnMap的线程安全
    mutex _connMutex;
    OfflineMsgModel _offlineMsgModel;
    FriendModel _friendModel;
    GroupModel _groupModel;

    Redis _redis;
};

#endif