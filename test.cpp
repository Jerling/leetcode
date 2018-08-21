#include "test.hpp"

int main(void)
{
    std::string str1("12332111");
    std::string str2("?2*2*");
    std::cout << MySolution().isMatch(str1, str2) << std::endl;
    return 0;
}
