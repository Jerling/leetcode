# 6. 排序
## 6.1 插入排序
### 6.1.1. Insertion Sort List
描述

Sort a linked list using insertion sort.

答案：[C++](code/6.1.1.hpp)

## 6.2 归并排序
### 6.2.1 Merge Two Sorted Arrays
描述

Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note: You may assume that A has enough space to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.

题意：将两个有序的数组合并为一个

答案：[C++](code/6.2.1.hpp)

### 6.2.2 Merge Two Sorted Lists
描述

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

题意：将两个有序的列表合并为一个

答案：[C++](code/6.2.2.hpp)

## 6.3 快速排序
### 6.3.1 Sort Colors
描述

Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Follow up:

A rather straight forward solution is a two-pass algorithm using counting sort.

First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?

分析

由于0, 1, 2 非常紧凑，首先想到计数排序(counting sort)，但需要扫描两遍，不符合题目要求。

由于只有三种颜色，可以设置两个index，一个是red的index，一个是blue的index，两边往中间走。时间复杂度O(n)，空间复杂度O(1)。

第3种思路，利用快速排序里 partition 的思想，第一次将数组按0分割，第二次按1分割，排序完毕，可以推广到n种颜色，每种颜色有重复元素的情况。

答案：[C++](code/6.3.1.hpp)
