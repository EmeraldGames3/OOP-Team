#pragma once

#include <stdexcept>

namespace Domain {
    class Date {
    private:
        int year;
        int month;
        int day;

    public:
        ///Default Constructor
        explicit Date(int _year = 0, int _month = 0, int _day = 0);

        ///Copy constructor
        Date(const Date &other) = default;

        ///Destructor
        ~Date() = default;

        ///Getters
        [[nodiscard]] int getYear() const;
        [[nodiscard]] int getMonth() const;
        [[nodiscard]] int getDay() const;
        [[nodiscard]] std::string getDateAsFormattedString() const;

        ///Setters
        void setYear(int newYear);
        void setMonth(int newMonth);
        void setDay(int newDay);

        ///Compute the number of days in a month
        static int daysInMonth(int year, int month);

        ///Get the date from a string
        static Date getDateFromString(const std::string &str);

        ///Overloaded operators
        Date &operator=(const Date& other);
        bool operator==(const Date& other) const;
        bool operator!=(const Date& other) const;
        bool operator<(const Date& other) const;
        bool operator<=(const Date& other) const;
        bool operator>(const Date& other) const;
        bool operator>=(const Date& other) const;
    };
}