#pragma once
#include "date.h"
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
using Entry = pair<Date, string>;

class Database {
public:
    void Add(const Date& date, const string& event);
    void Print(ostream& os) const;
    size_t RemoveIf(function<bool(const Date& date, const string& event)> predicate);
    vector<Entry> FindIf(function<bool(const Date& date, const string& event)> predicate);
    Entry Last(const Date& date) const;
private:
    map<Date, vector<string>> _data;
    map<Date, set<string>> _dataSet;
    vector<Entry> filterEvents(function<bool(const Date &date, const string &event)> pred) const;
};

ostream& operator<<(ostream &os, const Entry &entry);