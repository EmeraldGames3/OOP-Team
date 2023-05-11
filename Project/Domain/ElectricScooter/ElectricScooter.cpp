#include "ElectricScooter.h"

using namespace Domain;


ElectricScooter::ElectricScooter(const string &_identifier, string _model, string _commissioningDate, float _mileage,
                                 string _lastLocation,
                                 string _currentCondition) {
    if (_identifier.size() != 3)
        throw std::invalid_argument("");
    identifier = _identifier;
    model = _model;
    mileage = _mileage;
    lastLocation = _lastLocation;
    currentCondition = _currentCondition;
    commissioningDate = _commissioningDate;
}

ElectricScooter::ElectricScooter(const string &_id) {
    if (_id.size() != 3)
        throw std::invalid_argument("");
    identifier = _id;
}

string ElectricScooter::getDate() { return commissioningDate; }

string ElectricScooter::getCondition() { return currentCondition; }

string ElectricScooter::getId() { return identifier; }

string ElectricScooter::getLocation() { return lastLocation; }

float ElectricScooter::getMileage() const { return mileage; }

string ElectricScooter::getModel() { return model; }

void ElectricScooter::setDate(string date) {
    this->commissioningDate = date;
}

void ElectricScooter::setCondition(string condition) {
    this->currentCondition = condition;
}

void ElectricScooter::setModel(string model) {
    this->model = model;
}

void ElectricScooter::setLocation(string location) {
    lastLocation = location;
}

void ElectricScooter::setId(string id) {
    if (id.size() != 3)
        throw std::invalid_argument(" ");
    identifier = id;
}

void ElectricScooter::setMileage(float mileage) { this->mileage = mileage; }