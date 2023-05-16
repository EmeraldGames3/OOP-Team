#include "ElectricScooter.h"

#include <utility>

using Domain::ElectricScooter, Domain::Date;

/**
 * @brief Default constructor for the class Electric scooter
 * @warning The received strings are moved from their place in memory for efficiency purposes
 *          It is unsafe to use the strings after they have been received by this function
 * @throws invalid_argument if the id is invalid
 */
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

///Constructor with 1 parameter
///@throws invalid_argument if the id has an invalid format
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

///Get the date in string form
string ElectricScooter::getDateAsString() { return commissioningDate.getDateAsFormattedString(); }

///Date getter
Date ElectricScooter::getDate() {
    return commissioningDate;
}

///Condition getter
string ElectricScooter::getCondition() { return currentCondition; }

///ID getter
string ElectricScooter::getId() { return identifier; }

///Location getter
string ElectricScooter::getLocation() { return lastLocation; }

///Mileage getter
float ElectricScooter::getMileage() const { return mileage; }

///Model getter
string ElectricScooter::getModel() { return model; }

///Date setter
///@details Converts the date from string form and sets the data
void ElectricScooter::setDate(const string &newDate) {
    commissioningDate = Date::getDateFromString(newDate);
}

///Date setter
///@details Only sets the date no conversion needed
void Domain::ElectricScooter::setDate(const Date &newDate) {
    commissioningDate = newDate;
}

///Condition setter
void ElectricScooter::setCondition(const string &newCondition) {
    currentCondition = newCondition;
}

///Model setter
void ElectricScooter::setModel(const string &newModel) {
    model = newModel;
}

///Location setter
void ElectricScooter::setLocation(const string &newLocation) {
    lastLocation = newLocation;
}

///ID setter
///@throws invalid_argument if the id has an invalid format
void ElectricScooter::setId(const string &newID) {
    if (newID.size() != 3)
        throw std::invalid_argument("Invalid ID");
    identifier = newID;
}

///Mileage setter
void ElectricScooter::setMileage(float newMileage) { mileage = newMileage; }

///Convert the object into string form
///Used for writing to the Data Base
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

///Overloaded == operator
///Two objects are equal if they have the same id
bool Domain::ElectricScooter::operator==(const ElectricScooter &other) {
    return this->identifier == other.identifier;
}

///Overloaded != operator
///Two objects are not equal if they have different ids
bool Domain::ElectricScooter::operator!=(const ElectricScooter &other) {
    return !(*this == other);
}
