#include "ElectricScooterController.h"

#include <utility>

using namespace Controller;
using namespace Domain;

///Constructor with default parameters
ElectricScooterController::ElectricScooterController(shared_ptr<ElectricScooterRepository> repo) {
    repository = repo;
}

///Add a new scooter to the data Base
void ElectricScooterController::add(
        string id, string model, const string &date, float mileage, string location, string condition
) {
    ElectricScooter scooter(std::move(id), std::move(model), date, mileage,
                            std::move(location), std::move(condition));
    repository->add(scooter);
}

///Remove a scooter from the Data Base
///@throws invalid_argument if the identifier of the scooter to be removed does not exist
void ElectricScooterController::remove(const string &id) {
    if (!find(id))
        throw invalid_argument("");
    ElectricScooter scooter(id);
    repository->remove(scooter);
}

///Get all scooters in the Data Base
vector<ElectricScooter> ElectricScooterController::getAll() {
    return repository->getAll();
}

///Find if a scooter exists in the Data Base
bool ElectricScooterController::find(const string &id) {
    vector<ElectricScooter> scooters = getAll();
    for (auto &scooter: scooters)
        if (scooter.getId() == id)
            return true;
    return false;
}

///Update the model of a scooter
///@throws invalid_argument if the scooter identifier does not exist
void ElectricScooterController::updateModel(const string &model, const string &id) {
    if (!find(id))
        throw invalid_argument("");
    repository->updateModel(model, id);
}

///Update the mileage of a scooter
///@throws invalid_argument if the scooter identifier does not exist
void ElectricScooterController::updateMileage(float mileage, const string &id) {
    if (!find(id))
        throw invalid_argument("");
    repository->updateMileage(mileage, id);
}

///Update the identifier of a scooter
///@throws invalid_argument if the scooter identifier does not exist
void ElectricScooterController::updateID(const string &id, const string &oldId) {
    if (!find(oldId))
        throw invalid_argument("");
    repository->updateID(id, oldId);
}

///Update the last location of scooter
///@throws invalid_argument if the scooter identifier does not exist
void ElectricScooterController::updateLocation(const string &location, const string &id) {
    if (!find(id))
        throw invalid_argument("");
    repository->updateLocation(location, id);
}

///Update the condition of a scooter
///@throws invalid_argument if the scooter identifier does not exist
void ElectricScooterController::updateCondition(const string &condition, const string &id) {
    if (!find(id))
        throw invalid_argument("");
    repository->updateCondition(condition, id);
}

///Update the commissioning Date of a scooter
///@throws invalid_argument if the scooter identifier does not exist
void ElectricScooterController::updateDate(const string &date, const string &id) {
    if (!find(id))
        throw invalid_argument("");
    repository->updateDate(date, id);
}

///Filter all scooters by data
vector<ElectricScooter> ElectricScooterController::ageFiltered(Date value) {
    vector<ElectricScooter> scooters = getAll();
    vector<ElectricScooter> filteredScooters;

    // Filter electric scooters based on age
    for (ElectricScooter scooter: scooters) {
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
    sort(scooters.begin(), scooters.end(), [](ElectricScooter a, ElectricScooter b) {
        return a.getDate() < b.getDate();
    });
    return scooters;
}

///Filter all scooters based on mileage
vector<ElectricScooter> ElectricScooterController::mileageFiltered(float value) {
    vector<ElectricScooter> scooters = getAll();
    vector<ElectricScooter> filteredScooters;

    //Filter the scooter based on mileage
    for (const ElectricScooter &scooter: scooters) {
        if (scooter.getMileage() <= value) {
            // Add the scooter to the filtered list
            filteredScooters.push_back(scooter);
        }
    }

    return filteredScooters;
}

///Search for a string in the last location of a scooter
vector<ElectricScooter> ElectricScooterController::lastLocationSearch(const string &location) {
    vector<ElectricScooter> scooters = getAll();
    vector<ElectricScooter> matchingScooters;

    // Search for electric scooters with the specified location
    for (ElectricScooter scooter: scooters) {
        if (scooter.toString().find(location) != string::npos) {
            matchingScooters.push_back(scooter);
        }
    }
    return matchingScooters;
}

void ElectricScooterController::update() {
    repository->update();
}

void ElectricScooterController::reserveScooter(const string& id) {
    if (!find(id))
        throw invalid_argument("");
    repository->reserveScooter(id);
}

void ElectricScooterController::useScooter(const string& id) {
    if (!find(id))
        throw invalid_argument("");
    repository->useScooter(id);
}