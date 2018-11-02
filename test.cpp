#include "test.hpp"

int main(void)
{
    std::vector<int>v{7, 11, 15, 2, 2, 6};
    std::vector<int>v1{2,   5,  8, 12, 19};
    std::vector<int> v2{3,   6,  9, 16, 22};
    std::vector<std::vector<int> >mat{v, v1, v2};
    auto vv = Solution_5().subsetsWithDup(v);
    std::cout << vv.size() << "\n";
    return 0;
}
