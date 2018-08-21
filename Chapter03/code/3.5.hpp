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
    std::string longestPalindromicSubstring(const std::string &str){
        if (str.length() == 0 || str.length() == 1) return str;
        int max = 0, curlen = 0;
        int len = str.length();
        std::string result;
        for(int i=1; i < len-1; ++i){
            if(str[i]==str[i-1]){
                int j=0;
                for(;j<len-i-1 && j<i && str[i-j-1]==str[i+j];++j);
                curlen = 2*j+2;
                if(curlen > max){
                    max = curlen;
                    result.clear();
                    for(int k=i-j; k<i-j+curlen-2;k++){
                        result.push_back(str[k]);
                    }
                }
            }
            else if(str[i-1] == str[i+1]){
                int j=1;
                for(;j<len-i-1 && str[i-j]==str[i+j] && j<i;++j);
                curlen = 2*j+2;
                if(curlen > max){
                    max = curlen;
                    result.clear();
                    for(int k=i-j;k<i-j+curlen-1;k++){
                        result.push_back(str[k]);
                    }
                }
            }
        }
        return result;
    }
};

// Longest Palindromic Substring
// 备忘录法，会超时
// 时间复杂度O(n^2)，空间复杂度O(n^2)
namespace std {
    template<>
    struct hash<std::pair<int, int> > {
        size_t operator()(pair<int, int> const& p) const {
            return p.first * 31 + p.second;
        }
    };
}

class Solution_1 {
public:
    std::string longestPalindrome(std::string const& s) {
        cache.clear();
        return cachedLongestPalindrome(s, 0, s.length() - 1);
    }

private:
    std::unordered_map<std::pair<int, int>, std::string> cache;

    std::string longestPalindrome(std::string const& s, int i, int j) {
        const int length = j - i + 1;
        if (length < 2) return s.substr(i, length);

        const std::string& s1 = cachedLongestPalindrome(s, i + 1, j - 1);

        if (s1.length() == length - 2 && s[i + 1] == s[j - 1])
            return s.substr(i, length);

        const std::string& s2 = cachedLongestPalindrome(s, i + 1, j);
        const std::string& s3 = cachedLongestPalindrome(s, i, j - 1);

        // return max(s1, s2, s3)
        if (s1.length() > s2.length()) return s1.length() > s3.length() ? s1 : s3;
        else return s2.length() > s3.length() ? s2 : s3;
    }

    std::string cachedLongestPalindrome(std::string const& s, int i, int j) {
        auto key = std::make_pair(i, j);
        auto pos = cache.find(key);

        if (pos != cache.end()) return pos->second;
        else return cache[key] = longestPalindrome(s, i, j);
    }
};
// Longest Palindromic Substring
// 动规，时间复杂度O(n^2)，空间复杂度O(n^2)
class Solution_2 {
public:
    std::string longestPalindrome(const std::string& s) {
        const int n = s.size();
        bool f[n][n];
        std::fill_n(&f[0][0], n * n, false);
        // 用 vector 会超时
        //vector > f(n, vector(n, false));
        size_t max_len = 1, start = 0;  // 最长回文子串的长度，起点

        for (size_t i = 0; i < s.size(); i++) {
            f[i][i] = true;
            for (size_t j = 0; j < i; j++) {  // [j, i]
                f[j][i] = (s[j] == s[i] && (i - j < 2 || f[j + 1][i - 1]));
                if (f[j][i] && max_len < (i - j + 1)) {
                    max_len = i - j + 1;
                    start = j;
                }
            }
        }
        return s.substr(start, max_len);
    }
};

// Longest Palindromic Substring
// Manacher’s Algorithm
// 时间复杂度O(n)，空间复杂度O(n)
class Solution_3 {
public:
    // Transform S into T.
    // For example, S = "abba", T = "^#a#b#b#a#$".
    // ^ and $ signs are sentinels appended to each end to avoid bounds checking
    std::string preProcess(const std::string& s) {
        int n = s.length();
        if (n == 0) return "^$";

        std::string ret = "^";
        for (int i = 0; i < n; i++) ret += "#" + s.substr(i, 1);

        ret += "#$";
        return ret;
    }

    std::string longestPalindrome(std::string s) {
        std::string T = preProcess(s);
        const int n = T.length();
        // 以T[i]为中心，向左/右扩张的长度，不包含T[i]自己，
        // 因此 P[i]是源字符串中回文串的长度
        int P[n];
        int C = 0, R = 0;

        for (int i = 1; i < n - 1; i++) {
            int i_mirror = 2 * C - i; // equals to i' = C - (i-C)

            P[i] = (R > i) ? std::min(R - i, P[i_mirror]) : 0;

            // Attempt to expand palindrome centered at i
            while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
                P[i]++;

            // If palindrome centered at i expand past R,
            // adjust center based on expanded palindrome.
            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }
        }

        // Find the maximum element in P.
        int max_len = 0;
        int center_index = 0;
        for (int i = 1; i < n - 1; i++) {
            if (P[i] > max_len) {
                max_len = P[i];
                center_index = i;
            }
        }

        return s.substr((center_index - 1 - max_len) / 2, max_len);
    }
};
