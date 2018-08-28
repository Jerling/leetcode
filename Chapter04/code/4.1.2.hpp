#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

// Longest Valid Parentheses
// 时间复杂度O(n)，空间复杂度O(n)
// 解题有误，没有考虑连续
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

// LeetCode, Longest Valid Parenthese
// T: O(n), S:  O(n)
class Solution {
public:
    int longestValidParentheses(const std::string& s) {
        int max_len = 0, last = -1; // the position of the last ')'
        std::stack<int> lefts;  // keep track of the positions of non-matching '('s
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] =='(') {
                lefts.push(i);
            } else {
                if (lefts.empty()) {
                    // no matching left
                    last = i;
                } else{
                    // find a matching pair
                    lefts.pop();
                    if (lefts.empty()) {
                        max_len = max(max_len, i-last);
                    } else {
                        max_len = max(max_len, i-lefts.top());
                    }
                }
            }
        }
        return max_len;
    }
private:
    int max(int a, int b){
        return a>b?a:b;
    }
};
