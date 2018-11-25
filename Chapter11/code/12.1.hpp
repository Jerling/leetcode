#include <iostream>
#include <vector>
#include <algorithm>

// 自己实现的思路，应该是错误的,只是凑巧题目的测试通过了
// 待测试
class Solution_1 {
public:
    int jump(const std::vector<int>& nums) {
        int reach = 1; // 最右能跳到哪里
        int i;
        for (i = 0; i < reach && reach < nums.size(); ++i)
            reach = std::max(reach,  i + 1 + nums[i]);
        return reach < nums.size()?-1:i;
    }
};
// LeetCode, Jump Game II
// 时间复杂度O(n)，空间复杂度O(1)
class Solution_2 {
public:
    int jump(const std::vector<int>& nums) {
        int step = 0; // 最小步数
        int left = 0;
        int right = 0;  // [left, right]是当前能覆盖的区间
        if (nums.size() == 1) return 0;

        while (left <= right) { // 尝试从每一层跳最远
            ++step;
            const int old_right = right;
            for (int i = left; i <= old_right; ++i) {
                int new_right = i + nums[i];
                if (new_right >= nums.size() - 1) return step;

                if (new_right > right) right = new_right;
            }
            left = old_right + 1;
        }
        return 0;
    }
};

// LeetCode, Jump Game II
// 时间复杂度O(n)，空间复杂度O(1)
class Solution_3 {
public:
    int jump(const std::vector<int>& nums) {
        int result = 0;
        // the maximum distance that has been reached
        int last = 0;
        // the maximum distance that can be reached by using "ret+1" steps
        int cur = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > last) {
                last = cur;
                ++result;
            }
            cur = std::max(cur, i + nums[i]);
        }

        return result;
    }
};
