#include <iostream>
#include <sstream>
#include "../Date/Date.h"

using std::string;

namespace Domain {
    class ElectricScooter {
    private:
        string identifier;
        string model;
        Date commissioningDate;
        float mileage;
        string lastLocation;
        string currentCondition;

    public:
        ElectricScooter(string _identifier, string _model, const string& _commissioningDate, float _mileage,
                        string _lastLocation,
                        string _currentCondition);

        explicit ElectricScooter(string _id);

        [[nodiscard]] string getId();

        [[nodiscard]] string getModel();

        [[nodiscard]] string getDateAsString();

        [[nodiscard]] Date getDate();

        [[nodiscard]] float getMileage() const;

        [[nodiscard]] string getLocation();

        [[nodiscard]] string getCondition();

        void setId(const string &newID);

        void setModel(const string &newModel);

        void setDate(const string &newDate);

        void setDate(const Date &newDate);

        void setMileage(float newMileage);

        void setLocation(const string &newLocation);

        void setCondition(const string &newCondition);

        string toString();

        bool operator==(const ElectricScooter &other);

        bool operator!=(const ElectricScooter &other);
    };
}