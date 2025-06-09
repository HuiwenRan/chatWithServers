# 多服务器聊天使用说明

## 1.  消息格式说明
1. 注册{"msgid":1,"name":"lisi","password":"lisi"}
2. 登录
    {"msgid":2,"id":22,"password":"zhangsan"}
    {"msgid":2,"id":23,"password":"lisi"}
3. 发送消息{"msgid":3,"id":22,"from":"zhangsan","to":23,"msg":"hello"}
4. 添加朋友{"msgid":4,"id":22,"friendId":23}
5. 创建群聊{"msgid":5,"id":22,"groupName":"group1","groupDesc":"this is description"}
6. 加入群聊{"msgid":6,"id":23,"groupId":2}
7. 发送群聊消息{"msgid":7,"id":22,"from":"zhangsan","groupId":2,"msg":"hello"}
