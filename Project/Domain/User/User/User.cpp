#include "User.h"

#include <utility>
#include <sstream>

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

shared_ptr<ObjectWithId> User::convertFromString(const string &user) {
    return shared_ptr<ObjectWithId>();
}

string User::getAttributes() {
    std::ostringstream oss;
    oss << "Username" << ",";
    oss << "Password";
    return oss.str();
}

