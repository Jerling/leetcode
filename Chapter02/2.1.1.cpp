#include <iostream>
#include <vector>

int main(void)
{
  std::vector<int> vec = {1,1,2,3,3,3,3,8,8,9,10};
  // std::vector<int> vec = {1,2,3,8,9,10};
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
      i = j-1;                       // 提升性能，使得两个 for 时间复杂度为 O(n)
    }
  }

  for(auto &v : vec)
    std::cout << v << " ";
  return 0;
}
