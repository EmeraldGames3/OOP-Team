#include "User.h"

#include <utility>
#include <memory>
#include <sstream>
#include <vector>

using namespace Domain;

///Constructor
User::User(string _username, string _password) {
    username = std::move(_username);
    identifier = username;
    password = std::move(_password);
}

///Username getter
///@details can be overloaded
string User::getUsername() const { return username; }

///Password getter
///@details can be overloaded
string User::getPassword() const { return password; }

///Username setter
///@details can be overloaded
void User::setUsername(const string &newUsername) {
    username = newUsername;
    identifier = username;
}

///Password setter
///@details can be overloaded
void User::setPassword(const string &newPassword) {
    password = newPassword;
}

///Override id setter
void User::setId(const string &newID) {
    setUsername(newID);
}

string User::toString() {
    std::ostringstream oss;
    oss << username << ",";
    oss << password;
    return oss.str();
}

shared_ptr<ObjectWithId> User::convertFromString(string user) {
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

    return std::make_shared<User>(User(tokens[0], tokens[1]));
}

string User::getAttributes() {
    std::ostringstream oss;
    oss << "Username" << ",";
    oss << "Password";
    return oss.str();
}