#pragma once

#include "../User/User.h"
#include "../../ElectricScooter/ElectricScooter.h"
#include <vector>
#include <memory>

using namespace Domain;

#define NULL_SCOOTER_ID "---"

namespace Domain {
    class Client : public User {
    private:
        vector<ElectricScooter> reservedScooters;
        ElectricScooter scooterInUse;

    public:
        ///Default constructor
        explicit Client(string username = "0", string password = "0");

        ///Copy constructor
        Client(const Client &client) = default;

        ///Check if a client is already on a ride
        [[nodiscard]] bool isOnRide() { return scooterInUse.getId() != NULL_SCOOTER_ID; }
        [[nodiscard]] ElectricScooter getScooterInUse() { return scooterInUse; }

        ///Manipulate the reserved scooters of this client
        [[nodiscard]] bool reserveScooter(const ElectricScooter &electricScooter);
        [[nodiscard]] bool freeScooter(const ElectricScooter &electricScooter);
        [[nodiscard]] vector<ElectricScooter> getReservedScooters();

        ///Use a scooter
        [[nodiscard]] bool useScooter(const ElectricScooter &electricScooter);

        [[nodiscard]] shared_ptr<ObjectWithId> convertFromString(string user);

        ///Get a client from a string
        static Client convertFromStr(string str);
    };
}