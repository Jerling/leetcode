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

### 6.3.2 Kth Largest Element in an Array
描述
Find the k-th largest element in an unsorted array.
For example, given [3,2,1,5,6,4] and k = 2, return 5.
Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
分析
- 这题是一道很好的面试题目，
- 题目短小，很快就能说清题意
- 有很多种解法。从简单到复杂的解法都有，梯度均匀。
- 不需要预先知道特殊领域知识。
- 这题有很多思路：
- 按从大到小全排序，然后取第k个元素，时间复杂度O(nlogn)，空间复杂度O(1)
- 利用堆进行部分排序。维护一个大根堆，将数组元素全部压入堆，然后弹出k次，第k个就是答案。时间复杂度O(klogn)，空间复杂度O(n)
- 选择排序，第k次选择后即可得到第k大的数，时间复杂度O(nk)，空间复杂度O(1)
- 堆排序，维护一个k大小的小根堆，将数组中的每个元素与堆顶元素进行比较，如果比堆顶元素大，则删除堆顶元素并添加该元素，如果比堆顶元素小，则什么也不做，继续下一个元素。时间复杂度O(nlogk)，空间复杂度O(k)。
- 利用快速排序中的partition思想，从数组中随机选择一个元素x，把数组划分为前后两部分sa和sb，sa中的元素小于x，sb中的元素大于或等于x。这时有两种情况：
- sa的元素个数小于k，则递归求解sb中的第k-|sa|大的元素
- sa的元素个数大于或等于k，则递归求解sa中的第k大的元素
- 时间复杂度O(n)，空间复杂度O(1)
- 思路4和5比较高效，可以接受，其他思路太慢了，不采纳。

答案：[C++](code/6.3.2.hpp)

## 6.4 桶排序
### 6.4.1 First Missing Positive
描述

Given an unsorted integer array, find the first missing positive integer.

For example, Given [1,2,0] return 3, and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
分析

本质上是桶排序(bucket sort)，每当 A[i]!= i+1 的时候，将A[i]与A[A[i]-1]交换，直到无法交换为止，终止条件是 A[i]== A[A[i]-1]。

答案：[C++](code/6.4.1.hpp)
