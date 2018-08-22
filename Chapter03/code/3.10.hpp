#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <ctype.h>
#include <cmath>
#include <limits.h>

// Integer to Roman
// 时间复杂度O(num)，空间复杂度O(1)
class Solution {
public:
    std::string intToRoman(int num) {
        const int radix[] = {1000, 900, 500, 400, 100, 90,
                             50, 40, 10, 9, 5, 4, 1};
        const std::string symbol[] = {"M", "CM", "D", "CD", "C", "XC",
                                 "L", "XL", "X", "IX", "V", "IV", "I"};

        std::string roman;
        for (size_t i = 0; num > 0; ++i) {
            int count = num / radix[i];
            num %= radix[i];
            for (; count > 0; --count) roman += symbol[i];
        }
        return roman;
    }
};
