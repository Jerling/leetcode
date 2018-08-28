#include <iostream>
#include <string>
#include <stack>

// Valid Parentheses
// 时间复杂度O(n)，空间复杂度O(n)
class MySolution {
public:
    int LongestValid (std::string const& s) {
        std::string left = "(";
        std::string right = ")";
        std::stack<char> stk;
        int len = 0;

        for (auto c : s) {
            if (left.find(c) != std::string::npos) {
                stk.push (c);
            } else {
                if (stk.empty () || stk.top () != left[right.find (c)])
                    continue;
                else
                    stk.pop ();len += 2;
            }
        }
        return len;
    }
};
