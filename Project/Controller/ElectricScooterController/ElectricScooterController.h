#include "../../Repository/ElectricScooterRepository/ElectricScooterRepository.h"
#include <memory>

using namespace Repository;
namespace Controller {
    class ElectricScooterController {
    private:
        shared_ptr<ElectricScooterRepository> repository;
    public:
        explicit ElectricScooterController(
                shared_ptr<ElectricScooterRepository> repo = make_shared<ElectricScooterRepository>(
                        ElectricScooterRepository()));

        void add(string id, string model, string date, float mileage, string location, string condition);

        void remove(const string& id);

        void updateID(const string &id, const string &oldId);

        void updateModel(const string &model, const string &id);

        void updateDate(const string &date, const string &id);

        void updateMileage(float mileage, const string &id);

        void updateLocation(const string &location, const string &id);

        void updateCondition(const string &condition, const string &id);

        vector<ElectricScooter> getAll();

        vector<ElectricScooter> ageSorted();

        vector<ElectricScooter> ageFiltered(Domain::Date value);

        vector<ElectricScooter> mileageFiltered(float value);

        vector<ElectricScooter> lastLocationSearch(const string& location);

        bool find(const string& id);
    };
}