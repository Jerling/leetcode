#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <ctype.h>
#include <cmath>
#include <limits.h>

// Add Binary
// 时间复杂度O(n)，空间复杂度O(1)
// 题意理解有点误差，不过思路是对的，只是是多个字符串找最长前缀
class MySolution {
public:
    std::string LongestCommonPrefix(const std::string &str1, const std::string &str2){
        const int lenstr1 = str1.length(), lenstr2 = str2.length();
        std::string lcp;
        int i=0;
        while(i < lenstr1 && lenstr2 && str1[i] == str2[i]){
            lcp.push_back(str1[i]);
            ++i;
        }
        return lcp;
    }
};

// Longest Common Prefix
// 纵向扫描，从位置0开始，对每一个位置比较所有字符串，直到遇到一个不匹配
// 时间复杂度O(n1+n2+...)
// @author 周倩 (http://weibo.com/zhouditty)
class Solution_1 {
public:
    std::string longestCommonPrefix(std::vector<std::string> &strs) {
        if (strs.empty()) return "";

        for (int j = 0; j < strs[0].size(); ++j) { // 纵向扫描
            for (int i = 1; i < strs.size(); ++i) {
                // 不会越界，请参考string::[]的文档
                if (strs[i][j] != strs[0][j])
                    return strs[0].substr(0,j);
            }
        }
        return strs[0];
    }
};
// Longest Common Prefix
// 横向扫描，每个字符串与第0个字符串，从左到右比较，直到遇到一个不匹配，
// 然后继续下一个字符串
// 时间复杂度O(n1+n2+...)
class Solution_2{
public:
    std::string longestCommonPrefix(std::vector<std::string> &strs) {
        if (strs.empty()) return "";

        int right_most = strs[0].size();
        for (size_t i = 1; i < strs.size(); i++)
            for (int j = 0; j < right_most; j++)
                if (strs[i][j] != strs[0][j])  // 不会越界，请参考string::[]的文档
                    right_most = j;

        return strs[0].substr(0, right_most);
    }
};
