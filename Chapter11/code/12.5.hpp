#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>


class Solution {
public:
    unsigned int LongestSubString(const std::string &strs) {
        std::unordered_set<char> substr;
        size_t maxlen = 0;
        for (size_t i=0; i<strs.length(); i++) {
            if (substr.find(strs[i]) == substr.end()) {
                substr.insert(strs[i]);
                maxlen = std::max(substr.size(), maxlen);
            } else {
                substr.clear();
                substr.insert(strs[i]);
            }
        }
        return maxlen;
    }
};

// Longest Substring Without Repeating Characters
// 时间复杂度O(n)，空间复杂度O(1)
// 考虑非字母的情况
class Solution_1 {
public:
    int lengthOfLongestSubstring(std::string s) {
        const int ASCII_MAX = 255;
        int last[ASCII_MAX]; // 记录字符上次出现过的位置
        int start = 0; // 记录当前子串的起始位置

        std::fill(last, last + ASCII_MAX, -1); // 0也是有效位置，因此初始化为-1
        int max_len = 0;
        for (int i = 0; i < s.size(); i++) {
            if (last[s[i]] >= start) {
                max_len = std::max(i - start, max_len);
                start = last[s[i]] + 1;
            }
            last[s[i]] = i;
        }
        return std::max((int)s.size() - start, max_len);  // 别忘了最后一次，例如"abcd"
    }
};
