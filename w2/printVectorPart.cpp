//
// Created by Aleksei Kozharin on 18.11.2020.
//
#include <iostream>
#include <vector>
#include <algorithm>
void PrintVectorPart(const std::vector<int>& numbers) {
    auto it = std::find_if(
            numbers.begin(), numbers.end(),
            [](const int a) { return a < 0; }
    );
    for (auto i = it; i != numbers.begin(); )
        std::cout << *(--i) << " ";
}

int main() {
    PrintVectorPart({6, 1, 8, -5, 4});
    std::cout << std::endl;
    PrintVectorPart({-6, 1, 8, -5, 4});  // ничего не выведется
    std::cout << std::endl;
    PrintVectorPart({6, 1, 8, 5, 4});
    std::cout << std::endl;
    return 0;
}
