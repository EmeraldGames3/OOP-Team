#pragma once

#include <iostream>
#include <string>
#include "../../ObjectWithID.h"

using namespace std;
namespace Domain {
    ///This class represents a generic user
    class User : public  ObjectWithId{
    protected:
        string username;
        string password;

    public:
        ///Constructor
        explicit User(string _username = "0", string _password = "0");

        ///Copy constructor
        User(const User &user) = default;

        ///Getters
        [[nodiscard]] virtual string getUsername() const;
        [[nodiscard]] virtual string getPassword() const;

        ///Setters
        virtual void setUsername(const string &newUsername);
        virtual void setPassword(const string &newPassword);

        ///We consider that username == id for this type of object
        void setId(const string &newID) override;

        string toString() override;

        shared_ptr<ObjectWithId> convertFromString(const string &user) override;

        string getAttributes() override;
    };
}
