#include <iostream>
#include <vector>

int main() {
    int32_t N;
    int64_t sum = 0;
    std::vector<int32_t> temperatures;
    std::cin >> N;
    for(auto i=0; i<N; ++i) {
        int32_t tmp;
        std::cin >> tmp;
        sum += tmp;
        temperatures.push_back(tmp);
    }
    int32_t average = sum / static_cast<int64_t>(temperatures.size());
    std::vector<int32_t> filtered;
    for(auto i=0; i < temperatures.size(); ++i) {
        if (temperatures[i] > average)
            filtered.push_back(i);
    }
    std::cout << filtered.size() << std::endl;
    for (auto item: filtered)
        std::cout << item << " ";
}

