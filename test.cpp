#include "test.hpp"

int main(void)
{
    std::vector<int> v{0,1,2,0,0,0,1,1,2,1,0,1,2};
    auto print = [](auto a){std::cout << a << " ";};
    for_each(v.begin(), v.end(), print);
    Solution().sortColors(v);
    std::cout << "\n";
    for_each(v.begin(), v.end(), print);
    return 0;
}
