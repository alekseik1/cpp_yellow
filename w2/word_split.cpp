//
// Created by Aleksei Kozharin on 18.11.2020.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> SplitIntoWords(const string& s) {
    vector<string> result;
    auto it = s.begin();
    while (it != s.end())
    {
        auto space_pos = find(it, s.end(), ' ');
        result.emplace_back(string(it, space_pos));
        if (space_pos == s.end()) break;
        it = ++space_pos;
    }
    return result;
}

/**
int main() {
    string s = "C Cpp Java Python";

    vector<string> words = SplitIntoWords(s);
    cout << words.size() << " ";
    for (auto it = begin(words); it != end(words); ++it) {
        if (it != begin(words)) {
            cout << "/";
        }
        cout << *it;
    }
    cout << endl;

    return 0;
}
*/
