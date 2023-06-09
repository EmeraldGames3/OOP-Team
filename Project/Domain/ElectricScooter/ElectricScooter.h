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
        explicit ElectricScooter(string _id = "000");

        ///Copy constructor
        ElectricScooter(const ElectricScooter &electricScooter) = default;

        ///Getters
        [[nodiscard]] string getModel() const;
        [[nodiscard]] string getDateAsString() const;
        [[nodiscard]] Date getDate() const;
        [[nodiscard]] float getMileage() const;
        [[nodiscard]] string getLocation() const;
        [[nodiscard]] string getCondition() const;

        ///Setters
        void setModel(const string &newModel);
        void setDate(const string &newDate);
        void setDate(const Date &newDate);
        void setMileage(float newMileage);
        void setLocation(const string &newLocation);
        void setCondition(const string &newCondition);

        ///Functions for writing/reading to/from files
        [[nodiscard]] string toString() override;
        [[nodiscard]] shared_ptr<ObjectWithId> convertFromString(string scooter) override;
        [[nodiscard]] string getAttributes() override;

        ///Overloaded operators
        bool operator==(const ElectricScooter &other);
        bool operator!=(const ElectricScooter &other);
    };
}