#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
// Longest Increasing Subsequence
// 时间复杂度O(nlogn)，空间复杂度O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        // f[i]表示以i结尾的最长递增子序列的长度
        vector<int> f(nums.size(), 1);
        int global = 1;
        for (size_t j = 1; j < nums.size(); ++j) {
            for (size_t i = 0; i < j; ++i) {
                if (nums[i] < nums[j]) {
                    f[j] = max(f[j], f[i] + 1);
                }
            }
            global = max(global, f[j]);
        }
        return global;
    }
};
// Longest Increasing Subsequence
// 时间复杂度O(nlogn)，空间复杂度O(n)
class Solution_2 {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        for (auto x : nums) {
            size_t insertPos = lower_bound(lis, 0, lis.size(), x);
            if (insertPos >= lis.size()) {
                lis.push_back(x);
            } else {
                lis[insertPos] = x;
            }
        }
        return lis.size();
    }
    int lower_bound (const vector<int>& A, int first, int last, int target) {
        while (first != last) {
            int mid = first + (last - first) / 2;
            if (target > A[mid]) first = ++mid;
            else                 last = mid;
        }

        return first;
    }
};
