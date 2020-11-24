#include "database.h"
#include <algorithm>
#include <vector>

using namespace std;

vector<Entry> Database::filterEvents(function<bool(const Date &, const string &)> pred) const {
    vector<Entry> found;
    for (const auto& i : _data) {
        const auto &date = i.first;
        const auto &events = i.second;
        for (const string &event : events)
            if (pred(date, event)) found.push_back(make_pair(date, event));
    }
    return found;
}

void Database::Add(const Date &date, const string &event) {
    if (!_dataSet[date].count(event)) {
        _data[date].push_back(event);
        _dataSet[date].insert(event);
    }
}

size_t Database::RemoveIf(function<bool(const Date &, const string &)> predicate) {
    size_t deletedSize = 0;
    vector<Date> emptyKeys;
    for (auto &item : _data) {
        const auto &date = item.first;
        auto &events = item.second;
        auto it = stable_partition(
                events.begin(), events.end(),
                [date, predicate](const string &event) { return !predicate(date, event); }
        );
        deletedSize += events.end() - it;
        // Clean _dataSet
        for(auto it1 = it; it1 != events.end(); next(it1)) _dataSet[date].erase(*it1);
        // Clean _data
        events.erase(it, events.end());
        if (events.empty()) emptyKeys.push_back(date);
    }
    // Remove emptied keys afterwards. Note that it is not possible to do that in loop above
    for (const auto& item : emptyKeys) _data.erase(item);
    return deletedSize;
}

vector<Entry> Database::FindIf(function<bool(const Date &, const string &)> predicate) {
    return filterEvents(predicate);
}

ostream& operator<<(ostream &os, const Entry &entry) {
    os << entry.first << " " << entry.second;
    return os;
}

void Database::Print(ostream &os) const {
    vector<Entry> all_events = filterEvents([](const Date &date, const string &event) {return true; });
    for(auto &item : all_events)
        os << item << endl;
}

Entry Database::Last(const Date &date) const {
    auto it = _data.upper_bound(date);
    if (it == _data.begin()) throw invalid_argument("Date is smaller than least date in DB");
    prev(it);
    return make_pair(it->first, *(prev(it->second.end())));
}

