# 深度优先搜索 #

## Palindrome Partitioning ##

描述

Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab", Return

``` cpp-objdump
  [
    ["aa","b"],
    ["a","a","b"]
  ]
```

分析

在每一步都可以判断中间结果是否为合法结果，用回溯法。

一个长度为n的字符串，有n-1个地方可以砍断，每个地方可断可不断，因此复杂度为O(2n−1)O(2^{n-1})O(2​n−1​​)

答案: [c++](code/10.1.hpp)  [https://soulmachine.gitbooks.io/algorithm-essentials/content/cpp/dfs/palindrome-partitioning.html](https://soulmachine.gitbooks.io/algorithm-essentials/content/cpp/dfs/palindrome-partitioning.html)
## Unique Paths ##

描述

A robot is located at the top-left corner of a m × n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

答案：[C++](code/10.2.hpp)  [https://soulmachine.gitbooks.io/algorithm-essentials/content/cpp/dfs/unique-paths.html](https://soulmachine.gitbooks.io/algorithm-essentials/content/cpp/dfs/unique-paths.html)
