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

        [[nodiscard]] virtual string getUsername() const;

        [[nodiscard]] virtual string getPassword() const;

        virtual void setUsername(const string &newUsername);

        virtual void setPassword(const string &newPassword);
    };
}
