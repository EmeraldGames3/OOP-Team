#pragma once

#include "../User/User.h"

using namespace Domain;

namespace Domain {
    class Client : public User {
    public:
        ///Default constructor
        explicit Client(string username = "0", string password = "0");

        ///Copy constructor
        Client(const Client &client) = default;
    };
}