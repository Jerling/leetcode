#include "test.hpp"

int main(void)
{
    std::vector<int> v{5, 7, 7, 8, 8, 10};
    std::vector<int> r = MySolution().search_a_range(v, 7);
    for_each(r.begin(), r.end(), print);
    return 0;
}
