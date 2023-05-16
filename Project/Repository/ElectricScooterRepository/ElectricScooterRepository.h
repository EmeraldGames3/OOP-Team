#pragma once

#include "../../Domain/Domain.h"
#include "../AbstractRepository.h"
#include <vector>
#include <memory>

using Domain::ElectricScooter;
using std::unique_ptr, std::shared_ptr, std::vector, std::string;

namespace Repository {
    ///Repository to manage the electric scooter data
    class ElectricScooterRepository : AbstractRepository {
    private:
        shared_ptr<vector<ElectricScooter>> data;

    public:
        ///Constructor with default parameters
        explicit ElectricScooterRepository(const string &_fileName = "Repository/Data/ScooterDatabase");

        ///Add a scooter to the Data Base
        void add(ElectricScooter scooter);

        ///Remove a scooter from the Data Base
        void remove(ElectricScooter scooter);

        ///Update the Data Base
        void update() override;

        ///Update the ID of a scooter
        void updateID(const string &id, const string &oldId);

        ///Update the Model of a scooter
        void updateModel(const string &model, const string &id);

        ///Update the commissioning date of a scooter
        void updateDate(const string &date, const string &id);

        ///Update the mileage of a scooter
        void updateMileage(float mileage, const string &id);

        ///Update the location of a scooter
        void updateLocation(const string &location, const string &id);

        ///Update the condition of a scooter
        void updateCondition(const string &condition, const string &id);

        ///Delete all data from the Data Base
        void deleteAllData();

        ///Get all data in the scooter Data Base
        vector<ElectricScooter> getAll();

        ///Get a pointer to all data in the Data Base
        unique_ptr<vector<Domain::ElectricScooter>> getAllAsPointer();

        void reserveScooter(const string &id);

        void useScooter(const string &id);
    };
}