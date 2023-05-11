#include <iostream>
#include <string>

#pragma once
using namespace std;
namespace user {
    class User {
    public:
        User(string username, string password);

        string getUsername();

        string getPassword();

        void setUsername(string username);

        void setPassword(string password);

    protected:
        string username;
        string password;
    };
}
