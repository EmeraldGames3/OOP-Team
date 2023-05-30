#include "ElectricScooterController.h"

#include <utility>
#include <algorithm>

ElectricScooterController::ElectricScooterController(shared_ptr<CrudRepository<ElectricScooter>> repo)
        : repository(std::move(repo)) {}

///Add a new scooter to the data Base
void ElectricScooterController::add(
        string id, string model, const string &date, float mileage, string location, string condition
) {
    repository->create(ElectricScooter(std::move(id), std::move(model),
                                       date, mileage, std::move(location),
                                       std::move(condition)));
}

///Remove a scooter from the Data Base
///@throws invalid_argument if the identifier of the scooter to be removed does not exist
void ElectricScooterController::remove(const string &id) {
    ElectricScooter scooter(id);
    if (!repository->remove(scooter))
        throw invalid_argument("Scooter does not exist");
}

///Get all scooters in the Data Base
vector<ElectricScooter> ElectricScooterController::getAll() {
    return repository->findAll();
}

///Find if a scooter exists in the Data Base
bool ElectricScooterController::find(const string &id) {
    return std::ranges::any_of(repository->findAll(), [&](const auto &scooter) {
        return scooter.getId() == id;
    });
}

///Update the model of a scooter
///@throws invalid_argument if the scooter identifier does not exist
void ElectricScooterController::updateModel(const string &model, const string &id) {
    for (const auto &it: repository->findAll()) {
        if (it.getId() == id) {
            auto updatedScooter = ElectricScooter(it);
            updatedScooter.setModel(model);
            if (!repository->update(it, updatedScooter)) {
                throw std::invalid_argument("Failed to update scooter");
            }
            return;
        }
    }

    throw std::invalid_argument("Scooter does not exits");
}

///Update the mileage of a scooter
///@throws invalid_argument if the scooter identifier does not exist
void ElectricScooterController::updateMileage(float mileage, const string &id) {
    for (const auto &it: repository->findAll()) {
        if (it.getId() == id) {
            auto updatedScooter = ElectricScooter(it);
            updatedScooter.setMileage(mileage);
            if (!repository->update(it, updatedScooter)) {
                throw std::invalid_argument("Failed to update scooter");
            }
            return;
        }
    }

    throw std::invalid_argument("Scooter does not exits");
}

///Update the identifier of a scooter
///@throws invalid_argument if the scooter identifier does not exist
void ElectricScooterController::updateID(const string &newId, const string &oldId) {
    for (const auto &it: repository->findAll()) {
        if (it.getId() == oldId) {
            auto updatedScooter = ElectricScooter(it);
            updatedScooter.setId(newId);
            if (!repository->update(it, updatedScooter)) {
                throw std::invalid_argument("Failed to update scooter");
            }
            return;
        }
    }

    throw std::invalid_argument("Scooter does not exits");
}

///Update the last location of scooter
///@throws invalid_argument if the scooter identifier does not exist
void ElectricScooterController::updateLocation(const string &location, const string &id) {
    for (const auto &it: repository->findAll()) {
        if (it.getId() == id) {
            auto updatedScooter = ElectricScooter(it);
            updatedScooter.setLocation(location);
            if (!repository->update(it, updatedScooter)) {
                throw std::invalid_argument("Failed to update scooter");
            }
            return;
        }
    }

    throw std::invalid_argument("Scooter does not exits");
}

///Update the condition of a scooter
///@throws invalid_argument if the scooter identifier does not exist
void ElectricScooterController::updateCondition(const string &condition, const string &id) {
    for (const auto &it: repository->findAll()) {
        if (it.getId() == id) {
            auto updatedScooter = ElectricScooter(it);
            updatedScooter.setCondition(condition);
            if (!repository->update(it, updatedScooter)) {
                throw std::invalid_argument("Failed to update scooter");
            }
            return;
        }
    }

    throw std::invalid_argument("Scooter does not exits");
}

