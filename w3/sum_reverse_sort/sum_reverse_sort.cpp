//
// Created by Aleksei Kozharin on 17.11.2020.
//

#include "sum_reverse_sort.h"
#include <algorithm>

int Sum(int x, int y) {
    return x + y;
}

string Reverse(string s) {
    std::reverse(s.begin(), s.end());
    return s;
}

void Sort(vector<int>& v) {
    std::sort(v.begin(), v.end());
}
