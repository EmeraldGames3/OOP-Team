#include "Client.h"

#include <utility>

using namespace Domain;

///Constructor
Client::Client(string username, string password) : User(std::move(username), std::move(password)) {
    reservedScooters = vector<shared_ptr<ElectricScooter>>();
}

void Client::reserveScooter(const shared_ptr<ElectricScooter> &electricScooter) {
    reservedScooters.push_back(electricScooter);
}

bool Client::freeScooter(const shared_ptr<ElectricScooter> &electricScooter) {
    for (int i = 0; i < this->reservedScooters.size(); i++) {
        if (this->reservedScooters[i]->getId() == electricScooter->getId()) {
            this->reservedScooters.erase(this->reservedScooters.begin() + i);
            return true;
        }
    }
    return false;
}
