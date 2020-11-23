//
// Created by Aleksei Kozharin on 23.11.2020.
//
#include <set>
#include <iostream>
#include <iterator>

using namespace std;

set<int>::const_iterator FindNearestElement(const set<int>& numbers, int border) {
    auto gt = numbers.lower_bound(border);
    if (gt == numbers.begin()) return gt;
    auto le = prev(gt);
    if (gt == numbers.end()) return le;
    if (border - *le <= *gt - border) {
        return le;
    }
    return gt;
}

int main() {
    set<int> numbers = {1, 4, 6};
    cout <<
         *FindNearestElement(numbers, 0) << " " <<
         *FindNearestElement(numbers, 3) << " " <<
         *FindNearestElement(numbers, 5) << " " <<
         *FindNearestElement(numbers, 6) << " " <<
         *FindNearestElement(numbers, 100) << endl;

    set<int> empty_set;

    cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
    return 0;
}