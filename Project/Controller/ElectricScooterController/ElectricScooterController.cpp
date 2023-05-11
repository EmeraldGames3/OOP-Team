#include "ElectricScooterController.h"

using namespace Controller;

ElectricScooterController::ElectricScooterController(shared_ptr<ElectricScooterRepository> repo) {
    repository = repo;
}

void
ElectricScooterController::add(string id, string model, string date, float mileage, string location, string condition) {
    ElectricScooter scooter(id, model, date, mileage, location, condition);
    repository->add(scooter);
}

void ElectricScooterController::remove(string id) {
    if(!find(id))
        throw invalid_argument("");
    ElectricScooter scooter(id);
    repository->remove(scooter);
}

vector<ElectricScooter> ElectricScooterController::getAll() {
    return repository->getAll();
}

bool ElectricScooterController::find(string id) {
    vector<ElectricScooter> scooters = getAll();
    for (int i = 0; i < scooters.size(); i++)
        if (scooters[i].getId() == id)
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

vector<ElectricScooter> ElectricScooterController::ageFiltered(int value) {}

vector<ElectricScooter> ElectricScooterController::ageSorted() {}

vector<ElectricScooter> ElectricScooterController::mileageFiltered(float value) {}

vector<ElectricScooter> ElectricScooterController::lastLocationSearch(string location) {}