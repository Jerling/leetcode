#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

class Solution
{
public:
    int MaxSubArray(const std::vector<int> &nums) {
        int maxsum=*nums.begin(), cursum=*nums.begin();
        auto it=std::next(nums.begin());
        for (; it!=nums.cend(); it++) {
            if (*it > 0) {
                if (cursum>0) {
                    cursum += *it;
                } else {
                    cursum = *it;
                }
            } else {
                if (cursum > -*it) {
                    cursum += *it;
                } else
                    cursum = *it;
            }
            maxsum = std::max(cursum, maxsum);
        }
        return maxsum;
    }
};


// Maximum Subarray
// 时间复杂度O(n)，空间复杂度O(1)
class Solution_1 {
public:
    int maxSubArray(const std::vector<int>& nums) {
        int maxLocal = nums[0];
        int global = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            maxLocal = std::max(nums[i], nums[i] + maxLocal);
            global = std::max(global, maxLocal);
        }
        return global;
    }
};

// Maximum Subarray
// 时间复杂度O(n)，空间复杂度O(n)
class Solution_2 {
public:
    int maxSubArray(std::vector<int>& A) {
        return mcss(A.begin(), A.end());
    }
private:
    // 思路5，求最大连续子序列和
    template <typename Iter>
    static int mcss(Iter begin, Iter end) {
        int result, cur_min;
        const int n = distance(begin, end);
        int *sum = new int[n + 1];  // 前n项和

        sum[0] = 0;
        result = INT_MIN;
        cur_min = sum[0];
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + *(begin  + i - 1);
        }
        for (int i = 1; i <= n; i++) {
            result = std::max(result, sum[i] - cur_min);
            cur_min = std::min(cur_min, sum[i]);
        }
        delete[] sum;
        return result;
    }
};
