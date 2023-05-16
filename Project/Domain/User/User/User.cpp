#include "User.h"

#include <utility>

using namespace Domain;

///Constructor
User::User(string _username, string _password) {
    username = std::move(_username);
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
}

///Password setter
///@details can be overloaded
void User::setPassword(const string &newPassword) {
    password = newPassword;
}