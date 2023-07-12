# Chatprogram
一个高性能聊天服务器
## compile
cd build/

cmake ..

make
## 技术点
* 基于muduo网络库提高高并发网络IO服务。
* 使用json序列化与反序列化作为通信协议。
* 配置nginx基于tcp的负载均衡功能，实现聊天服务器集群功能。
* 基于redis的发布订阅功能完成跨服务器通信。
* 使用mysql关系型数据库存储。
* 使用连接池提高数据库的数据存取性能。
* 基于Quora's Poe逆向工程，向Poe发送HTTP请求，实现用户与ChatGPT等机器人的对话。
