# 贪心算法
## 1. Jump Game
```latex
描述
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:

A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.


分析
由于每层最多可以跳\fn{A[i]}步，也可以跳0或1步，因此如果能到达最高层，则说明每一层都可以到达。有了这个条件，说明可以用贪心法。

思路一：正向，从0出发，一层一层网上跳，看最后能不能超过最高层，能超过，说明能到达，否则不能到达。

思路二：逆向，从最高层下楼梯，一层一层下降，看最后能不能下降到第0层。

思路三：如果不敢用贪心，可以用动规，设状态为\fn{f[i]}，表示从第0层出发，走到\fn{A[i]}时剩余的最大步数，则状态转移方程为：
$$
f[i] = max(f[i-1], A[i-1])-1, i > 0
$$
```
答案: [C++](code/1.hpp)

## Jump Game 2
```latex
描述
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array \code{A = [2,3,1,1,4]}

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)


分析
贪心法。
```
答案：[C++](code/12.1.hpp)

## Best Time to Buy and Sell Stock
描述    
Say you have an array for which the i-th element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), 
design an algorithm to find the maximum profit.
分析   
贪心法，分别找到价格最低和最高的一天，低进高出，注意最低的一天要在最高的一天之前。
把原始价格序列变成差分序列，本题也可以做是最大m子段和，m=1。

答案：[C++](code/12.3.hpp)

## Best Time Buy and Sell Stock II ##
描述   
Say you have an array for which the i-th element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
分析
贪心法，低进高出，把所有正的价格差价相加起来。
把原始价格序列变成差分序列，本题也可以做是最大m子段和，m=数组长度。

答案：[C++](code/12.4.hpp)


## Longest Substring Without Repeating Characters ##

描述
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
分析
假设子串里含有重复字符，则父串一定含有重复字符，单个子问题就可以决定父问题，因此可以用贪心法。跟动规不同，动规里，单个子问题只能影响父问题，不足以决定父问题。

从左往右扫描，当遇到重复字母时，以上一个重复字母的index+1，作为新的搜索起始位置，直到最后一个字母，复杂度是O(n)。如下图所示。

答案：[C++](code/12.5.hpp)
