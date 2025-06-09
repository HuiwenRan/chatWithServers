#pragma once

#include <vector>
#include "json.hpp"

using json = nlohmann::json;

class FriendModel
{
private:
public:
    bool insert(int userid, int friendid);
    bool remove(int userid, int friendid);
    std::vector<json> query(int userid);
};