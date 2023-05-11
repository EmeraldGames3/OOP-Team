#include "Date.h"

///Default constructor
///@throws invalid_argument If an invalid date is provided
Domain::Date::Date(int _year, int _month, int _day) {
    if (_year <= 0 || _month <= 0 || _day <= 0)
        throw std::invalid_argument("Time is represented as a positive integer");

    if (_month > 12)
        throw std::invalid_argument("There are only 12 months in a year");

    int daysInMonth = 31;
    if (_month == 2) // February
        daysInMonth = (_year % 4 == 0 && _year % 100 != 0) || (_year % 400 == 0) ? 29 : 28;
    else if (_month == 4 || _month == 6 || _month == 9 || _month == 11) // April, June, September, November
        daysInMonth = 30;

    if (_day > daysInMonth)
        throw std::invalid_argument("Invalid day");

    year = _year;
    month = _month;
    day = _day;
}

///Year getter
int Domain::Date::getYear() const {
    return year;
}

///Month getter
int Domain::Date::getMonth() const {
    return month;
}

///Day getter
int Domain::Date::getDay() const {
    return day;
}

///Convert the date to a string
std::string Domain::Date::getDateAsFormattedString() const {
    return std::to_string(year) + '-' + std::to_string(month) + '-' + std::to_string(day);
}

///Year setter
///@throws invalid_argument if an invalid year is provided
void Domain::Date::setYear(int newYear) {
    if (newYear >= 0)
        year = newYear;
    else
        throw std::invalid_argument("Year cannot be negative.");
}

///Month setter
///@throws invalid_argument if an invalid month is provided
void Domain::Date::setMonth(int newMonth) {
    if (newMonth >= 1 && newMonth <= 12)
        month = newMonth;
    else
        throw std::invalid_argument("Month must be between 1 and 12.");
}

///Check if a year is a leap year
bool isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return true;
    return false;
}

///Find how many days are in a month
int Domain::Date::daysInMonth(int year, int month) {
    const int daysInMonth[] = {31, 28 + isLeapYear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return daysInMonth[month - 1];
}

///Day setter
///@throws invalid_argument if the day is invalid
void Domain::Date::setDay(int newDay) {
    int daysInMonth = Date::daysInMonth(year, month);
    if (newDay >= 1 && newDay <= daysInMonth)
        day = newDay;
    else
        throw std::invalid_argument("Day must be between 1 and " + std::to_string(daysInMonth));
}

///Overloaded assignment operator
Domain::Date &Domain::Date::operator=(const Domain::Date &other) {
    if (this != &other) {
        year = other.year;
        month = other.month;
        day = other.day;
    }
    return *this;
}

///Overloaded comparison operators ///
bool Domain::Date::operator>=(const Domain::Date &other) const {
    return !(*this < other);
}

bool Domain::Date::operator>(const Domain::Date &other) const {
    return !(*this <= other);
}

bool Domain::Date::operator<=(const Domain::Date &other) const {
    return (*this < other || *this == other);
}

bool Domain::Date::operator<(const Domain::Date &other) const {
    if (year < other.year) {
        return true;
    } else if (year == other.year && month < other.month) {
        return true;
    } else if (year == other.year && month == other.month && day < other.day) {
        return true;
    } else {
        return false;
    }
}

bool Domain::Date::operator!=(const Domain::Date &other) const {
    return !(*this == other);
}

bool Domain::Date::operator==(const Domain::Date &other) const {
    return (year == other.year && month == other.month && day == other.day);
}