#include "ElectricScooter.h"

#include <utility>

using Domain::ElectricScooter, Domain::Date;

ElectricScooter::ElectricScooter(string _identifier, string _model, const string &_commissioningDate, float _mileage,
                                 string _lastLocation,
                                 string _currentCondition) {
    if (_identifier.size() != 3)
        throw std::invalid_argument("Invalid ID");
    identifier = std::move(_identifier);
    model = std::move(_model);
    mileage = _mileage;
    lastLocation = std::move(_lastLocation);
    currentCondition = std::move(_currentCondition);
    commissioningDate = Date::getDateFromString(_commissioningDate);
}

ElectricScooter::ElectricScooter(string _id) {
    if (_id.size() != 3)
        throw std::invalid_argument("Invalid ID");
    identifier = std::move(_id);
    model = "";
    commissioningDate = Date();
    mileage = 0.0;
    lastLocation = "";
    currentCondition = "";
}

string ElectricScooter::getDateAsString() { return commissioningDate.getDateAsFormattedString(); }

Date ElectricScooter::getDate() {
    return commissioningDate;
}

string ElectricScooter::getCondition() { return currentCondition; }

string ElectricScooter::getId() { return identifier; }

string ElectricScooter::getLocation() { return lastLocation; }

float ElectricScooter::getMileage() const { return mileage; }

string ElectricScooter::getModel() { return model; }

void ElectricScooter::setDate(const string &newDate) {
    commissioningDate = Date::getDateFromString(newDate);
}

void Domain::ElectricScooter::setDate(const Date &newDate) {
    commissioningDate = newDate;
}

void ElectricScooter::setCondition(const string &newCondition) {
    currentCondition = newCondition;
}

void ElectricScooter::setModel(const string &newModel) {
    model = newModel;
}

void ElectricScooter::setLocation(const string &newLocation) {
    lastLocation = newLocation;
}

void ElectricScooter::setId(const string &newID) {
    if (newID.size() != 3)
        throw std::invalid_argument("Invalid ID");
    identifier = newID;
}

void ElectricScooter::setMileage(float newMileage) { mileage = newMileage; }

string Domain::ElectricScooter::toString() {
    std::ostringstream oss;
    oss << "Identifier: " << identifier << " ";
    oss << "Model: " << model << " ";
    oss << "Commissioning Date: " << getDateAsString() << " ";
    oss << "Mileage: " << mileage << " ";
    oss << "Last Location: " << lastLocation << " ";
    oss << "Current Condition: " << currentCondition << " ";
    return oss.str();
}

bool Domain::ElectricScooter::operator==(const ElectricScooter &other) {
    return this->identifier == other.identifier;
}

bool Domain::ElectricScooter::operator!=(const ElectricScooter &other) {
    return !(*this == other);
}
