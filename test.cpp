#include "test.hpp"

int main(void)
{
    std::vector<int> v{1,2,0};
    std::cout << Solution().firstMissingPositive(v) << "\n";
    return 0;
}
