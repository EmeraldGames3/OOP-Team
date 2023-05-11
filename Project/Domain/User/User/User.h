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

        virtual string getUsername();

        virtual string getPassword();

        virtual void setUsername(const string &newUsername);

        virtual void setPassword(const string &newPassword);
    };
}
