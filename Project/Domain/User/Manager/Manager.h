#pragma once

#include "../User/User.h"

using namespace Domain;
namespace Domain {
    class Manager : public User {
    public:
        ///Constructor
        Manager(const string &username, const string &password);
    };
}