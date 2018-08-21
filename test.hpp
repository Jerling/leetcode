#include <iostream>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <cmath>
#include <limits.h>

// Add Binary
// 时间复杂度O(n)，空间复杂度O(1)
class MySolution {
public:
    std::string longestPalindromicSubstring(const std::string &str){
        if (!str || str.length() == 1) return str;
        int max = 0, curlen = 0;
        int len = str.length();
        for(int i=1; i < len-1; ++i){
            if(str[i]==str[i-1]){
                for(j=1;j<len-i-1 && j<i && str[i-j-i]==str[i+j];++j);
            }
        }
    }
};

// Add Binary
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        std::string result;
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        while(i >= 0 || j >= 0 || carry > 0) {
            int valueA = i < 0 ? 0 : a[i--] - '0';
            int valueB = j < 0 ? 0 : b[j--] - '0';
            int sum = valueA + valueB + carry;
            result.insert(result.begin(), (sum % 2) + '0');
            carry = sum / 2;
        }
        return result;
    }
};
