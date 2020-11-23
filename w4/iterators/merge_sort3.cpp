//
// Created by Aleksei Kozharin on 20.11.2020.
//
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    if (range_end - range_begin <= 1) return;
    vector<typename RandomIt::value_type> elements(range_begin, range_end);
    auto sp1 = elements.begin() + (elements.end() - elements.begin())/3;
    auto sp2 = sp1 + (elements.end() - elements.begin())/3;
    MergeSort(elements.begin(), sp1);
    MergeSort(sp1, sp2);
    MergeSort(sp2, elements.end());
    vector<typename RandomIt::value_type> tmp_res;
    merge(elements.begin(), sp1, sp1, sp2, back_inserter(tmp_res));
    merge(tmp_res.begin(), tmp_res.end(), sp2, elements.end(), range_begin);
}

int main() {
    vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, 5};
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

