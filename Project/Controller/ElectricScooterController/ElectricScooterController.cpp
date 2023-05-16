#include "ElectricScooterController.h"

#include <utility>

using namespace Controller;
using namespace Domain;

ElectricScooterController::ElectricScooterController(shared_ptr<ElectricScooterRepository> repo) {
    repository = std::move(repo);
}

void ElectricScooterController::add(
        string id, string model, const string &date, float mileage, string location, string condition
) {
    ElectricScooter scooter(std::move(id), std::move(model), date, mileage,
                            std::move(location), std::move(condition));
    repository->add(scooter);
}

void ElectricScooterController::remove(const string &id) {
    if (!find(id))
        throw invalid_argument("");
    ElectricScooter scooter(id);
    repository->remove(scooter);
}

vector<ElectricScooter> ElectricScooterController::getAll() {
    return repository->getAll();
}

bool ElectricScooterController::find(const string &id) {
    vector<ElectricScooter> scooters = getAll();
    for (auto &scooter : scooters)
        if (scooter.getId() == id)
            return true;
    return false;
}

void ElectricScooterController::updateModel(const string &model, const string &id) {
    if (!find(id))
        throw invalid_argument("");
    repository->updateModel(model, id);
}

void ElectricScooterController::updateMileage(float mileage, const string &id) {
    if (!find(id))
        throw invalid_argument("");
    repository->updateMileage(mileage, id);
}

void ElectricScooterController::updateID(const string &id, const string &oldId) {
    if (!find(id))
        throw invalid_argument("");
    repository->updateID(id, oldId);
}

void ElectricScooterController::updateLocation(const string &location, const string &id) {
    if (!find(id))
        throw invalid_argument("");
    repository->updateLocation(location, id);
}

void ElectricScooterController::updateCondition(const string &condition, const string &id) {
    if (!find(id))
        throw invalid_argument("");
    repository->updateCondition(condition, id);
}

void ElectricScooterController::updateDate(const string &date, const string &id) {
    if (!find(id))
        throw invalid_argument("");
    repository->updateDate(date, id);
}

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

vector<ElectricScooter> ElectricScooterController::ageSorted() {
    vector<ElectricScooter> scooters = getAll();
    sort(scooters.begin(), scooters.end(), [](ElectricScooter a, ElectricScooter b) {
        return a.getDate() < b.getDate();
    });
    return scooters;
}

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