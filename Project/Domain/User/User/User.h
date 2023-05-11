#include <iostream>
#include <string>

#pragma once
using namespace std;
namespace Domain {
    class User {
    protected:
        string username;
        string password;

    public:
        User(string _username, string _password);

        string getUsername();

        string getPassword();

        void setUsername(const string &newUsername);

        void setPassword(const string &newPassword);
    };
}
