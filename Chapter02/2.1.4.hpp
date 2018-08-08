#include <vector>
#include <algorithm>

/* 分析：允许重复元素，则A[m] >= A[l], 那么[l,m]为增序列的假设就不成立了，
 * 比如[1,3,1,1,1]。如果A[m]>A[l]不能确定递增，就拆开
 * 1. 若A[m]>[l],则区间[l,m]一定递增
 * 2. 若a[m] == A[1] 无法确定，则 l++，往下一步看看。
 * */

/* 代码1
 * T : n，S；1
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
        if (rsa[first] < rsa[mid]) {
          if(rsa[first] <= target && target < rsa[mid]){
            last = mid;
          }else{
            first = mid + 1;
          }
        }else if(rsa[mid] < rsa[first]){
          if (rsa[mid] < target && target <= rsa[last-1]) {
            first = mid + 1;
          }else{
            last = mid;
          }
        }else{
          first++; // 跳过重复的部分
        }
      }
      return -1;
    }
};
