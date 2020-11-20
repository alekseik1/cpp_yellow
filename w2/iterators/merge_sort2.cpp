//
// Created by Aleksei Kozharin on 20.11.2020.
//
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

/**
template <typename RandomIt>
void merge(RandomIt& first_begin, RandomIt& first_end, RandomIt& second_begin, RandomIt& second_end) {
    RandomIt& curr_first = first_begin;
    RandomIt& curr_second = second_begin;
    while ((curr_first != first_end) && (curr_second != second_end)) {
        auto& a = *curr_first;
        auto& b = *curr_second;
        if (a > b) {
            rotate(curr_first, curr_second++, curr_second);
        } else {
            ++curr_first;
        }
    }
}
 */

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    if (range_end - range_begin <= 1) return;
    vector<typename RandomIt::value_type> elements(range_begin, range_end);
    auto middle = elements.begin() + (elements.end() - elements.begin())/2;
    MergeSort(elements.begin(), middle);
    MergeSort(middle, elements.end());
    merge(elements.begin(), middle, middle, elements.end(), range_begin);
}

int main() {
    vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
    // vector<int> v = {-5, -2, 10, -10, -24, 0, -59, 8};
    MergeSort(begin(v), end(v));
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    sort(v.begin(), v.end());
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}

