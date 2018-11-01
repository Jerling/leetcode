#include "test.hpp"

int main(void)
{
    std::vector<int>v{1,   4,  7, 11, 15};
    std::vector<int>v1{2,   5,  8, 12, 19};
    std::vector<int> v2{3,   6,  9, 16, 22};
    std::vector<std::vector<int> >mat{v, v1, v2};
    std::cout << MySolution().search_a_2D_2(mat, 1) << std::endl;
    return 0;
}
