#include <iostream>
#include <string>

#pragma once
using namespace std;
namespace Domain {
    ///This class represents a generic user
    class User {
    protected:
        string username;
        string password;

    public:
        ///Constructor
        User(string _username, string _password);

        ///Getters
        [[nodiscard]] virtual string getUsername() const;
        [[nodiscard]] virtual string getPassword() const;

        ///Setters
        virtual void setUsername(const string &newUsername);
        virtual void setPassword(const string &newPassword);
    };
}
