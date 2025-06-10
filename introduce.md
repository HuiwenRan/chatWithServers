# 多服务器聊天使用说明

## 1.  消息格式说明
1. 注册{"msgid":1,"name":"lisi","password":"lisi"}
2. 登录
    {"msgid":2,"id":22,"password":"zhangsan"}
    {"msgid":2,"id":23,"password":"lisi"}
3. 发送消息{"msgid":3,"id":22,"name":"zhangsan","toid":23,"msg":"hello","time":"2019-05-23 12:00"}
4. 添加朋友{"msgid":4,"id":22,"friendid":23}
5. 创建群聊{"msgid":5,"id":22,"groupname":"group1","groupdesc":"this is description"}
6. 加入群聊{"msgid":6,"id":23,"groupid":2}
7. 发送群聊消息{"msgid":7,"id":22,"from":"zhangsan","groupid":2,"msg":"hello","time":"2019-05-23 12:00"}
