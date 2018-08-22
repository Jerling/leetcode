#include "test.hpp"

int main(void)
{
    std::string str1("12332111");
    std::string str2("12*2*");
    std::cout << MySolution().LongestCommonPrefix(str1, str2) << std::endl;
    return 0;
}
