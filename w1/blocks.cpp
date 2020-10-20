#include <iostream>
#include <limits>

int main() {
    // std::cout << std::numeric_limits<uint64_t>::max() << std::endl;
    uint32_t N = 0;
    uint16_t R = 0;
    uint64_t result = 0;
    std::cin >> N >> R;
    for(auto i=0; i < N; ++i) {
        // Be careful, * operator can lead to overflow!
        uint64_t W, H, D = 0;
        std::cin >> W >> H >> D;
        result += W*H*D*R;
    }
    std::cout << result << std::endl;
    return 0;
}
