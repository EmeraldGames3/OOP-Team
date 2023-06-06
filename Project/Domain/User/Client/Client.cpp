#include "Client.h"

#include <utility>

using namespace Domain;

///Constructor
Client::Client(string username, string password) : User(std::move(username), std::move(password)) {
    reservedScooters = vector<ElectricScooter>();
    scooterInUse = ElectricScooter(NULL_SCOOTER_ID);
}

bool Client::reserveScooter(const ElectricScooter &electricScooter) {
    for(const auto &it: reservedScooters){
        if(it.getId() == electricScooter.getId()){
            return false;
        }
    }

    reservedScooters.push_back(electricScooter);
    return true;
}

bool Client::useScooter(const ElectricScooter &electricScooter) {
    if(scooterInUse.getId() != NULL_SCOOTER_ID){
        return false;
    }

    scooterInUse = electricScooter;
    return true;
}

bool Client::freeScooter(const ElectricScooter &electricScooter) {
    if(electricScooter.getId() == scooterInUse.getId()){
        scooterInUse = ElectricScooter(NULL_SCOOTER_ID);
        return true;
    }

    for (int i = 0; i < this->reservedScooters.size(); i++) {
        if (this->reservedScooters[i].getId() == electricScooter.getId()) {
            this->reservedScooters.erase(this->reservedScooters.begin() + i);
            return true;
        }
    }
    return false;
}

vector<ElectricScooter> Client::getReservedScooters() {
    return reservedScooters;
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

shared_ptr<ObjectWithId> Client::convertFromString(string user) {
    vector<std::string> tokens;
    size_t pos = 0;
    string delimiter = ",";

    while ((pos = user.find(delimiter)) != std::string::npos) {
        std::string token = user.substr(0, pos);
        tokens.push_back(token);
        user.erase(0, pos + delimiter.length());
    }
    // The remaining part after the last delimiter
    tokens.push_back(user);

    return std::make_shared<Client>(Client(tokens[0], tokens[1]));
}
