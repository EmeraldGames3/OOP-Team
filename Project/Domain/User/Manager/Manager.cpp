#include "Manager.h"
#include <string>
#include <vector>

using namespace Domain;

///Constructor
Manager::Manager(const string &username, const string &password) : User(username, password) {}

Manager Manager::convertFromStr(string str) {
    vector<std::string> tokens;
    size_t pos = 0;
    string delimiter = ",";

    while ((pos = str.find(delimiter)) != std::string::npos) {
        std::string token = str.substr(0, pos);
        tokens.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    // The remaining part after the last delimiter
    tokens.push_back(str);

    return Manager(tokens[0], tokens[1]);
}

shared_ptr<ObjectWithId> Manager::convertFromString(string user) {
    vector<std::string> tokens;
    size_t pos = 0;
    string delimiter = ",";

    while ((pos = user.find(delimiter)) != std::string::npos) {
        std::string token = user.substr(0, pos);
        tokens.push_back(token);
        user.erase(0, pos + delimiter.length());
    }
    // The remaining part after the last delimiter
    tokens.push_back(user);

    return std::make_shared<Manager>(Manager(tokens[0], tokens[1]));
}