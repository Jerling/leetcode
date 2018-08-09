#include <vector>
#include <algorithm>

/* 自己的思路：
 * 1. 分别求a1,a2的中位数m1,m2，如果相等即为所求
 * 2. 若m1 > m2,则求解a1在[0,m/2]中的中位数m1,以及a2在[n/2,n]中的中位数m2
 * 3. 是否满足1. 或者有一个数组只剩一个元素时，求解比较简单了
 * */
class mySolution{
  public:
  int Findmedian(const std::vector<int>& nums1, const std::vector<int>& nums2){
    int l1start = 0, l2start = 0;
    int l1end = nums1.size() - 1, l2end = nums2.size() - 1;
    int mid1 = (l1end-l1start)%2 == 0 ? (l1start + l1end)/2 : (l1start + l1end - 1)/2;
    int mid2 = (l2end-l2start)%2 == 0 ? (l2start + l2end)/2 : (l2start + l2end - 1)/2;
    while(l1start < l1end && l2start < l2end){
      if (nums1[mid1] == nums2[mid2]) {
        return nums1[mid1];
      }
      if (nums1[mid1] < nums2[mid2]) {
        l1start = mid1 + 1;
      }else{
        l2start = mid2 + 1;
      }
      mid1 = (l1end-l1start)%2 == 0 ? (l1start + l1end)/2 : (l1start + l1end - 1)/2;
      mid2 = (l2end-l2start)%2 == 0 ? (l2start + l2end)/2 : (l2start + l2end - 1)/2;
    } // while

    if (l1start >= l1end) {
      if (l2start >= l2end) {
        return nums1[l1start] > nums2[l2start] ? nums2[l2start]: nums1[l1start] ; // 返回较小者
      }
      mid2 = (l2end-l2start)%2 == 0 ? (l2start + l2end)/2 : (l2start + l2end - 1)/2;
      return nums2[mid2] > nums1[l1start] ? nums2[mid2] : (nums2[mid2+1] < nums1[l1start] ? nums2[mid2 + 1] : nums1[l1start]);
    }
  
    mid1 = (l1end-l1start)%2 == 0 ? (l1start + l1end)/2  : (l1start + l1end - 1)/2;
    return nums1[mid1] > nums2[l2start] ? nums1[mid1] : (nums1[mid1+1] < nums2[l2start] ? nums1[mid1 + 1] : nums2[l2start]);
  }
};


/* 代码1
 * T : log(m+n)，S；1
 * */
class Solution_1{
  public:
    double Findmedian(const std::vector<int> &A, const std::vector<int> &B){
      const int m = A.size(), n = B.size();
      int total = m + n;
      if (total & 0x1) {
        return find_kth(A.begin(), m, B.begin(), n, total/2 +1);
      }else{
        return (find_kth(A.begin(), m, B.begin(), n, total/2)
            + find_kth(A.begin(), m, B.begin(), n, total/2 + 1))/2.0;
      }
    }

  private:
    static int find_kth(std::vector<int>::const_iterator A, int m,
        std::vector<int>::const_iterator B, int n, int k){
      if (m > n) { // 确保 m <= n
        return find_kth(B,n,A,m,k);
      }
      if (m==0) {
        return *(B+k-1);
      }
      if (k==1) {
        return std::min(*A, *B);
      }

      int ia = std::min(k/2, m), ib = k - ia; // 划分为两部分，判断 k/2 在那个区间，如>m，则中位数一定在A数组里。
      if (*(A + ia -1) < *(B +ib -1)) {
        return find_kth(A + ia, m-ia, B, n, k-ia);  // 截断A前ia(k/2)个小的
      }else if(*(A + ia -1) > *(B + ib -1)){
        return find_kth(A, m, B + ib, n-ib, k-ib);  // 截断B前id个小的
      }else{
        return A[ia-1];
      }
    }
};
