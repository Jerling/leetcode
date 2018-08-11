#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

/* 自己的思路：
 * 左右夹逼
 * 最接近的初始化为前三个之和与tartget的绝对值
 * T:n^2 S:1
 * */
class mySolution{
  public:
    int threeSumClosest(std::vector<int> &nums, const int target=0){
      const int length = nums.size();
      if (length < 3) {
        return std::accumulate(nums.begin(), nums.end(),0);
      }
      sort(nums.begin(), nums.end());
      int closest = std::abs(std::accumulate(nums.begin(), nums.begin() + 3, 0));
      // std::cout << closest << std::endl;
      for (int i = 0; i < length - 2; i++) {
        int j = i+1;
        int k = length-1;
        while (j<k) {
          if(std::abs(nums[i] + nums[j] + nums[k] - target) < closest){
            closest = std::abs(nums[i] + nums[j] + nums[k] - target);
            ++j;
            while(nums[j] == nums[j-1] && j<k) ++j;
          }else{
            --k;
            while (nums[k] == nums[k-1] && j<k) {
              --k;
            }
          }
        }
      }
      return closest;
    }
};


/* 解法本质和自己的思路一致
 * 代码简洁性值得参考
 * 代码1
 * T : n，S；1
 * */
class Solution_1{
  public:
    int threeSumClosest(std::vector<int>& nums, int target=0) {
      int result = 0;
      int min_gap = INT_MAX;
      sort(nums.begin(), nums.end());
      for (auto a = nums.begin(); a != prev(nums.end(), 2); ++a) {
        // prev 函数返回args[0]之前的args[1]个迭代器，args[1] 默认为 1;
      auto b = next(a);  // 功能和prev相反, advance(&it, int num) 前进num个位置,无返回值
      auto c = prev(nums.end());
      while (b < c) {
      const int sum = *a + *b + *c;
      const int gap = abs(sum - target);
      if (gap < min_gap) {
        result = sum;
        min_gap = gap;
      }
      if (sum < target) ++b;
      else --c;
      }
    }
    return result;
  }
};

