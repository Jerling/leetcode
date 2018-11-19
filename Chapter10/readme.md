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

