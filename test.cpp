#include "test.hpp"

int main(void)
{
    std::vector<int> v{8, 9, 10, 5, 6, 8, 8, 8, 8, 8};
    int r = MySolution().search_in_rotated_sorted_array(v, 10);
    std::cout << r << "\n";
    return 0;
}
