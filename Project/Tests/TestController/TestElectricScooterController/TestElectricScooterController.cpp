#include "TestElectricScooterController.h"
#include "../../../Controller/Controller.h"
#include <cassert>

using namespace Controller;

void testAddAndRemoveElectricScooterController() {
    // Create a mock ElectricScooterRepository
    auto repository = make_shared<ElectricScooterRepository>();
    repository->deleteAllData();

    // Create an ElectricScooterController instance using the mock repository
    ElectricScooterController controller(repository);

    // Add multiple electric scooters
    controller.add("690", "Model A", "2023-05-01",
                   100.0, "Location A", "Good Condition");
    controller.add("691", "Model B", "2023-05-02",
                   200.0, "Location B", "Fair Condition");
    controller.add("692", "Model C", "2023-05-03",
                   300.0, "Location A", "Excellent Condition");

    // Get all electric scooters
    vector<ElectricScooter> allScooters = controller.getAll();

    // Verify that the added electric scooters exist in the repository
    assert(allScooters.size() == 3);
    assert(allScooters[0].getId() == "690");
    assert(allScooters[1].getId() == "691");
    assert(allScooters[2].getId() == "692");

    // Remove an electric scooter
    controller.remove("691");

    // Get all electric scooters after removal
    vector<ElectricScooter> updatedScooters = controller.getAll();

    // Verify that the removed electric scooter is no longer in the repository
    assert(updatedScooters.size() == 2);
    assert(updatedScooters[0].getId() == "690");
    assert(updatedScooters[1].getId() == "692");

    // Remove another electric scooter
    controller.remove("690");

    // Get all electric scooters after another removal
    updatedScooters = controller.getAll();

    // Verify that both electric scooters have been removed from the repository
    assert(updatedScooters.size() == 1);
    assert(updatedScooters[0].getId() == "692");
}

void testFindElectricScooterController() {
    // Create a mock ElectricScooterRepository
    auto repository = make_shared<ElectricScooterRepository>();
    repository->deleteAllData();

    // Create an ElectricScooterController instance using the mock repository
    ElectricScooterController controller(repository);

    // Add electric scooters
    controller.add("690", "Model A", "2023-05-01", 100.0,
                   "Location A", "Good Condition");
    controller.add("691", "Model B", "2023-05-02", 200.0,
                   "Location B", "Fair Condition");

    // Test finding an existing electric scooter
    assert(controller.find("690"));
    assert(controller.find("691"));

    // Test finding a non-existent electric scooter
    assert(!controller.find("692"));

    // Remove an electric scooter
    controller.remove("691");

    // Test finding the removed electric scooter
    assert(!controller.find("691"));
}

void testUpdateElectricScooterController() {
    // Create a mock ElectricScooterRepository
    auto repository = make_shared<ElectricScooterRepository>();

    // Create an ElectricScooterController instance using the mock repository
    ElectricScooterController controller(repository);

    // Add an electric scooter
    controller.add("690", "Model A", "2023-05-01", 100.0,
                   "Location A", "Good Condition");

    // Test updating the model of an existing electric scooter
    controller.updateModel("New Model", "690");
    assert(controller.getAll()[0].getModel() == "New Model");

    // Test updating the mileage of an existing electric scooter
    controller.updateMileage(150.0, "690");
    assert(controller.getAll()[0].getMileage() == 150.0);

    // Test updating the ID of an existing electric scooter
    controller.updateID("691", "690");
    assert(!controller.find("690"));  // Check that the old ID is not found
    assert(controller.find("691"));  // Check that the new ID is found

    // Test updating the location of an existing electric scooter
    controller.updateLocation("New Location", "691");
    assert(controller.getAll()[0].getLocation() == "New Location");

    // Test updating the condition of an existing electric scooter
    controller.updateCondition("Fair Condition", "691");
    assert(controller.getAll()[0].getCondition() == "Fair Condition");

    // Test updating the date of an existing electric scooter
    controller.updateDate("2023-05-05", "691");
    assert(controller.getAll()[0].getDateAsString() == "2023-5-5");
}

