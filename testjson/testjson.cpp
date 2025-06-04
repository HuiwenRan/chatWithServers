#include "../json.hpp"
using json = nlohmann::json;

#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

void func1()
{
    json js;
    js["msg_type"] = 2;
    js["from"] = "zhangsan";
    js["to"] = "lisi";
    js["msg"] = "hello";
    string sendBuf = js.dump();
    cout << sendBuf.c_str() << endl;
}

int main()
{
    func1();
}