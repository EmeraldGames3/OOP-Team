#include "TestElectricScooter.h"
#include <cassert>
#include "../../../Domain/Domain.h"

using Domain::ElectricScooter;

void testElectricScooter() {
    // Create an electric scooter object with valid arguments
    ElectricScooter scooter("ABC", "Model X", "2023-01-01",
                            100.0, "Location A", "Good");

    // Test getters
    assert(scooter.getId() == "ABC");
    assert(scooter.getModel() == "Model X");
    assert(scooter.getDateAsString() == "2023-01-01");
    assert(scooter.getDate().getDateAsFormattedString() == "2023-01-01");
    assert(scooter.getMileage() == 100.0);
    assert(scooter.getLocation() == "Location A");
    assert(scooter.getCondition() == "Good");

    // Test setters
    scooter.setId("DEF");
    assert(scooter.getId() == "DEF");

    scooter.setModel("Model Y");
    assert(scooter.getModel() == "Model Y");

    scooter.setDate("2023-02-01");
    assert(scooter.getDateAsString() == "2023-02-01");
    assert(scooter.getDate().getDateAsFormattedString() == "2023-02-01");

    Date newDate(2023, 3, 1);
    scooter.setDate(newDate);
    assert(scooter.getDateAsString() == "2023-03-01");
    assert(scooter.getDate().getDateAsFormattedString() == "2023-03-01");

    scooter.setMileage(200.0);
    assert(scooter.getMileage() == 200.0);

    scooter.setLocation("Location B");
    assert(scooter.getLocation() == "Location B");

    scooter.setCondition("Fair");
    assert(scooter.getCondition() == "Fair");

    // Test invalid identifier length
    try {
        ElectricScooter invalidScooter("ABCD", "Model Z",
                                       "2023-04-01", 300.0,
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