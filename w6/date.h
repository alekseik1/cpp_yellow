#pragma once
#include <iostream>
#include <exception>

using namespace std;
class Date {
public:
    const int day = 1;
    const int month = 1;
    const int year = 1900;
    Date(const int& day, const int& month, const int& year);
    bool operator<(const Date &other) const;
    bool operator<=(const Date &other) const;
    bool operator>=(const Date &other) const;
    bool operator>(const Date &other) const;
    bool operator==(const Date &other) const;
    bool operator!=(const Date &other) const;
};

Date ParseDate(istream& is);
ostream& operator<<(ostream& os, const Date& date);