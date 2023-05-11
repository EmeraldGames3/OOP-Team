#pragma once
#include "../User/User.h"

using namespace Domain;

namespace Domain {
    class Client : public User {
    public:
        Client(string username, string password);
    };
}