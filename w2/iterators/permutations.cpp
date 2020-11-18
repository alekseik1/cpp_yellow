//
// Created by Aleksei Kozharin on 18.11.2020.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

template<typename T>
std::ostream& operator << (std::ostream& os, const std::vector<T>& v) {
    for (auto& i : v) os << i << " ";
    os << std::endl;
    return os;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> v;
    std::set<std::vector<int>> permutations;
    for (auto i = 1; i <= n; ++i) v.push_back(i);
    do {
        permutations.insert(v);
    } while (std::next_permutation(v.begin(), v.end()));
    for(auto i = permutations.rbegin(); i != permutations.rend(); ++i) std::cout << *i;
}
