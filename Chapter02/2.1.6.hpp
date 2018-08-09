#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

/* 自己的思路：
 * 以空间换时间
 * */
class mySolution{
  public:
    int LongestConsecutiveSequence(const std::vector<int> &S) {
      const int max = *std::max_element(S.begin(), S.end());
      // std::cout << max << std::endl;
      int arr[max+1] = {0};
      for(auto &i : S){
        arr[i] = 1;
        // std::cout << i << std::endl;
      }
      int longest = 0, tmp_max = 0;
      for (int i = 0; i < max+1; i++) {
        // std::cout << i << " " << arr[i] << std::endl;
        if(arr[i] == 1){
          ++tmp_max;
          // std::cout << i <<" "<< arr[i] << " "<< tmp_max << std::endl;
          longest = std::max(longest, tmp_max);
        }else{
          tmp_max = 0;
        }
      }
      return longest;
    }
};


/* 用一个哈希表used来记录每个元素是否使用，对每个元素；
 * 从前从后扩张，直到不连续
 * 代码1
 * T : log(n)，S；1
 * */
class Solution_1{
  public:
    int LongestConsecutiveSequence(const std::vector<int> & nums) {
      std::unordered_map<int, bool> used;
      for(auto i : nums)
        used[i] = false;  // 初始化未使用过
      int longest = 0;
      for(auto i : nums){
        if (used[i]) {   // 已经检查过，直接跳过
          continue;
        }
        int length = 1;
        used[i] = true;
        for (int j = i + 1; used.find(j) != used.end(); j++) { // 向后检查是否连续
          used[j] = true;  // 标记检查过的元素
          ++length;
        }
        for (int j = i - 1; used.find(j) != used.end(); --j) { // 向前检查是否连续
          used[j] = true;
          ++length;
        }
        longest = std::max(longest, length);
      }
      return longest;
    }
};

/* 代码2：
 * */
class Solution_2{
  public:
    int LongestConsecutiveSequence(const std::vector<int> &nums) {
      std::unordered_map<int, int> map;
      int size = nums.size();
      int l = 1;
      for (int i = 0; i < size; i++) {
        if (map.find(nums[i]) != map.end()) continue;
        map[nums[i]] = 1;
        if (map.find(nums[i] - 1) != map.end()) {
          l = std::max(l, mergeCluster(map, nums[i] - 1, nums[i]));
        }
        if (map.find(nums[i] + 1) != map.end()) {
        l = std::max(l, mergeCluster(map, nums[i], nums[i] + 1));
        }
      }
      return size == 0 ? 0 : l;
    }
  private:
    int mergeCluster(std::unordered_map<int, int> &map, int left, int right) {
      int upper = right + map[right] - 1;
      int lower = left - map[left] + 1;
      int length = upper - lower + 1;
      map[upper] = length;
      map[lower] = length;
      return length;
    }
};
