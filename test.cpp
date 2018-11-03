#include "test.hpp"

int main(void)
{
    std::vector<int>v{1, 2, 3, 3};
    auto vv = Solution().combine(4, 2);
    std::cout << vv.size() << "\n";
    return 0;
}
