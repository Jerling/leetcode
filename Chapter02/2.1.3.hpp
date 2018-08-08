#include <vector>
#include <algorithm>

/* 自己实现的方法有点臃肿，不适用，留着纪念吧。。。
 * */
class mySolution{
  public:
    int serchInRSA(const std::vector<int> &rsa, int target) {
      // rsa使用引用避免复制开销
      if (!rsa.size()) {
        return -1;
      }
      const int len = rsa.size();
      if (len == 1) {
        if (rsa[0] == target) {
          return 0;
        } else {
          return -1;
        }  
      }
      // auto mid = std::distance(rsa.begin(),lower_bound(rsa.begin(), rsa.end(), rsa[0]));
      // 经测试lower_bound功能与upper_bound功能类似，只是将 > 改为 >=。所以不适用，并不是
      // 猜测的找到比起始值小的迭代器
      int i = len-1;
      for (; i > 0 ; --i) { // 将旋转数组分开
        if(rsa[i] > rsa[0])
          break;
      }
      auto a = binarySearch(rsa, 0, i, target);
      auto b = binarySearch(rsa, i+1, len-1, target);
      if (a != -1) {
        return a;
      }else if(b != -1){
        return b;
      }
      return -1;
    }

    int binarySearch(auto rsa, int first, int last, const int target){
      int mid;
      do{
        mid = (first + last) / 2;
        // (first + last)/2 = first + (last-first)/2
        if (rsa[mid] == target) {
          return mid; 
        }else if(rsa[mid] > rsa[first]){
          first = mid;
        }else{
          last = mid;
        }
      }while(first != last);

      return -1;
    }
};

/* 分析：二分查找，难度在于边界的确定
 * */

/* 代码1
 * T : logn，S；1
 * */
class Solution_1{
  public:
    int serchInRSA(const std::vector<int> &rsa, int target) {
      int first=0, last=rsa.size();
      while (first != last) {
        const int mid = first + (last - first)/2;
        if (rsa[mid] == target) {
          return mid;
        }
        if (rsa[first] <= rsa[mid]) {
          if(rsa[first] <= target && target < rsa[mid]){
            last = mid;
          }else{
            first = mid + 1;
          }
        }else{
          if (rsa[mid] < target && target <= rsa[last-1]) {
            first = mid + 1;
          }else{
            last = mid;
          }
        }
      }
      return -1;
    }
};