void testAgeFilteredElectricScooterController() {
    // Create a mock ElectricScooterRepository
    auto repository = make_shared<ElectricScooterRepository>();
    repository->deleteAllData();
    // Create an ElectricScooterController instance using the mock repository
    ElectricScooterController controller(repository);

    // Add electric scooters with different dates
    controller.add("123", "Model A", "2023-01-01", 100.0,
                   "Location A", "Good Condition");
    controller.add("456", "Model B", "2023-02-01", 200.0,
                   "Location B", "Fair Condition");
    controller.add("789", "Model C", "2023-03-01", 300.0,
                   "Location C", "Excellent Condition");

    // Define the filter date
    Date filterDate(2023, 2, 15);

    // Filter electric scooters based on age
    vector<ElectricScooter> filteredScooters = controller.ageFiltered(filterDate);

    // Verify the filtered electric scooters
    assert(filteredScooters.size() == 2);
    assert(filteredScooters[0].getId() == "123");
    assert(filteredScooters[1].getId() == "456");
}

void testAgeSortedElectricScooterController() {
    // Create a mock ElectricScooterRepository
    auto repository = make_shared<ElectricScooterRepository>();
    repository->deleteAllData();
    // Create an ElectricScooterController instance using the mock repository
    ElectricScooterController controller(repository);

    // Add electric scooters with different dates
    controller.add("123", "Model A", "2023-01-01",
                   100.0, "Location A", "Good Condition");
    controller.add("456", "Model B", "2023-03-01",
                   200.0, "Location B", "Fair Condition");
    controller.add("789", "Model C", "2023-02-01",
                   300.0, "Location C", "Excellent Condition");

    // Sort electric scooters based on age
    vector<ElectricScooter> sortedScooters = controller.ageSorted();

    // Verify the sorted electric scooters
    assert(sortedScooters.size() == 3);
    assert(sortedScooters[0].getId() == "123"); // Oldest scooter
    assert(sortedScooters[1].getId() == "789");
    assert(sortedScooters[2].getId() == "456"); // Newest scooter
}

void testMileageFilteredElectricScooterController() {
    // Create a mock ElectricScooterRepository
    auto repository = make_shared<ElectricScooterRepository>();
    repository->deleteAllData();

    // Create an ElectricScooterController instance using the mock repository
    ElectricScooterController controller(repository);

    // Add electric scooters with different mileage values
    controller.add("123", "Model A", "2023-01-01",
                   100.0, "Location A", "Good Condition");
    controller.add("456", "Model B", "2023-02-01",
                   200.0, "Location B", "Fair Condition");
    controller.add("789", "Model C", "2023-03-01",
                   300.0, "Location C", "Excellent Condition");

    // Filter electric scooters based on mileage
    vector<ElectricScooter> filteredScooters = controller.mileageFiltered(250.0);

    // Verify the filtered electric scooters
    assert(filteredScooters.size() == 2);
    assert(filteredScooters[0].getId() == "123");
    assert(filteredScooters[1].getId() == "456");
}

void testLastLocationSearchElectricScooterController() {
    // Create a mock ElectricScooterRepository
    auto repository = make_shared<ElectricScooterRepository>();

    // Create an ElectricScooterController instance using the mock repository
    ElectricScooterController controller(repository);

    // Add electric scooters with different locations
    controller.add("123", "Model A", "2023-01-01", 100.0,
                   "Location A", "Good Condition");
    controller.add("456", "Model B", "2023-02-01", 200.0,
                   "Location B", "Fair Condition");
    controller.add("789", "Model C", "2023-03-01", 300.0,
                   "Location C", "Excellent Condition");

    // Search for electric scooters with the specified location
    vector<ElectricScooter> matchingScooters = controller.lastLocationSearch("B");

    // Verify the matching electric scooters
    assert(matchingScooters.size() == 1);
    assert(matchingScooters[0].getId() == "456");

    // If an empty string is given all scooters should be returned
    matchingScooters = controller.lastLocationSearch("");
    assert(matchingScooters.size() == 3);
}

void testElectricScooterController() {
    testAddAndRemoveElectricScooterController();
    testFindElectricScooterController();
    testUpdateElectricScooterController();
    testAgeFilteredElectricScooterController();
    testAgeSortedElectricScooterController();
    testMileageFilteredElectricScooterController();
    testLastLocationSearchElectricScooterController();
}