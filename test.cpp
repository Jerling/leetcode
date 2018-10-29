#include "test.hpp"

int main(void)
{
    std::vector<int> v{12,4,5,7,8,2,10};
    auto print = [](auto a){std::cout << a << " ";};
    for_each(v.begin(), v.end(), print);
    int kth = MySolution().k_th_largest_element(v, 3);
    std::cout << kth << "\n";
    for_each(v.begin(), v.end(), print);
    return 0;
}
