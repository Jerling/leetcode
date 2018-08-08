#include <vector>
#include <algorithm>

class mySolution{
  public:
    int removeDuplicates_2(std::vector<int> nums) {
      return std::distance(nums.begin(),
          removeDuplicates_2(nums.begin(), nums.end(), nums.begin()));
    }
    template<typename InIt, typename OutIt> 
    OutIt removeDuplicates_2(InIt first, InIt last, OutIt output) {
      while (first != last) {
        *output++ = *first;
        first = upper_bound(first, last, *first);
        if (std::distance(output, first) > 2) {
          *output++ = *(first -1);
        }
      }
      return output;
    }
};

/* 分析：加入变量记录出现的次数，排好序的数组所以只要一个变量
 * 否则引入 hashmap 来记录出现的次数
 * */

/* 代码1
 * T : n，S；1
 * @author hex108 (https://github.com/hex108)
 * */
class Solution_1{
  public:
    int removeDuplicates_2(std::vector<int> nums, int occur = 2) {
      if (nums.size() <= 2) {
        return nums.size();
      }
      int index = 2;
      for (int i = 2; i < int(nums.size()); i++) {
        if (nums[i] != nums[index - occur]) {
          nums[index++] = nums[i];
        }
      }
      return index;
    }
};

/* 代码2
 * 代码2简洁一些，但是代码1扩展性好些，把occur < 2 改为 occur < 3就可以
 * 实现最多重复三次了。
 * T: n , S: 1
 * */
class Solution_2 {
  public:
    int removeDuplicates_2(std::vector<int> nums) {
      const int n = nums.size();
      int index = 0;
      for (int i = 0; i < n; i++) {
        if(i>0 && i < n-1 && nums[i] == nums[i-1] && nums[i] == nums[i+1])
          continue;
        nums[index++] = nums[i];
      }
      return index;
    }
};
