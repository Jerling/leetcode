#include <vector>
#include <algorithm>

/* 自己的思路：
 * 1. 分别求a1,a2的中位数m1,m2，如果相等即为所求
 * 2. 若m1 > m2,则求解a1在[0,m/2]中的中位数m1,以及a2在[n/2,n]中的中位数m2
 * 3. 是否满足1. 或者有一个数组只剩一个元素时，求解比较简单了
 * */
class mySolution{
  int Findmedian(const std::vector<int> nums1, const std::vector<int> nums2){
    int l1start = 0, l2start = 0;
    int l1end = nums1.size(), l2end = nums2.size();
    int mid1, mid2;
    do{
      mid1 = (l1end-l1start)%2 == 0 ? (l1start + l1end)/2 - 1 : (l1start + l1end - 1)/2;
      mid2 = (l2end-l2start)%2 == 0 ? (l2start + l2end)/2 - 1 : (l2start + l2end - 1)/2;
      if (nums1[mid1] == nums2[mid2]) {
        return nums1[mid1];
      }
    }while(mid1 != -1 && mid2 != -1);
    if (mid1 == -1) {
      mid2 = (l2end-l2start)%2 == 0 ? (l2start + l2end)/2 - 1 : (l2start + l2end - 1)/2;
    }
  }
};

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
