#include "TestElectricScooterController.h"
#include "../../../Controller/Controller.h"
#include <cassert>

using namespace Controller;

void testAgeFiltered() {
    // Create a vector of ElectricScooters with different dates
    vector<ElectricScooter> scooters;
    for (int i = 0; i < 10; i++) {
        string id = "00" + to_string(i);
        string model = "Model " + to_string(i + 1);
        string date = "202" + to_string(i % 3 + 1) + "-0" +
                      to_string((i + 1) % 9 + 1) + "-0" + to_string((i + 1) % 9 + 1);
        double mileage = 100 * (i + 1);
        string location = "Location " + to_string(i + 1);
        string condition = "Condition " + to_string(i + 1);
        scooters.emplace_back(id, model, date,
                              mileage, location, condition);
    }

    // Create a controller with a repository containing the scooters
    InMemoryRepository<ElectricScooter> repository(scooters);
    ElectricScooterController controller(std::make_shared<InMemoryRepository<ElectricScooter>>(repository));

    // Filter scooters based on age (before or on "2021-01-01")
    Date filterDate(2022, 12, 31);
    vector<ElectricScooter> filteredScooters = controller.ageFiltered(filterDate);

    // Assert the correct number of filtered scooters
    assert(filteredScooters.size() == 7);

    // Assert the correct scooters are in the filtered list
    assert(filteredScooters[0].getId() == "000");
    assert(filteredScooters[1].getId() == "001");
    assert(filteredScooters[2].getId() == "003");
    assert(filteredScooters[3].getId() == "004");
    assert(filteredScooters[4].getId() == "006");
    assert(filteredScooters[5].getId() == "007");
    assert(filteredScooters[6].getId() == "009");
}

void testModelSorted() {
    // Create a vector of ElectricScooters
    vector<ElectricScooter> scooters;
    for (int i = 0; i < 10; i++) {
        string id = "00" + to_string(i);
        string model = "Model " + to_string(i + 1);
        string date =
                "202" + to_string(i % 3 + 1) + "-0" + to_string((i + 1) % 9 + 1)
                + "-0" + to_string((i + 1) % 9 + 1);
        double mileage = 100 * (i + 1);
        string location = "Location " + to_string(i + 1);
        string condition = "Condition " + to_string(i + 1);
        scooters.emplace_back(id, model, date,
                              mileage, location, condition);
    }

    // Create a controller with a repository containing the scooters
    InMemoryRepository<ElectricScooter> repository(scooters);
    ElectricScooterController controller(std::make_shared<InMemoryRepository<ElectricScooter>>(repository));

    vector<ElectricScooter> sortedScooters = controller.modelSorted();

    assert(sortedScooters.size() == 10);
    for (int i = 0; i < 9; i++) {
        assert(sortedScooters[i].getModel() <= sortedScooters[i + 1].getModel());
    }
}

void testAgeSorted() {
    // Create a vector of ElectricScooters
    vector<ElectricScooter> scooters;
    for (int i = 0; i < 10; i++) {
        string id = "00" + to_string(i);
        string model = "Model " + to_string(i + 1);
        string date =
                "202" + to_string(i % 3 + 1) + "-0" + to_string((i + 1) % 9 + 1)
                + "-0" + to_string((i + 1) % 9 + 1);
        double mileage = 100 * (i + 1);
        string location = "Location " + to_string(i + 1);
        string condition = "Condition " + to_string(i + 1);
        scooters.emplace_back(id, model, date,
                              mileage, location, condition);
    }

    // Create a controller with a repository containing the scooters
    InMemoryRepository<ElectricScooter> repository(scooters);
    ElectricScooterController controller(std::make_shared<InMemoryRepository<ElectricScooter>>(repository));

    // Get the scooters sorted by age
    vector<ElectricScooter> sortedScooters = controller.ageSorted();

    // Assert the correct order of scooters based on date
    assert(sortedScooters.size() == 10);
    for (int i = 0; i < 9; i++) {
        assert(sortedScooters[i].getDate() <= sortedScooters[i + 1].getDate());
    }
}

void testMileageSorted() {
    // Create a vector of ElectricScooters
    vector<ElectricScooter> scooters;
    for (int i = 0; i < 10; i++) {
        string id = "00" + to_string(i);
        string model = "Model " + to_string(i + 1);
        string date =
                "202" + to_string(i % 3 + 1) + "-0" + to_string((i + 1) % 9 + 1)
                + "-0" + to_string((i + 1) % 9 + 1);
        double mileage = 100 * (i + 1);
        string location = "Location " + to_string(i + 1);
        string condition = "Condition " + to_string(i + 1);
        scooters.emplace_back(id, model, date,
                              mileage, location, condition);
    }

    // Create a controller with a repository containing the scooters
    InMemoryRepository<ElectricScooter> repository(scooters);
    ElectricScooterController controller(std::make_shared<InMemoryRepository<ElectricScooter>>(repository));

    vector<ElectricScooter> sortedScooters = controller.mileageSorted();

    assert(sortedScooters.size() == 10);
    for (int i = 0; i < 9; i++) {
        assert(sortedScooters[i].getMileage() <= sortedScooters[i + 1].getMileage());
    }
}

