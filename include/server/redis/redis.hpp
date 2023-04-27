#ifndef REDIS_H
#define REDIS_H

#include <hiredis/hiredis.h>
#include <thread>
#include <functional>
using namespace std;


class Redis
{
public:
    Redis();
    ~Redis();
    bool connect();

    bool publish(int channel,string message);

    bool subcribe(int channel);

    bool unsubcribe(int channel);

    void observer_channel_message();

    //初始化
    void init_notify_handler(function<void(int,string)> fn);

private:
    redisContext* _publish_context;
    redisContext* _subcribe_context;

    //收到订阅的消息，给service上报
    function<void(int,string)> _notify_message_handler;
};



#endif