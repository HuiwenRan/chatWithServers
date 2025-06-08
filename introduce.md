# 多服务器聊天使用说明

## 1.  消息格式说明
1. 注册{"msgid":1,"name":"lisi","password":"lisi"}
2. 登录
    {"msgid":2,"id":22,"password":"zhangsan"}
    {"msgid":2,"id":23,"password":"lisi"}
3. 发送消息{"msgid":3,"id":22,"from":"zhangsan","to":23,"msg":"hello"}