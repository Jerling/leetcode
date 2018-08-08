#include <vector>
#include <algorithm>

// 自己实现的
// 时间复杂度 n^2, 空间复杂度 1
class mySolution {
  public:
    int removeDuplicates(std::vector<int> & vec){
      int i,j;
      int length = vec.size();
      for (i = 0; i < length; i++) {
        for (j = i+1; j < length; j++) {
          if (vec[i] != vec[j]) {        // 不重复往前走
            break;
          }
        }
        if (i + 1 < j){                  // 有重复才删除
          vec.erase(vec.begin() + i + 1, // +1 保留至少一个，
              vec.begin() + j);          // 删除重复序列
          length = vec.size();
        }
      }
      return vec.size();
    }
};

// 代码1
// 时间复杂度 n , 空间复杂度 1
class Solution_1{
  public:
    int removeDuplicates(std::vector<int>& nums){
      if (nums.empty()) {
        return 0;
      }
      int index = 0;
      int length = nums.size();
      for (int i = 1; i < length; i++) {
        if (nums[index] != nums[i]) {
          nums[++index] = nums[i];
        }
      }
      return index + 1;
    }
};

// 代码2
// 使用STL: unique() 是algorithm 中的函数，去除容器中的重复元素并返回最后的迭代器 .end();
// distanse(): 返回两个迭代器之间的距离（元素个数）
// T : n，S ：1
class Solution_2{
  public:
    int removeDuplicates(std::vector<int>& nums){
      return std::distance(nums.begin(), std::unique(nums.begin(), nums.end()));
    }
};

// 代码3
// 使用STL: upper_bound(first, last, val) 返回在first和last中第一个大于val的迭代器
// 因为题目说是有序数组，否则先排序，再用upper_bound()
// T : n, S : 1
class Solution_3{
  public:
    int removeDuplicates(std::vector<int> & nums)
    {
      // std::sort(nums.begin(), nums.end());  // 无序时使用
      return std::distance(nums.begin(), removeDuplicates(nums.begin(), nums.end(), nums.begin()));
    }

    template<typename InIt, typename OutIt> 
    OutIt removeDuplicates(InIt first, InIt last, OutIt output){
      while (first != last) {
        *output++ = *first;
        first = upper_bound(first, last, *first);
      }
      return output;
    }
};
