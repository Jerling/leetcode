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
