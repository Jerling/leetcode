#include "test.hpp"

int main(void)
{
    std::vector<int> v{1,2,0};
    auto print = [](auto a){std::cout << a << " ";};
    std::cout << Solution().firstMissingPositive(v) << "\n";
    for_each(v.begin(), v.end(), print);
    return 0;
}
