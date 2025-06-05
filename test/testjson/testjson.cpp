#include "../json.hpp"
using json = nlohmann::json;

#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
// json底层就是使用的hash表，和unordered_map类似
// 所以存储顺序与定义的顺序不一致
// map需要提前指定类型，json键必须为字符串，值范围内随意
/*
json内容可以为：
    字符串(必须为双引号)
    整数
    bool
    null(cpp中使用nullptr)
    嵌套对象(可以直接赋值给map对象)
    数组（可以直接赋值给vector）
*/
// 接受json字符串char*，然后反序列化为对象，进行数据处理
// json变为string类型，string变为char*，然后发送

// 1. 序列化，产生json对象进而成为字符串
// 1.1 直接产生
json getJsonDirect()
{
    json js;
    js["msg_type"] = 2;
    js["isValid"] = true;
    js["change"] = nullptr;
    js["from"] = "zhangsan";
    js["to"] = {"lisi", "wanwu"};                       // 数组
    js["msg"] = {{"head", "hello"}, {"body", "world"}}; // 双层的{}且内部元素就两个且键为非重复字符串时就是嵌套对象
    // 等价于下面
    // js["msg"]["head"] = "hello";
    // js["msg"]["body"] = "world";
    string s = js.dump(); // json变为string类型，string变为char*，然后发送
    cout << s.c_str() << endl;
    return js;
}

// 1.2 从结构体/类转换，调用to_json
struct Person
{
    string name;
    int age;
};
void to_json(json &j, const Person &p)
{
    j = json{{"name", p.name}, {"age", p.age}};
}

json getJsonFromClass()
{
    Person person{"zhangsan", 3};
    json js = person;
    cout << js << endl;
    return js;
}

// 1.3 从容器转换
json getJsonFromSTL()
{
    vector<string> v{"name", "lisi"};
    json js = v;
    cout << js << endl;
    return js;
}

// 2. 反序列化，从json字符串解析为c++对象
void parse(string &s)
{
    json js = json::parse(s);
    cout << js << endl;
    string sender = js["from"];
    vector<string> reciever = js["to"];
    map<string, string> message = js["msg"];
    cout << sender << endl;
    for (auto &i : reciever)
    {
        cout << i << endl;
    }
    for (auto &i : message)
    {
        cout << i.first << " : " << i.second << endl;
    }
    return;
}

int main()
{
    json js1 = getJsonDirect();
    json js2 = getJsonFromClass();
    json js3 = getJsonFromSTL();
    string s1 = js1.dump();
    parse(s1);
}