#pragma once

#include "../User/User.h"
#include "../../ElectricScooter/ElectricScooter.h"
#include <vector>
#include <memory>

using namespace Domain;

namespace Domain {
    class Client : public User {
    private:
        vector<shared_ptr<ElectricScooter>> reservedScooters;

    public:
        ///Default constructor
        explicit Client(string username = "0", string password = "0");

        ///Copy constructor
        Client(const Client &client) = default;

        void reserveScooter(const shared_ptr<ElectricScooter>& electricScooter);

        bool freeScooter(const shared_ptr<ElectricScooter>& electricScooter);

        static Client convertFromStr(string str);
    };
}