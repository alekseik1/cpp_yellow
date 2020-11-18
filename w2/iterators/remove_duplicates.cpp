//
// Created by Aleksei Kozharin on 18.11.2020.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
ostream& operator << (ostream& os, const vector<T>& v) {
    for (auto& i : v) os << i << " ";
    os << endl;
    return os;
}

template <typename T>
void RemoveDuplicates(vector<T>& elements) {
    //set<T> unique = set<T>(elements.begin(), elements.end());
    //elements = vector<T>(unique.begin(), unique.end());
    sort(begin(elements), end(elements));
    cout << "After sort:" << endl << elements;
    auto start = unique(begin(elements), end(elements));
    cout << "After unique:" << endl <<elements;
    cout << start - begin(elements) << endl;
    elements.erase(start, elements.end());
}

int main() {
    vector<int> v1 = {6, 4, 7, 6, 4, 4, 0, 1};
    RemoveDuplicates(v1);
    for (int x : v1) {
        cout << x << " ";
    }
    cout << endl;

    vector<string> v2 = {"C", "C++", "C++", "C", "C++"};
    RemoveDuplicates(v2);
    for (const string& s : v2) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}
