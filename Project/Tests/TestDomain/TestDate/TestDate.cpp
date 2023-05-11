#include "TestDate.h"
#include "../../../Domain/Domain.h"
#include <cassert>

using Domain::Date;

void testDateSimple() {
    // Create a new Date object
    Date d(2023, 4, 18);

    // Test the getters
    assert(d.getYear() == 2023);
    assert(d.getMonth() == 4);
    assert(d.getDay() == 18);

    // Test the setters
    d.setYear(2024);
    assert(d.getYear() == 2024);

    d.setMonth(5);
    assert(d.getMonth() == 5);

    d.setDay(6);
    assert(d.getDay() == 6);
}

void testDateExtended(){
    {
        // Test constructors and getters
        Date date1(2023, 4, 26);
        Date date2(2024, 2, 29);
        Date date3(2025, 12, 31);

        assert(date1.getYear() == 2023);
        assert(date1.getMonth() == 4);
        assert(date1.getDay() == 26);

        assert(date2.getYear() == 2024);
        assert(date2.getMonth() == 2);
        assert(date2.getDay() == 29);

        assert(date3.getYear() == 2025);
        assert(date3.getMonth() == 12);
        assert(date3.getDay() == 31);

        // Test setters and safeguards
        date1.setYear(2022);
        date1.setMonth(10);
        date1.setDay(31);

        assert(date1.getYear() == 2022);
        assert(date1.getMonth() == 10);
        assert(date1.getDay() == 31);

        bool caughtException = false;
        try {
            date1.setYear(-2022);
        } catch (std::invalid_argument &e) {
            caughtException = true;
        }
        assert(caughtException);

        caughtException = false;
        try {
            date1.setMonth(13);
        } catch (std::invalid_argument &e) {
            caughtException = true;
        }
        assert(caughtException);

        caughtException = false;
        try {
            date1.setDay(32);
        } catch (std::invalid_argument &e) {
            caughtException = true;
        }
        assert(caughtException);

        // Test copy constructor and assignment operator
        Date date4 = date3;
        assert(date4.getYear() == 2025);
        assert(date4.getMonth() == 12);
        assert(date4.getDay() == 31);

        date4 = date2;
        assert(date4.getYear() == 2024);
        assert(date4.getMonth() == 2);
        assert(date4.getDay() == 29);

        // Test comparison operators
        assert(date1 < date2);
        assert(date2 > date1);
        assert(date1 <= date1);
        assert(date1 >= date1);
        assert(date1 != date2);
        assert(date2 == date4);
    }

    // Test converting a date to a string
    {
        // Test case 1: Date with day, month, and year values of 1
        Date date1(1, 1, 1);
        assert(date1.getDateAsFormattedString() == "1-1-1");

        // Test case 2: Date with day, month, and year values of 31
        Date date2(2022, 12, 31);
        assert(date2.getDateAsFormattedString() == "2022-12-31");

        // Test case 3: Date with day value of 10, month value of 2, and year value of 2023
        Date date3(2023, 2, 10);
        assert(date3.getDateAsFormattedString() == "2023-2-10");

        // Test case 4: Date with day value of 29, month value of 2, and year value of 2024 (leap year)
        Date date4(2024, 2, 29);
        assert(date4.getDateAsFormattedString() == "2024-2-29");
    }
}

void testDate(){
    testDateSimple();
    testDateExtended();
}