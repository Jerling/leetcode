#include <iostream>
#include <vector>
#include <algorithm>

// LeetCode, Jump Game
// 思路1，时间复杂度O(n)，空间复杂度O(1)
class Solution_1 {
public:
    bool canJump(const std::vector<int>& nums) {
        int reach = 1; // 最右能跳到哪里
        for (int i = 0; i < reach && reach < nums.size(); ++i)
            reach = std::max(reach,  i + 1 + nums[i]);
        return reach >= nums.size();
    }
};

class Solution_2 {
public:
    bool canJump (const std::vector<int>& nums) {
        if (nums.empty()) return true;
        // 逆向下楼梯，最左能下降到第几层
        int left_most = nums.size() - 1;

        for (int i = nums.size() - 2; i >= 0; --i)
            if (i + nums[i] >= left_most)
                left_most = i;

        return left_most == 0;
    }
};
