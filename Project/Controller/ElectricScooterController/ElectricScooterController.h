#pragma once

#include "../UserController/UserController.h"
#include "../../Repository/Repository.h"
#include <memory>

using namespace Controller;
using std::shared_ptr;

namespace Controller {
    class ElectricScooterController {
    private:
        shared_ptr<CrudRepository<ElectricScooter>> repository;
        User currentUser;

    public:
        ///Constructor
        explicit ElectricScooterController(shared_ptr<CrudRepository<ElectricScooter>> repo);

        ///Add an electric scooter to the Data Base
        void add(string id, string model, const string& date, float mileage, string location, string condition);

        ///Remove a scooter from the Data Base
        void remove(const string& id);

        ///Update functions
        void updateID(const string &newId, const string &oldId);
        void updateModel(const string &model, const string &id);
        void updateDate(const string &date, const string &id);
        void updateMileage(float mileage, const string &id);
        void updateLocation(const string &location, const string &id);
        void updateCondition(const string &condition, const string &id);

        ///Get all scooters
        vector<ElectricScooter> getAll();

        ///Get all scooters sorted by date
        vector<ElectricScooter> ageSorted();

        ///Filter all scooters by data
        vector<ElectricScooter> ageFiltered(Domain::Date value);

        ///Filter all scooters based on mileage
        vector<ElectricScooter> mileageFiltered(float value);

        ///Search for a string in the last location of a scooter
        vector<ElectricScooter> lastLocationSearch(const string& location);

        ///Check if a scooter is in the Data Base
        bool find(const string& id);

        ///Manipulate a scooter
        bool reserveScooter(const string &id, Client &client);
        bool useScooter(const string &id, Client &client);
        bool freeScooter(const string &id, Client &client);
    };
}