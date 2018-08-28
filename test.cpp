#include "test.hpp"

int main(void)
{
    std::string str1("()())())");
    std::cout << Solution().longestValidParentheses(str1) << "\n";
    std::cout << MySolution().LongestValid(str1) << "\n";
    return 0;
}
