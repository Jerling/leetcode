#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

// maximum-product-subarray
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    int maxProduct(std::vector<int> & nums) {
        int maxLocal = nums[0];
        int minLocal = nums[0];
        int global = nums[0];

        for(size_t i = 1; i < nums.size(); i++){
            int temp = maxLocal;
            maxLocal = std::max(std::max(nums[i] * maxLocal, nums[i]), nums[i] * minLocal);
            minLocal = std::min(std::min(nums[i] * temp, nums[i]), nums[i] * minLocal);
            global = std::max(global, maxLocal);
        }
        return global;
    }
};
