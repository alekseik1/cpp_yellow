#include <iostream>
#include <vector>
#include <map>
#include <stdexcept>

using namespace std;

template <typename Key, typename Value>
Value& GetRefStrict(map<Key, Value>& m, Key k) {
    for (auto& pair : m) {
        if (pair.first == k) {
            return pair.second;
        }
    }
    throw runtime_error("Not found");
}


int main() {
    map<int, string> m = {{0, "value"}};
    string& item = GetRefStrict(m, 0);
    item = "newvalue";
    cout << m[0] << endl; // выведет newvalue
    return 0;
}