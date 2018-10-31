#include "test.hpp"

int main(void)
{
    std::vector<int>v{1,   3,  5,  7};
    std::vector<int>v1{10, 11, 16, 20};
    std::vector<int> v2{23, 30, 34, 50};
    std::vector<std::vector<int> >mat{v, v1, v2};
    std::cout << MySolution().search_a_2D(mat, 3) << std::endl;
    return 0;
}
