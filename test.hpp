#include <iostream>
#include <algorithm>
#include <vector>

// First Missing Positive
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        bucket_sort(nums);

        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] != (i + 1))
                return i + 1;
        return nums.size() + 1;
    }
private:
    static void bucket_sort(std::vector<int>& A) {
        const int n = A.size();
        for (int i = 0; i < n; i++) {
            while (A[i] != i + 1) {
                if (A[i] <= 0 || A[i] > n || A[i] == A[A[i] - 1])
                    break;
                std::swap(A[i], A[A[i] - 1]);
            }
        }
    }
};
