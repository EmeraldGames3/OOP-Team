#include "User.h"

#include <utility>

using namespace Domain;

User::User(string _username, string _password) {
    username = std::move(_username);
    password = std::move(_password);
}

string User::getUsername() { return username; }

string User::getPassword() { return password; }

void User::setUsername(const string &newUsername) {
    username = newUsername;
}

void User::setPassword(const string &newPassword) {
    password = newPassword;
}