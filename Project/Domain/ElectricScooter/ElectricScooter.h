#pragma once

#include <iostream>
#include <sstream>
#include "../Date/Date.h"
#include "../ObjectWithID.h"

using std::string;

namespace Domain {
    class ElectricScooter : public ObjectWithId{
    private:
        string model;
        Date commissioningDate;
        float mileage;
        string lastLocation;
        string currentCondition;

    public:
        ///Default constructor
        ElectricScooter(string _identifier, string _model, const string &_commissioningDate, float _mileage,
                        string _lastLocation,
                        string _currentCondition);

        ///Constructor with 1 parameter
        explicit ElectricScooter(string _id);

        ///Getters
        [[nodiscard]] string getModel();
        [[nodiscard]] string getDateAsString();
        [[nodiscard]] Date getDate();
        [[nodiscard]] float getMileage() const;
        [[nodiscard]] string getLocation();
        [[nodiscard]] string getCondition();

        ///Setters
        void setModel(const string &newModel);
        void setDate(const string &newDate);
        void setDate(const Date &newDate);
        void setMileage(float newMileage);
        void setLocation(const string &newLocation);
        void setCondition(const string &newCondition);

        ///Convert the object to string form
        string toString();

        ///Overloaded operators
        bool operator==(const ElectricScooter &other);
        bool operator!=(const ElectricScooter &other);
    };
}