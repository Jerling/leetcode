#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

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
    std::vector<int> threeSum(std::vector<int> &nums, const int target=0){
      const int length = nums.size();
      std::vector<int> result;
      if (length < 3) {
        return result;
      }
      sort(nums.begin(), nums.end());
      for (int i = 0; i < length - 2; i++) {
        if (i>0 && nums[i] == nums[i-1]) { // 防止重复
          continue;
        }
        for (int j = length - 1; j > i + 1; j--) {
          auto tmp = find(nums.begin() + i + 1, nums.end(),target - nums[i] - nums[j]) ;
          if (tmp != nums.end() && tmp < nums.begin() + j) {
              result.push_back(nums[i]);
              result.push_back(*tmp);
              result.push_back(nums[j]);
          }
        }
      }
      return result;
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
    std::vector<int> threeSum(std::vector<int> & nums, const int target = 0){
      std::vector<int> result;
      const int length = nums.size();
      if (length < 3) {
        return result;
      }
      sort(nums.begin(), nums.end());
      auto last = nums.end();
      for (auto i = nums.begin(); i < last - 2; i++) {
        auto j = i+1;
        if (i > nums.begin() && *i == *(i-1)) {
          continue;
        }
        auto k = last - 1;
        while (j < k) {
          if (*i + *j + *k < target) { 
            ++j;
            while (*j == *(j-1) && j < k) {
              ++j;  // 去掉重复元素
            }
          }else if(*i + *j + *k > target){
              --k;
              while (*k == *(k+1) && j < k) {
                --k; // 去重
              }
            }else{
                result.push_back(*i);
                result.push_back(*j);
                result.push_back(*k);
                ++j;
                --k;
                while (*j == *(j-1) && *k == *(k+1) && j < k) {
                  ++j; // 去重
                }
            }
        }
      }
      return result;
    }
};

