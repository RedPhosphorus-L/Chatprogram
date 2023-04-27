#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
#include <iostream>
#include<functional>
#include <string>
using namespace std;
using namespace placeholders;
using namespace muduo;
using namespace muduo::net;
/*
TcpServer:
TcpClient:
epoll+线程池
业务代码:  用户的连接和断开  用户的可读写事件
*/


/*
1\crate some object
2\ create Eventobject prior
3\ know canshu
4\ register
*/
class ChatServer
{
private:
    TcpServer _server;
    EventLoop* _loop;

private:
    void onConnection(const TcpConnectionPtr& conn){
        if(conn->connected()){
            cout<<conn->peerAddress().toIpPort()<<"->"<<conn->localAddress().toIpPort()<<"state:online"<<endl;
        }
        else{
            cout<<conn->peerAddress().toIpPort()<<"->"<<conn->localAddress().toIpPort()<<"state:offline"<<endl;
            conn->shutdown();//close(fd)
            //_loop->quit();
        }
        
    }

    void onMessage(const TcpConnectionPtr& conn,
                            Buffer* buff,
                            Timestamp time){
        string buf=buff->retrieveAllAsString();
        cout<<"recv data:"<<buf<<"time: "<<time.toString()<<endl;
        conn->send(buf);
                            
    }
public:
    ChatServer(EventLoop* loop,
                const InetAddress &listenAddr,
                const string& nameArg)
            :_server(loop,listenAddr,nameArg),_loop(loop){
    //给服务器注册用户连接的创建和断开回调
    _server.setConnectionCallback(std::bind(&ChatServer::onConnection,this,_1));
    //给服务器注册用户读写事件回调
    _server.setMessageCallback(std::bind(&ChatServer::onMessage,this,_1,_2,_3));
    //设置服务器端线程数量,1 I/O线程 3个worker线程
    _server.setThreadNum(4);

    }
    void start(){
        _server.start();
    }
    ~ChatServer(){

    }
};

int main(){
    EventLoop loop;
    InetAddress addr("192.168.31.138",6000);
    ChatServer server(&loop,addr,"ChatServer");
    server.start();
    loop.loop();//epoll_wait 以阻塞的方式等待新用户连接活在已连接用户的读写事件.
    return 0;
}