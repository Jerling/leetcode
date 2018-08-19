#include <iostream>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <clocale>

/*
  分析：
  一个一个比较
*/
// T:n, S:1
class MySolution
{
public:
    bool ValidPalindrome(const std::string str){
        const int length = str.size();
        for (int i = 0,j=0; i < length/2 ; i++,j++) {
            for(;!std::isalpha(str[i]);i++);
            for(;!std::isalpha(str[length-j-1]);j++);
            // std::cout << str[i] << " " << str[length-j-1] << std::endl;
            if(tolower(str[i]) != tolower(str[length-j-1])) return false;
        }
        return true;
    }
};

// Valid Palindrome
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    bool isPalindrome(std::string s) {
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        auto left = s.begin(), right = prev(s.end());
        while (left < right) {
            if (!::isalnum(*left))  ++left;
            else if (!::isalnum(*right)) --right;
            else if (*left != *right) return false;
            else { left++, right--; }
        }
        return true;
    }
};
