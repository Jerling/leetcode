# 8. 暴力枚举法
## 8.1 Subsets
描述

Given a set of distinct integers, S, return all possible subsets.

Note:

    Elements in a subset must be in non-descending order.
    The solution set must not contain duplicate subsets.

For example, If S = [1,2,3], a solution is:

``` cpp-objdump
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
```
答案：[C++](code/8.1.hpp) [https://soulmachine.gitbooks.io/algorithm-essentials/content/cpp/brute-force/subsets.html](https://soulmachine.gitbooks.io/algorithm-essentials/content/cpp/brute-force/subsets.html)

## 8.2 Subsets II
描述

Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:

Elements in a subset must be in non-descending order. The solution set must not contain duplicate subsets. For example, If S = [1,2,2], a solution is:

``` cpp-objdump
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
```

分析

这题有重复元素，但本质上，跟上一题很类似，上一题中元素没有重复，相当于每个元素只能选0或1次，这里扩充到了每个元素可以选0到若干次而已。

答案：[C++](code/8.2.hpp)
