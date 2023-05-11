#include <iostream>
#include <sstream>
#include "../Date/Date.h"

using std::string;

namespace Domain {
    class ElectricScooter {
    private:
        string identifier;
        string model;
        string commissioningDate;
        float mileage;
        string lastLocation;
        string currentCondition;

    public:
        ElectricScooter(const string &_identifier, string _model, string _commissioningDate, float _mileage,
                        string _lastLocation,
                        string _currentCondition);

        explicit ElectricScooter(const string &_id);

        string getId();

        string getModel();

        string getDate();

        [[nodiscard]] float getMileage() const;

        string getLocation();

        string getCondition();

        void setId(string id);

        void setModel(string model);

        void setDate(string date);

        void setMileage(float mileage);

        void setLocation(string location);

        void setCondition(string condition);


    };
}