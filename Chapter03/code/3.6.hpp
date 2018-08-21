#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <ctype.h>
#include <cmath>
#include <limits.h>

// Add Binary
// 时间复杂度O(n)，空间复杂度O(1)
class MySolution {
public:
    bool isMatch(const std::string &str, const std::string &expr){
        int lenexpr = expr.length();
        int lenstr = str.length();
        for(int i=0,j=0; i<lenexpr && j<lenstr; ++i){
            if(expr[i]=='.') ++j;
            else if(expr[i]=='*') continue;
            else if(expr[i] != str[j]){
                if(expr[i-1] == '*'){
                    for(; expr[i]!=str[j] && j < lenstr;j++);
                    if(j==lenstr) return false;
                }
                else return false;
            }
            else ++j;
        }
        return true;
    }
};

// Regular Expression Matching
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    bool isMatch(const std::string& s, const std::string& p) {
        return isMatch(s.c_str(), p.c_str());
    }
private:
    bool matchFirst(const char *s, const char *p) {
        return *p == *s || (*p == '.' && *s != '\0');
    }

    bool isMatch(const char *s, const char *p) {
        if (*p == '\0') return *s == '\0';    //empty

        // next char is not '*', then must match current character
        if (*(p + 1) != '*') {
            if (matchFirst(s, p)) return isMatch(s + 1, p + 1);
            else return false;
        } else { // next char is '*'
            if (isMatch(s, p + 2)) return true;    // try the length of 0
            while ( matchFirst(s, p) )       // try all possible lengths
                if (isMatch(++s, p + 2)) return true;
            return false;
        }
    }
};
