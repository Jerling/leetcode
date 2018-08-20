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
    std::string addBinary(const std::string &str1, const std::string &str2){
        int l1 = str1.length()-1;
        int l2 = str2.length()-1;
        std::string result;
        int jinwei = 0;
        while(l1 >= 0 && l2 >=0){
            result.push_back('0'+(str1[l1] - '0' + str2[l2] - '0' + jinwei)%2);
            jinwei = (str1[l1] - '0' + str2[l2] - '0' + jinwei)/2;
            --l1;--l2;
        }
        while(l1 >= 0){
            result.push_back('0' + (str1[l1]-'0'+jinwei)%2);
            jinwei = (str1[l1]-'0'+jinwei)/2;
            --l1;
        }
        while(l2 >= 0){
            result.push_back('0' + (str2[l2]-'0'+jinwei)%2);
            jinwei = (str1[l2]-'0'+jinwei)/2;
            --l2;
        }
        if(jinwei) result.push_back(jinwei+'0');
        std::reverse(result.begin(),result.end());   // 逆转结果
        return result;
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
