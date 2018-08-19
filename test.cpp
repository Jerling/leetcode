#include "test.hpp"

int main(void)
{
    std::string str1 = {"A man, a plan, a canal: Panama"};
    std::string str2 = {"race a car"};
    std::cout << str1 << "\n" << str2 << std::endl;
    std::cout << MySolution().ValidPalindrome(str1) << std::endl;
    std::cout << MySolution().ValidPalindrome(str2) << std::endl;
    std::cout << Solution().isPalindrome(str2) << std::endl;

    return 0;
}
