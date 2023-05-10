#pragma once

#include <string>

using std::string;

namespace Domain{
    class User{
    protected:
        string username;
        string password;

    public:
        User(const string &_username, const string &_password);

        virtual string getUsername();

        virtual string getPassword();

        virtual void setUsername(string username) = 0;

        virtual void setPassword(string password) = 0;
    };
}