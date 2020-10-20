//
// Created by Aleksei Kozharin on 18.10.2020.
//

#include <iostream>
#include <limits>
#include <vector>

using namespace std;


void PrintAvg() {
    vector<int> t = {-8, -7, 3};
    int sum = 0;
    for (int x : t)
        sum += x;
    int avg = sum / t.size();
    cout << avg << endl;
}

int main() {
    vector<int> v = {1, 4, 5};
    for (size_t k = v.size(); k > 0; --k) {
        size_t i = k - 1;
        cout << v[i] << endl;
    }
}

