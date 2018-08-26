#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <functional>

// 本地解题不严谨，万一最后的不是字母就出错了
class MySolution
{
public:
    int LastLengthOfWord(const std::string &str){
        size_t len = str.size() - 1;
        while(len > 0 && str[len] !=' ') --len;
        return str.size() - len - 1;
    }
};


// Length of Last Word
// 偷懒，用 STL
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    int lengthOfLastWord(const std::string& s) {
        auto first = find_if(s.rbegin(), s.rend(), ::isalpha);
        auto last = find_if_not(first, s.rend(), ::isalpha);
        return distance(first, last);
    }
};
