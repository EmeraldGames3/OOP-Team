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

Client Client::convertFromStr(string str) {
    vector<std::string> tokens;
    size_t pos = 0;
    string delimiter = ",";

    while ((pos = str.find(delimiter)) != std::string::npos) {
        std::string token = str.substr(0, pos);
        tokens.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    // The remaining part after the last delimiter
    tokens.push_back(str);

    return Client(tokens[0], tokens[1]);
}