void testLastLocationSorted() {
    // Create a vector of ElectricScooters
    vector<ElectricScooter> scooters;
    for (int i = 0; i < 10; i++) {
        string id = "00" + to_string(i);
        string model = "Model " + to_string(i + 1);
        string date =
                "202" + to_string(i % 3 + 1) + "-0" + to_string((i + 1) % 9 + 1)
                + "-0" + to_string((i + 1) % 9 + 1);
        double mileage = 100 * (i + 1);
        string location = "Location " + to_string(i + 1);
        string condition = "Condition " + to_string(i + 1);
        scooters.emplace_back(id, model, date,
                              mileage, location, condition);
    }

    // Create a controller with a repository containing the scooters
    InMemoryRepository<ElectricScooter> repository(scooters);
    ElectricScooterController controller(std::make_shared<InMemoryRepository<ElectricScooter>>(repository));

    vector<ElectricScooter> sortedScooters = controller.lastLocationSorted();

    assert(sortedScooters.size() == 10);
    for (int i = 0; i < 9; i++) {
        assert(sortedScooters[i].getLocation() <= sortedScooters[i + 1].getLocation());
    }
}

void testCurrentConditionSorted() {
    // Create a vector of ElectricScooters
    vector<ElectricScooter> scooters;
    for (int i = 0; i < 10; i++) {
        string id = "00" + to_string(i);
        string model = "Model " + to_string(i + 1);
        string date =
                "202" + to_string(i % 3 + 1) + "-0" + to_string((i + 1) % 9 + 1)
                + "-0" + to_string((i + 1) % 9 + 1);
        double mileage = 100 * (i + 1);
        string location = "Location " + to_string(i + 1);
        string condition = "Condition " + to_string(i + 1);
        scooters.emplace_back(id, model, date,
                              mileage, location, condition);
    }

    // Create a controller with a repository containing the scooters
    InMemoryRepository<ElectricScooter> repository(scooters);
    ElectricScooterController controller(std::make_shared<InMemoryRepository<ElectricScooter>>(repository));

    vector<ElectricScooter> sortedScooters = controller.currentConditionSorted();

    assert(sortedScooters.size() == 10);
    for (int i = 0; i < 9; i++) {
        assert(sortedScooters[i].getCondition() <= sortedScooters[i + 1].getCondition());
    }
}

void testMileageFiltered() {
    // Create a vector of ElectricScooters with different dates
    vector<ElectricScooter> scooters;
    for (int i = 0; i < 10; i++) {
        string id = "00" + to_string(i);
        string model = "Model " + to_string(i + 1);
        string date = "202" + to_string(i % 3 + 1) + "-0" +
                      to_string((i + 1) % 9 + 1) + "-0" + to_string((i + 1) % 9 + 1);
        double mileage = 100 * (i + 1);
        string location = "Location " + to_string(i + 1);
        string condition = "Condition " + to_string(i + 1);
        scooters.emplace_back(id, model,
                              date, mileage, location, condition);
    }

    // Create a controller with a repository containing the scooters
    InMemoryRepository<ElectricScooter> repository(scooters);
    ElectricScooterController controller(std::make_shared<InMemoryRepository<ElectricScooter>>(repository));

    // Filter scooters based on mileage (100 or less)
    vector<ElectricScooter> filteredScooters = controller.mileageFiltered(400);

    // Assert the correct number of filtered scooters
    assert(filteredScooters.size() == 4);

    // Assert the correct scooters are in the filtered list
    assert(filteredScooters[0].getId() == "000");
    assert(filteredScooters[1].getId() == "001");
    assert(filteredScooters[2].getId() == "002");
    assert(filteredScooters[3].getId() == "003");
}

