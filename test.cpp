#include "test.hpp"

int main(void)
{
    std::string str1("12332111");
    std::string str2("1");
    std::cout << MySolution().longestPalindromicSubstring(str1) << std::endl;
    std::cout << Solution_1().longestPalindrome(str1) << std::endl;
    std::cout << Solution_2().longestPalindrome(str1) << std::endl;
    std::cout << Solution_3().longestPalindrome(str1) << std::endl;
    return 0;
}
