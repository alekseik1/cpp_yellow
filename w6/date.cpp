#include "date.h"
#include <iostream>
#include <iomanip>
#include <ctime>

ostream& operator<<(ostream& os, const Date& date) {
    os << setfill('0') << setw(4) << date.year << "-"
    << setfill('0') << setw(2) << date.month << "-"
    << setfill('0') << setw(2) << date.day;
    return os;
}
Date::Date(const int& day, const int& month, const int& year): day(day), month(month), year(year) {
    if ((day > 31) || (day < 1)) { throw runtime_error("Day should be in [1, 31]"); }
    if ((month > 12) || (month < 1)) { throw runtime_error("Month should be in [1, 12]"); }
};

Date ParseDate(istream& is) {
    string string_date; is >> string_date;
    tm tm{};
    strptime(string_date.c_str(), "%F", &tm);
    return {tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900};
}

int main() {
    Date d = ParseDate(cin);
    cout << d;
}
