#include "../Domain/ElectricScooter/ElectricScooter.h"
#include <vector>

using namespace Domain;
using namespace std;

namespace Repository {
    class ElectricScooterRepository {
    private:
        vector<ElectricScooter> repository;

    public:
        ElectricScooterRepository();

        void add(ElectricScooter scooter);

        void remove(ElectricScooter scooter);

        void updateDatabase();

        void updateID(const string &id, const string &oldId);

        void updateModel(const string &model, const string &id);

        void updateDate(const string &date, const string &id);

        void updateMileage(float mileage, const string &id);

        void updateLocation(const string &location, const string &id);

        void updateCondition(const string &condition, const string &id);

        vector<ElectricScooter> getAll();

    };
}