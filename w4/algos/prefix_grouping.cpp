//
// Created by Aleksei Kozharin on 23.11.2020.
//
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, const string& prefix) {
    if (range_begin == range_end) return make_pair(range_begin, range_end);
    return equal_range(
            range_begin, range_end, prefix,
            [prefix](const string &a, const string &b) {
                return a.substr(0, prefix.size()) < b.substr(0, prefix.size());
            });
}

int main() {
    const vector<string> sorted_strings = {"moscow", "motovilikha", "murmansk"};

    const auto mo_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
    for (auto it = mo_result.first; it != mo_result.second; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    const auto mt_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
    cout << (mt_result.first - begin(sorted_strings)) << " " <<
         (mt_result.second - begin(sorted_strings)) << endl;

    const auto na_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
    cout << (na_result.first - begin(sorted_strings)) << " " <<
         (na_result.second - begin(sorted_strings)) << endl;

    return 0;
}
