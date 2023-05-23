#include "TestElectricScooterController.h"
#include "../../../Controller/Controller.h"
#include <cassert>

using namespace Controller;

void testElectricScooterController() {
    auto scooters = vector<ElectricScooter>();
    for (int i = 0; i < 10; i++) {
        scooters.emplace_back(to_string(i) + to_string(i) + to_string(i));
    }

    InMemoryRepository<ElectricScooter> repository(scooters);
    ElectricScooterController controller(std::make_shared<InMemoryRepository<ElectricScooter>>(repository));

    for (int i = 0; i < 10; i++) {
        assert(controller.find(to_string(i) + to_string(i) + to_string(i)));
        assert(!controller.find(to_string(i)));
    }

    ElectricScooter scooter("123", "M", "2023-11-11",
                            10.5, "L", "C");

    controller.updateCondition(scooter.getCondition(), "000");
    controller.updateLocation(scooter.getLocation(), "000");
    controller.updateMileage(scooter.getMileage(), "000");
    controller.updateModel(scooter.getModel(), "000");
    controller.updateDate(scooter.getDateAsString(), "000");
    controller.updateID(scooter.getId(), "000");

    assert(!controller.find("000"));
    assert(controller.find(scooter.getId()));

    auto tempScooter = controller.getAll()[0];
    assert(tempScooter.getId() == scooter.getId());
    assert(tempScooter.getModel() == scooter.getModel());
    assert(tempScooter.getMileage() == scooter.getMileage());
    assert(tempScooter.getLocation() == scooter.getLocation());
    assert(tempScooter.getDate() == scooter.getDate());

    controller.remove(scooter.getId());
    assert(!controller.find(scooter.getId()));

    controller.add("000", "0", "2023-11-11", 0, "0", "0");

    for (int i = 0; i < 10; i++) {
        assert(controller.find(to_string(i) + to_string(i) + to_string(i)));
        assert(!controller.find(to_string(i)));
    }
}