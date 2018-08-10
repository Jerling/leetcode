#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <limits.h>

/* 自己的思路：
 * 找每个值后面是否存在 targe-nums[i] 这个值
 * 理论上时间复杂度为n^2, 空间复杂度 1
 * 因为find的原型是一个个找，并不是二分查找：
 * template<class InputIterator, class T>
 *  InputIterator find (InputIterator first, InputIterator last, const T& val)
 * {
 *    while (first!=last) {
 *      if (*first==val) return first;
 *        ++first;
 *   }
 *   return last;
 * }
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


/* 用一个哈希表mapping来记录每个元素对应的下标；
 * unordered_map对应哈希表，查找时间复杂度为 1
 * map 对应红黑树，查找时间复杂度为 log(n)
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
      auto b = next(a);
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

