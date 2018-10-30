#include "test.hpp"

int main(void)
{
    std::vector<int> v{5, 6, 7, 8, 9, 10};
    int r = Solution().search_insert_position(v, 9);
    std::cout << r << "\n";
    return 0;
}
