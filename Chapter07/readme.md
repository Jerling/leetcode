# 7. 查找
## 7.1 Search for a Range
描述
Given a sorted array of integers, find the starting and ending position of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].
For example, Given [5, 7, 7, 8, 8, 10] and target value 8, return [3, 4].

答案：[C++](code/7.1.hpp)

## 7.2 Search Insert Position
描述

Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.

[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0

答案：[C++](code/7.2.hpp)

## 7.3 Search in Rotated Sorted Array
描述

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

答案：[C++](code/7.3.hpp)

## 7.4 Search in Rotated Sorted Array II
描述

Follow up for "Search in Rotated Sorted Array": What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
分析

允许重复元素，则上一题中如果A[left] <= A[mid],那么[left,mid]为递增序列的假设就不能成立了，比如[1,3,1,1,1]。

既然A[left] <= A[mid]不能确定递增，那就把它拆分成两个条件：

    若A[left] < A[mid]，则区间[left,mid]一定递增
    若A[left] == A[mid] 确定不了，那就left++，往下看一步即可。

答案：[C++](code/7.4.hpp)

## 7.5 Search a 2D Matrix
描述

Write an efficient algorithm that searches for a value in an m × n matrix. This matrix has the following properties:

    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row.

For example, Consider the following matrix:

``` cpp-objdump
[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
```

Given target = 3, return true.

答案：[C++](code/7.5.hpp)

## 7.6. Search a 2D Matrix II
描述

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

    Integers in each row are sorted in ascending from left to right.
    Integers in each column are sorted in ascending from top to bottom.

For example,

Consider the following matrix:

``` cpp-objdump
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
```

Given target = 5, return true.

Given target = 20, return false.

分析

从右上角开始, 比较target 和 matrix[i][j]的值。如果小于target, 则该行不可能有此数, 所以i++; 如果大于target, 则该列不可能有此数, 所以j--。遇到边界则表明该矩阵不含target.

答案：[C++](code/7.6.hpp)

## 7.7 Find Minimum in Rotated Sorted Array
描述

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
分析

从左向右扫描，扫描到的第一个逆序的位置，肯定是原始数组中第一个元素，时间复杂度O(n)。

不过本题依旧可以用二分查找，最关键的是要判断那个“断层”是在左边还是右边。

- 若A[mid] < A[right]，则区间[mid,right]一定递增，断层一定在左边
- 若A[mid] > A[right]，则区间[left,mid]一定递增，断层一定在右边
- nums[mid] == nums[right]，这种情况不可能发生，因为数组是严格单调递增的，不存在重复元素

答案：[C++](code/7.7.hpp)

Median of Two Sorted Arrays
描述

There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
分析

这是一道非常经典的题。这题更通用的形式是，给定两个已经排序好的数组，找到两者所有元素中第k大的元素。

O(m+n)的解法比较直观，直接merge两个数组，然后求第k大的元素。

不过我们仅仅需要第k大的元素，是不需要“排序”这么昂贵的操作的。可以用一个计数器，记录当前已经找到第m大的元素了。同时我们使用两个指针pA和pB，分别指向A和B数组的第一个元素，使用类似于merge sort的原理，如果数组A当前元素小，那么pA++，同时m++；如果数组B当前元素小，那么pB++，同时m++。最终当m等于k的时候，就得到了我们的答案，O(k)时间，O(1)空间。但是，当k很接近m+n的时候，这个方法还是O(m+n)的。

有没有更好的方案呢？我们可以考虑从k入手。如果我们每次都能够删除一个一定在第k大元素之前的元素，那么我们需要进行k次。但是如果每次我们都删除一半呢？由于A和B都是有序的，我们应该充分利用这里面的信息，类似于二分查找，也是充分利用了“有序”。

假设A和B的元素个数都大于k/2，我们将A的第k/2个元素（即A[k/2-1]）和B的第k/2个元素（即B[k/2-1]）进行比较，有以下三种情况（为了简化这里先假设k为偶数，所得到的结论对于k是奇数也是成立的）：

``` cpp-objdump
A[k/2-1] == B[k/2-1]
A[k/2-1] > B[k/2-1]
A[k/2-1] < B[k/2-1]
```

如果A[k/2-1] < B[k/2-1]，意味着A[0]到A[k/2-1]的肯定在A∪BA \cup BA∪B的top k元素的范围内，换句话说，A[k/2-1]不可能大于A∪BA \cup BA∪B的第k大元素。留给读者证明。

因此，我们可以放心的删除A数组的这k/2个元素。同理，当A[k/2-1] > B[k/2-1]时，可以删除B数组的k/2个元素。

当A[k/2-1] == B[k/2-1]时，说明找到了第k大的元素，直接返回A[k/2-1]或B[k/2-1]即可。

因此，我们可以写一个递归函数。那么函数什么时候应该终止呢？

- 当A或B是空时，直接返回B[k-1]或A[k-1]；
- 当k=1是，返回min(A[0], B[0])；
- 当A[k/2-1] == B[k/2-1]时，返回A[k/2-1]或B[k/2-1]

答案：[C++](code/7.8.hpp)
