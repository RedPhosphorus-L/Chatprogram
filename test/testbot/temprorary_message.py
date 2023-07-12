import poe
import logging
import sys


#send a message and immediately delete it

# token是用浏览器接入poe.com时获得的token
# 获取方式为：科学上网 -> https://poe.com/ -> F12打开dev tools -> 
# applications -> cookies -> https://poe.com/ -> p-b对应的value
# 隔一段时间会更新
token="0TQbbyE4n_11vRAM3TBcVg%3D%3D"
proxy_="http://192.168.31.167:7890"

# 关闭log INFO
# poe.logger.setLevel(logging.INFO)

# poe需要科学上网才能访问，所以需要设置代理proxy
# 这台ubuntu18.04时虚拟机，windows上运行了clash代理工具
# 打开windows上的clash，进入general选项
# 记下Port(7890)，打开Allow LAN，关闭System Proxy
# clash中获取WLAN的ip (192.168.31.178)
client = poe.Client(token,proxy=proxy_)
print(client.bot_names)

message="What can you do"
reply= ""

for chunk in client.send_message("capybara", message, with_chat_break=True):
  print(chunk["text_new"], end="", flush=True)
  reply += chunk["text_new"]

print('\n')
print(reply)

#delete the 3 latest messages, including the chat break
# client.purge_conversation("capybara", count=3)