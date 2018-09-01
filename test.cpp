#include "test.hpp"

int main(void)
{
    std::string str = {'1','2','+','3','*'};
    std::cout << str << "\n";
    std::cout << MySolution().evaluateReversePolishNotation(str) << "\n";
    return 0;
}
