#pragma once

#include "../User/User.h"

using namespace Domain;
namespace Domain {
    class Manager : public User {
    public:
        ///Constructor
        explicit Manager(const string &username = "0", const string &password = "0");

        ///Copy constructor
        Manager(const Manager &manager) = default;

        static Manager convertFromStr(string str);

        [[nodiscard]] shared_ptr<ObjectWithId> convertFromString(string user) override;
    };
}