void testLastLocationSearch() {
    // Create a vector of ElectricScooters with different locations
    vector<ElectricScooter> scooters;
    for (int i = 0; i < 10; i++) {
        string id = "00" + to_string(i);
        string model = "Model " + to_string(i + 1);
        string date = "2021-01-01";
        double mileage = 100 * (i + 1);
        string location = "Location " + to_string(i + 1);
        string condition = "Condition " + to_string(i + 1);
        scooters.emplace_back(id, model,
                              date, mileage, location, condition);
    }

    // Create a controller with a repository containing the scooters
    InMemoryRepository<ElectricScooter> repository(scooters);
    ElectricScooterController controller(std::make_shared<InMemoryRepository<ElectricScooter>>(repository));

    // Search for scooters based on last location (e.g., "ation 1")
    string searchLocation = "1";
    vector<ElectricScooter> matchingScooters = controller.lastLocationSearch(searchLocation);

    // Assert the correct number of matching scooters
    assert(matchingScooters.size() == 2);

    // Assert the correct scooter is in the matching list
    assert(matchingScooters[0].getId() == "000");
    assert(matchingScooters[1].getId() == "009");
}

void testReserveScooter() {
    // Create a vector of ElectricScooters
    vector<ElectricScooter> scooters;
    for (int i = 0; i < 10; i++) {
        string id = "00" + to_string(i);
        string model = "Model " + to_string(i + 1);
        string date = "2021-01-01";
        double mileage = 100 * (i + 1);
        string location = "Location " + to_string(i + 1);
        string condition = (i % 2 == 0) ? "Parked" : "Reserved";
        scooters.emplace_back(id, model, date,
                              mileage, location, condition);
    }

    // Create a controller with a repository containing the scooters
    InMemoryRepository<ElectricScooter> repository(scooters);
    ElectricScooterController controller(std::make_shared<InMemoryRepository<ElectricScooter>>(repository));

    // Test reserving a parked scooter
    string scooterId = "000";
    Client client("John Doe");
    assert(controller.reserveScooter(scooterId, client));
    assert(controller.find(scooterId));
    assert(controller.getAll()[0].getCondition() == "Reserved");

    // Test reserving a scooter that is not parked
    scooterId = "001";
    assert(!controller.reserveScooter(scooterId, client));
    assert(controller.find(scooterId));
    assert(controller.getAll()[1].getCondition() == "Reserved");
}

void testUseScooter() {
    // Create a vector of ElectricScooters
    vector<ElectricScooter> scooters;
    for (int i = 0; i < 10; i++) {
        string id = "00" + to_string(i);
        string model = "Model " + to_string(i + 1);
        string date = "2021-01-01";
        double mileage = 100 * (i + 1);
        string location = "Location " + to_string(i + 1);
        string condition = (i % 2 == 0) ? "Parked" : "Reserved";
        scooters.emplace_back(id, model, date,
                              mileage, location, condition);
    }

    // Create a controller with a repository containing the scooters
    InMemoryRepository<ElectricScooter> repository(scooters);
    ElectricScooterController controller(std::make_shared<InMemoryRepository<ElectricScooter>>(repository));

    Client client("John Doe");
    assert(!controller.useScooter("---", client));

    assert(controller.useScooter("000", client));
    assert(controller.getAll()[0].getCondition() == "In_Use");
    assert(client.isOnRide());

    assert(!controller.useScooter("002", client));
}

void testFreeScooter() {
    // Create a vector of ElectricScooters
    vector<ElectricScooter> scooters;
    for (int i = 0; i < 10; i++) {
        string id = "00" + to_string(i);
        string model = "Model " + to_string(i + 1);
        string date = "2021-01-01";
        double mileage = 100 * (i + 1);
        string location = "Location " + to_string(i + 1);
        string condition = (i % 2 == 0) ? "Parked" : "Reserved";
        scooters.emplace_back(id, model,
                              date, mileage, location, condition);
    }

    // Create a controller with a repository containing the scooters
    InMemoryRepository<ElectricScooter> repository(scooters);
    ElectricScooterController controller(std::make_shared<InMemoryRepository<ElectricScooter>>(repository));

    // Create a client
    Client client("John Doe");

    assert(controller.useScooter("000", client));
    assert(controller.getAll()[0].getCondition() == "In_Use");

    assert(controller.freeScooter("000", client));
    assert(controller.getAll()[0].getCondition() == "Parked");

    assert(controller.reserveScooter("000", client));
    assert(controller.reserveScooter("002", client));

    assert(controller.useScooter("000", client));
    assert(controller.freeScooter("000", client));

    assert(!controller.useScooter("001", client));
    assert(!controller.freeScooter("001", client));
    assert(!controller.reserveScooter("001", client));
}

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

    testModelSorted();
    testAgeSorted();
    testMileageSorted();
    testLastLocationSorted();
    testCurrentConditionSorted();
    testMileageFiltered();
    testAgeFiltered();
    testLastLocationSearch();
    testReserveScooter();
    testUseScooter();
    testFreeScooter();
}