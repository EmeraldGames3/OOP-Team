#pragma once

#include "../User/User.h"

using namespace Domain;

namespace Domain {
    class Client : public User {
    public:
        ///Default constructor
        Client(string username, string password);
    };
}