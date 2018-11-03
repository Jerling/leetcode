#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

// Letter Combinations of a Phone Number
// 时间复杂度O(3^n)，空间复杂度O(n)
class Solution_1 {
public:
    const vector<string> keyboard { " ", "", "abc", "def", // '0','1','2',...
            "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

    vector<string> letterCombinations (const string &digits) {
        vector<string> result;
        if (digits.empty()) return result;
        dfs(digits, 0, "", result);
        return result;
    }

    void dfs(const string &digits, size_t cur, string path,
             vector<string> &result) {
        if (cur == digits.size()) {
            result.push_back(path);
            return;
        }
        for (auto c : keyboard[digits[cur] - '0']) {
            dfs(digits, cur + 1, path + c, result);
        }
    }
};


// Letter Combinations of a Phone Number
// 时间复杂度O(3^n)，空间复杂度O(1)
class Solution_2 {
public:
    const vector<string> keyboard { " ", "", "abc", "def", // '0','1','2',...
            "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

    vector<string> letterCombinations (const string &digits) {
        if (digits.empty()) return vector<string>();
        vector<string> result(1, "");
        for (auto d : digits) {
            const size_t n = result.size();
            const size_t m = keyboard[d - '0'].size();

            // resize to n * m
            for (size_t i = 1; i < m; ++i) {
                for (size_t j = 0; j < n; ++j) {
                    result.push_back(result[j]);
                }
            }

            for (size_t i = 0; i < result.size(); ++i) {
                result[i] = result[i] + keyboard[d - '0'][i/n];
            }
        }
        return result;
    }
};
