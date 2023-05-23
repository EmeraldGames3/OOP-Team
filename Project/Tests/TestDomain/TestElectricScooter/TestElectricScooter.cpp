#include "TestElectricScooter.h"
#include <cassert>
#include "../../../Domain/Domain.h"

using Domain::ElectricScooter;

void testElectricScooter() {
    {
        // Create an electric scooter object with valid arguments
        ElectricScooter scooter("ABC", "Model X", "2023-01-01",
                                100.0, "Location A", "Good");

        // Test getters
        assert(scooter.getId() == "ABC");
        assert(scooter.getModel() == "Model X");
        assert(scooter.getDateAsString() == "2023-1-1");
        assert(scooter.getDate().getDateAsFormattedString() == "2023-1-1");
        assert(scooter.getMileage() == 100.0);
        assert(scooter.getLocation() == "Location A");
        assert(scooter.getCondition() == "Good");

        // Test setters
        scooter.setId("DEF");
        assert(scooter.getId() == "DEF");

        scooter.setModel("Model Y");
        assert(scooter.getModel() == "Model Y");

        scooter.setDate("2023-2-1");
        assert(scooter.getDateAsString() == "2023-2-1");
        assert(scooter.getDate().getDateAsFormattedString() == "2023-2-1");

        Date newDate(2023, 3, 1);
        scooter.setDate(newDate);
        assert(scooter.getDateAsString() == "2023-3-1");
        assert(scooter.getDate().getDateAsFormattedString() == "2023-3-1");

        scooter.setMileage(200.0);
        assert(scooter.getMileage() == 200.0);

        scooter.setLocation("Location B");
        assert(scooter.getLocation() == "Location B");

        scooter.setCondition("Fair");
        assert(scooter.getCondition() == "Fair");

        // Test invalid identifier length
        try {
            ElectricScooter invalidScooter("ABCD", "Model Z",
                                           "2023-4-1", 300.0,
                                           "Location C", "Excellent");
            assert(false);  // This line should not be reached
        } catch (const std::invalid_argument &e) {
            assert(true);  // Exception caught, the test passed
        }

        // Test empty model
        scooter.setModel("");
        assert(scooter.getModel().empty());

        // Test empty condition
        scooter.setCondition("");
        assert(scooter.getCondition().empty());

        std::cout << "All tests passed successfully!" << std::endl;
    }

    {
        // Create an instance of ElectricScooter
        ElectricScooter scooter("001", "Model X", "2022-1-1",
                                1000.5, "Park A", "Good");

        // Call toString()
        string result = scooter.toString();

        // Expected string representation
        string expected = "001,Model X,2022-1-1,1000.5,Park A,Good";

        // Compare the result with the expected string
        assert(result == expected);
    }

    {
        ElectricScooter scooter1("001", "Model X", "2022-1-1",
                                 1000.5, "Park A", "Good");
        ElectricScooter scooter2("004", "Model X", "2022-1-1",
                                 1000.5, "Park A", "Good");
        ElectricScooter scooter3("001");

        assert(scooter1 == scooter3);
        assert(scooter1 != scooter2);
        assert(scooter2 != scooter3);

        assert(scooter1.toString() == "001,Model X,2022-1-1,1000.5,Park A,Good");
        assert(scooter1.convertFromString(scooter1.toString())->getId() == scooter1.getId());
        assert(scooter1.getAttributes() ==
               "Identifier,Model,commissioning Date,Mileage,last Location,current Condition");
    }
}