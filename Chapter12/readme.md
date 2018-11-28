# 动态规划算法 #

## Triangle ##

描述
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

``` cpp-objdump
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
```

The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
Note: Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
分析
设状态为f(i, j)，表示从从位置(i,j)出发，路径的最小和，则状态转移方程为
$$ f(i,j)=\min\left\{f(i+1,j),f(i+1,j+1)\right\}+(i,j) f(i,j)=min{f(i+1,j),f(i+1,j+1)}+(i,j) $$

答案: [C++](code/13.1.hpp)

## Maximum Subarray ##

描述
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
For example, given the array `[−2,1,−3,4,−1,2,1,−5,4]`, the contiguous subarray `[4,−1,2,1]` has the largest `sum = 6`
分析
最大连续子序列和，非常经典的题。

当我们从头到尾遍历这个数组的时候，对于数组里的一个整数，它有几种选择呢？它只有两种选择： 1、加入之前的SubArray；2. 自己另起一个SubArray。那什么时候会出现这两种情况呢？
如果之前SubArray的总体和大于0的话，我们认为其对后续结果是有贡献的。这种情况下我们选择加入之前的SubArray
如果之前SubArray的总体和为0或者小于0的话，我们认为其对后续结果是没有贡献，甚至是有害的（小于0时）。这种情况下我们选择以这个数字开始，另起一个SubArray。
设状态为f[j]，表示以S[j]结尾的最大连续子序列和，则状态转移方程如下：
$$ 
f[j] = \max\left\{f[j-1]+S[j],S[j]\right\}, 1 \leq j \leq nf[j]=max{f[j−1]+S[j],S[j]},1≤j≤n
target = \max\left\{f[j]\right\}, 1 \leq j \leq ntarget=max{f[j]},1≤j≤n
$$
解释如下：
- 情况一，S[j]不独立，与前面的某些数组成一个连续子序列，则最大连续子序列和为f[j-1]+S[j]。
- 情况二，S[j]独立划分成为一段，即连续子序列仅包含一个数S[j]，则最大连续子序列和为S[j]。
其他思路：
- 思路2：直接在i到j之间暴力枚举，复杂度是O(n^3)
- 思路3：处理后枚举，连续子序列的和等于两个前缀和之差，复杂度O(n^2)。
- 思路4：分治法，把序列分为两段，分别求最大连续子序列和，然后归并，复杂度O(nlog n)
- 思路5：把思路2O(n^2)的代码稍作处理，得到O(n)的算法
- 思路6：当成M=1的最大M子段和

答案： [C++](code/13.2.hpp)

## Maximum Product Subarray ##
描述
Find the contiguous subarray within an array (containing at least one number) which has
the largest product.
For example, given the array [2,3,-2,4], the contiguous subarray [2,3] has the largest
product = 6.
分析
这题跟“最大连续子序列和”非常类似，只不过变成了“最大连续子序列积”，所以解决思路也很类似。
仅仅有一个小细节需要注意，就是负负得正，两个负数的乘积是正数，因此我们不仅要跟踪最大值，还要跟踪最小值。

答案： [C++](code/13.3.hpp)

## Logest Increaing Subsequence ##

描述
Given an unsorted array of integers, find the length of longest increasing subsequence.
For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. 
Note that there may be more than one LIS combination, it is only necessary for you to
return the length.
Your algorithm should run in O(n^2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?

答案： [C++](code/13.4.hpp) [https://soulmachine.gitbooks.io/algorithm-essentials/content/cpp/dp/longest-increasing-subsequence.html](https://soulmachine.gitbooks.io/algorithm-essentials/content/cpp/dp/longest-increasing-subsequence.html)


## Palindrome Partitioning II ##

描述
Given a string s, partition s such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.
For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
答案：[https://soulmachine.gitbooks.io/algorithm-essentials/content/cpp/dp/palindrome-partitioning-ii.html](https://soulmachine.gitbooks.io/algorithm-essentials/content/cpp/dp/palindrome-partitioning-ii.html)
