#include <algorithm>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

template <typename T> T Sqr(T& t);
template <typename T> vector<T> Sqr(vector<T>& v);
template <typename T1, typename T2> pair<T1, T2> Sqr(pair<T1, T2>& p);
template <typename Key, typename Value> map<Key, Value> Sqr(map<Key, Value>& d);

template <typename T>
T Sqr(T& t) {
    return t * t;
}


template <typename T>
vector<T> Sqr(vector<T>& v) {
    vector<T> rv;
    rv.reserve(v.size());
    for(auto& i : v) {
        rv.push_back(Sqr(i));
    }
    return rv;
}

template <typename T1, typename T2>
pair<T1, T2> Sqr(pair<T1, T2>& p) {
    return make_pair(Sqr(p.first), Sqr(p.second));
}

template <typename Key, typename Value>
map<Key, Value> Sqr(map<Key, Value>& d) {
    map<Key, Value> rv;
    for(auto& pair : d) {
        rv.insert(make_pair(pair.first, Sqr(pair.second)));
    }
    return rv;
}


int main() {
    // Пример вызова функции
    vector<int> v = {1, 2, 3};
    cout << "vector:";
    for (int x : Sqr(v)) {
        cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {
            {4, {2, 2}},
            {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }
    return 0;
}