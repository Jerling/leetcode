#include "test.hpp"

int main(void)
{
    std::string str1("123");
    std::string str2("23");
    std::cout << Solution().myAtoi(str1) - Solution().myAtoi(str2);
    return 0;
}