///Update the commissioning Date of a scooter
///@throws invalid_argument if the scooter identifier does not exist
void ElectricScooterController::updateDate(const string &date, const string &id) {
    for (const auto &it: repository->findAll()) {
        if (it.getId() == id) {
            auto updatedScooter = ElectricScooter(it);
            updatedScooter.setDate(date);
            if (!repository->update(it, updatedScooter)) {
                throw std::invalid_argument("Failed to update scooter");
            }
            return;
        }
    }

    throw std::invalid_argument("Scooter does not exits");
}

///Filter all scooters by data
vector<ElectricScooter> ElectricScooterController::ageFiltered(Date value) {
    vector<ElectricScooter> filteredScooters;

    // Filter electric scooters based on age
    for (const ElectricScooter &scooter: getAll()) {
        if (scooter.getDate() <= value) {
            // Add the scooter to the filtered list
            filteredScooters.push_back(scooter);
        }
    }

    return filteredScooters;
}

///Get all scooters sorted by date
vector<ElectricScooter> ElectricScooterController::ageSorted() {
    vector<ElectricScooter> scooters = getAll();
    sort(scooters.begin(), scooters.end(),
         [](const ElectricScooter &a, const ElectricScooter &b) {
             return a.getDate() < b.getDate();
         });
    return scooters;
}

///Filter all scooters based on mileage
vector<ElectricScooter> ElectricScooterController::mileageFiltered(float value) {
    vector<ElectricScooter> filteredScooters;

    //Filter the scooter based on mileage
    for (const ElectricScooter &scooter: getAll()) {
        if (scooter.getMileage() <= value) {
            // Add the scooter to the filtered list
            filteredScooters.push_back(scooter);
        }
    }

    return filteredScooters;
}

///Search for a string in the last location of a scooter
vector<ElectricScooter> ElectricScooterController::lastLocationSearch(const string &location) {
    vector<ElectricScooter> matchingScooters;

    // Search for electric scooters with the specified location
    for (const auto &scooter: getAll()) {
        if (scooter.getLocation().find(location) != string::npos) {
            matchingScooters.push_back(scooter);
        }
    }
    return matchingScooters;
}

bool ElectricScooterController::reserveScooter(const string &id, Client &client) {
    for(auto &it: repository->findAll())
        if(it.getId() == id) {
            if (it.getCondition() != "Parked")
                return false;
            it.setCondition("Reserved");
            if(!repository->update(it, it)){
                return false;
            }
            if(!client.reserveScooter(it)){
                return false;
            }
            return true;
        }

    return false;
}

bool ElectricScooterController::useScooter(const string &id, Client &client) {
    if(client.isOnRide()){
        return false;
    }

    for(auto &it: repository->findAll())
        if(it.getId() == id) {
            if(it.getCondition() == "Reserved"){
                bool wasReserved = false;
                for(const auto &it2 : client.getReservedScooters()){
                    if(it2.getId() == id){
                        wasReserved = true;
                    }
                }
                if(!wasReserved){
                    return false;
                }

                it.setCondition("In_Use");
                if(!repository->update(it, it)){
                    return false;
                }

                if(!client.useScooter(it)){
                    return false;
                }

                return true;
            }

            if (it.getCondition() != "Parked")
                return false;

            it.setCondition("In_Use");
            if(!repository->update(it, it)){
                return false;
            }
            if(!client.useScooter(it)){
                return false;
            }
            return true;
        }

    return false;
}

bool ElectricScooterController::freeScooter(const string &id, Client &client) {
    if(client.isOnRide()){
        if(client.getScooterInUse().getId() == id){
            auto it = client.getScooterInUse();
            it.setCondition("Parked");
            if(!repository->update(it, it)){
                return false;
            }
            if(!client.freeScooter(it)){
                return false;
            }
            return true;
        }

        return false;
    }

    for(auto &it: repository->findAll())
        if(it.getId() == id) {
            if (it.getCondition() != "Reserved")
                return false;

            bool wasReserved = false;
            for(const auto &it2 : client.getReservedScooters()){
                if(it2.getId() == id){
                    wasReserved = true;
                    break;
                }
            }
            if(!wasReserved){
                return false;
            }

            it.setCondition("Parked");
            if(!repository->update(it, it)){
                return false;
            }
            if(!client.freeScooter(it)){
                return false;
            }
            return true;
        }

    return false;
}