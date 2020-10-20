#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

enum class Lang {
    DE, FR, IT
};

struct Region {
    string std_name;
    string parent_std_name;
    map<Lang, string> names;
    int64_t population;
};

bool operator<(const Region & lhs,const Region & rhs){
    return tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) <
           tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
};

/** Авторское решение
int FindMaxRepetitionCount(const vector<Region>& regions) {
    int result = 0;
    map<Region, int> repetition_count;
    for (const Region& region : regions) {
        result = max(result, ++repetition_count[region]);
    }
    return result;
}
 */

int FindMaxRepetitionCount(const vector<Region>& regions) {
    std::map<Region, int> repetitions;
    for(const auto& item: regions) {
        if(repetitions.find(item) == repetitions.end()) {
            repetitions[item] = 1;
        } else {
            repetitions[item] += 1;
        }
    }
    int result = 0;
    for(auto& key: repetitions) {
        if (key.second > result) {
            result = key.second;
        }
    }
    return result;
}