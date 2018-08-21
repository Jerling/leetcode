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
            if(expr[i]=='?') ++j;
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

// Wildcard Matching
// 递归版，会超时，用于帮助理解题意
// 时间复杂度O(n!*m!)，空间复杂度O(n)
class Solution_1 {
public:
    bool isMatch(const std::string& s, const std::string& p) {
        return isMatch(s.c_str(), p.c_str());
    }
private:
    bool isMatch(const char *s, const char *p) {
        if (*p == '\0' || *s == '\0') return *p == *s;
        else if (*p == '*') {
            while (*p == '*') ++p;  //skip continuous '*'
            if (*p == '\0') return true;
            while (*s != '\0' && !isMatch(s, p)) ++s;

            return *s != '\0';
        }
        else if (*p == *s || *p == '?') return isMatch(++s, ++p);
        else return false;
    }
};

// Wildcard Matching
// 迭代版，时间复杂度O(n*m)，空间复杂度O(1)
class Solution_2 {
public:
    bool isMatch(const std::string& s, const std::string& p) {
        return isMatch(s.c_str(), p.c_str());
    }
private:
    bool isMatch(const char *s, const char *p) {
        bool star = false;
        const char *str, *ptr;
        for (str = s, ptr = p; *str != '\0'; str++, ptr++) {
            switch (*ptr) {
            case '?':
                break;
            case '*':
                star = true;
                s = str, p = ptr;
                while (*p == '*') p++;  //skip continuous '*'
                if (*p == '\0') return true;
                str = s - 1;
                ptr = p - 1;
                break;
            default:
                if (*str != *ptr) {
                    // 如果前面没有'*'，则匹配不成功
                    if (!star) return false;
                    s++;
                    str = s - 1;
                    ptr = p - 1;
                }
            }
        }
        while (*ptr == '*') ptr++;
        return (*ptr == '\0');
    }
};
