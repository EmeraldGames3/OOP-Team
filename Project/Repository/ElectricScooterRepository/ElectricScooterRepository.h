#pragma once
#include "../../Domain/Domain.h"
#include "../AbstractRepository.h"
#include <vector>
#include <memory>

using Domain::ElectricScooter;
using std::unique_ptr, std::shared_ptr, std::vector, std::string;

namespace Repository {
    class ElectricScooterRepository : AbstractRepository{
    private:
        shared_ptr<vector<ElectricScooter>> data;

    public:
        explicit ElectricScooterRepository(const string &_fileName = "Repository/Data/ScooterDatabase");

        void add(ElectricScooter scooter);

        void remove(ElectricScooter scooter);

        void update() override;

        void updateID(const string &id, const string &oldId);

        void updateModel(const string &model, const string &id);

        void updateDate(const string &date, const string &id);

        void updateMileage(float mileage, const string &id);

        void updateLocation(const string &location, const string &id);

        void updateCondition(const string &condition, const string &id);

        void deleteAllData();

        vector<ElectricScooter> getAll();

        unique_ptr<vector<Domain::ElectricScooter>> getAllAsPointer();
    };
}