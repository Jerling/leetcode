#include "test.hpp"

int main(void)
{
    std::vector<int>v{1, 2, 3};
    auto vv = MySolution().permutations(v);
    std::cout << vv.size() << "\n";
    return 0;
}
