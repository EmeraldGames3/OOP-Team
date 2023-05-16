#include "TestRepository.h"
#include "../../Repository/Repository.h"
#include <cassert>

using namespace Repository;

void testUserRepository() {
    {
        try {
            UserRepository userRepository("false");
            assert(false);
        } catch (const exception &e) {
            assert(true);
        }
    }

    {
        auto userRepository = UserRepository("Tests/TestRepository/TestDataBase/EmptyFile");
        assert(userRepository.getAllAsPointer()->empty());
        userRepository.add(User("a", "a"));
        userRepository.add(User("b", "a"));
        userRepository.add(User("c", "a"));

        auto values = userRepository.getAllAsPointer();
        for (const auto &it: *values) {
            assert(it.getPassword() == "a");
        }

        assert(values->at(0).getUsername() == "a");
        assert(values->at(1).getUsername() == "b");
        assert(values->at(2).getUsername() == "c");

        userRepository.remove(User("a", "a"));
        userRepository.remove(User("b", "a"));
        userRepository.remove(User("c", "a"));

        assert(userRepository.getAll().empty());

        try {
            userRepository.remove(User("a", "a"));
            assert(false);
        } catch (const exception &exception) {
            assert(true);
        }
    }

    {
        auto userRepository = UserRepository("Tests/TestRepository/TestDataBase/TestUserDataBase");
        auto values = userRepository.getAllAsPointer();
        assert(!values->empty());

        userRepository.deleteAllData();
        assert(userRepository.getAll().empty());

        assert(values->at(0).getUsername() == "antonia_kocsis");
        assert(values->at(0).getPassword() == "29466");

        assert(values->at(1).getUsername() == "Bogdan");
        assert(values->at(1).getPassword() == "1234");

        userRepository.add(values->at(0));
        userRepository.add(values->at(1));
        userRepository.update();
    }
}

void testElectricScooterRepository() {
    {
        // Test case 1: Exception is thrown when file does not exist
        try {
            ElectricScooterRepository repository("NonexistentFile");
            assert(false);  // The code should not reach this point
        } catch (const std::exception &e) {
            assert(true);  // Exception should be thrown
        }

        // Test case 2: Adding and getting scooters
        ElectricScooterRepository repository("Tests/TestRepository/TestDataBase/EmptyFile");
        repository.deleteAllData();
        // Ensure the database is initially empty
        assert(repository.getAll().empty());

        // Create scooters
        ElectricScooter scooter1("001");
        ElectricScooter scooter2("002");
        ElectricScooter scooter3("003");

        // Add scooters to the repository
        repository.add(scooter1);
        repository.add(scooter2);
        repository.add(scooter3);

        // Check if the scooters are added successfully
        assert(repository.getAll().size() == 3);
        assert(repository.getAll()[0].getId() == "001");
        assert(repository.getAll()[1].getId() == "002");
        assert(repository.getAll()[2].getId() == "003");

        // Test case 3: Removing a scooter
        repository.remove(scooter2);
        assert(repository.getAll().size() == 2);
        assert(repository.getAll()[0].getId() == "001");
        assert(repository.getAll()[1].getId() == "003");

        // Test case 4: Updating scooter attributes
        repository.updateModel("NewModel", "001");
        repository.updateCondition("NewCondition", "003");

        assert(repository.getAll()[0].getModel() == "NewModel");
        assert(repository.getAll()[1].getCondition() == "NewCondition");
    }

    {
        auto repository = ElectricScooterRepository("Tests/TestRepository/"
                                                    "TestDataBase/TestElectricScooterDataBase");

        // Test case 1: Check the number of scooters in the repository
        assert(repository.getAll().size() == 3);

        // Test case 2: Check the details of a specific scooter
        ElectricScooter scooter = repository.getAll()[0];
        assert(scooter.getId() == "001");
        assert(scooter.getModel() == "Model X");
        assert(scooter.getDateAsString() == "2022-1-15");
        assert(scooter.getMileage() == 500.0);
        assert(scooter.getLocation() == "Location A");
        assert(scooter.getCondition() == "Good");

        // Test case 3: Try adding a scooter with the same ID, should not add duplicate
        ElectricScooter duplicateScooter("001", "Duplicate Model", "2022-04-01",
                                         100.0, "Location D", "Fair");
        repository.add(duplicateScooter);
        assert(repository.getAll().size() == 3);  // Number of scooters should remain the same

        // Test case 4: Remove a scooter from the repository
        repository.remove(scooter);
        assert(repository.getAll().size() == 2);  // Number of scooters should decrease by 1

        // Test case 5: Update the mileage of a scooter
        repository.updateMileage(600.0, "002");
        ElectricScooter updatedScooter = repository.getAll()[0];
        assert(updatedScooter.getMileage() == 600.0);  // Mileage should be updated
    }

    {
        // Create a mock data vector
        vector<ElectricScooter> data;
        data.emplace_back("123", "Model X",
                          "2023-01-01", 100.0, "Location A", "Good Condition");
        data.emplace_back("456", "Model Y",
                          "2023-02-01", 200.0, "Location B", "Fair Condition");
        data.emplace_back("789", "Model Z",
                          "2023-03-01", 300.0, "Location C", "Excellent Condition");

        // Create an ElectricScooterRepository instance using the mock data
        ElectricScooterRepository repository;
        repository.deleteAllData();

        repository.add(data[0]);
        repository.add(data[1]);
        repository.add(data[2]);

        // Test updating the model
        repository.updateModel("New Model", "123");
        assert(repository.getAll()[0].getModel() == "New Model");

        // Test updating the mileage
        repository.updateMileage(150.0, "456");
        assert(repository.getAll()[1].getMileage() == 150.0);

        // Test updating the ID
        repository.updateID("999", "789");
        assert(repository.getAll()[2].getId() == "999");

        // Test updating the location
        repository.updateLocation("New Location", "123");
        assert(repository.getAll()[0].getLocation() == "New Location");

        // Test updating the condition
        repository.updateCondition("Fair Condition", "456");
        assert(repository.getAll()[1].getCondition() == "Fair Condition");

        // Test updating the date
        repository.updateDate("2023-5-5", "999");

        assert(repository.getAll()[2].getDateAsString() == "2023-5-5");
    }
}

void testRepository() {
    testUserRepository();
    testElectricScooterRepository();
}