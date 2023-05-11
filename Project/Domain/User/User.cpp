#include "User.h"

using namespace user;

User::User(string username, string password) {
    this->username = username;
    this->password = password;
}

string User::getUsername() { return username; }

string User::getPassword() { return password; }

void User::setUsername(string username) {
    this->username = username;
}

void User::setPassword(string password) {
    this->password = password;
}