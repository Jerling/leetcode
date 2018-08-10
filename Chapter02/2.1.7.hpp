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
    std::vector<int> twoSum(const std::vector<int> &nums, const int target){
      const int length = nums.size();
      std::vector<int> result;
      for (int i = 0; i < length; i++) {
        auto tmp = find(nums.begin() + i, nums.end(),target - nums[i]) ;
        if (tmp != nums.end()) {
            // std::cout << *tmp << std::endl;
            const int dist = std::distance(nums.begin(), tmp);
            result.push_back(i+1);
            result.push_back(dist+1);
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
    std::vector<int> twoSum(const std::vector<int> & nums, const int target){
      std::unordered_map<int, int> mapping;
      std::vector<int> result;
      const int length = nums.size();
      for (int i = 0; i < length; i++) {
        mapping[nums[i]] = i;         // 存贮值即下标
      }
      for (int j = 0; j < length; j++) {
        const int gap = target - nums[j];
        if (mapping.find(gap) != mapping.end() && mapping[gap] > j) { // 后面的条件防止重复
          result.push_back(j+1);
          result.push_back(mapping[gap] + 1);
        }
      }
      return result;
    }
};

