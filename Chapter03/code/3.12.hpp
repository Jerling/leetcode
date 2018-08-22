#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <functional>

// http://www.cnblogs.com/grandyang/p/4086299.html
class Solution_1 {
public:
    std::string countAndSay(int n) {
        if (n <= 0) return "";
        std::string res = "1";
        while (--n) {
            std::string cur = "";
            for (int i = 0; i < res.size(); ++i) {
                int cnt = 1;
                while (i + 1 < res.size() && res[i] == res[i + 1]) {
                    ++cnt;
                    ++i;
                }
                cur += std::to_string(cnt) + res[i];
            }
            res = cur;
        }
        return res;
    }
};
// Count and Say
// @author 连城 (http://weibo.com/lianchengzju)
// 时间复杂度O(n^2)，空间复杂度O(n)
class Solution_2 {
public:
    std::string countAndSay(int n) {
        std::string s("1");

        while (--n)
            s = getNext(s);

        return s;
    }

    std::string getNext(const std::string &s) {
        std::stringstream ss;

        for (auto i = s.begin(); i != s.end(); ) {
            auto j = find_if(i, s.end(), bind1st(not_equal_to(), *i));
            ss << distance(i, j) << *i;
            i = j;
        }

        return ss.str();
    }
};
