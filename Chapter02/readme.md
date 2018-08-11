# 2. 线性表
主要内容：数组、单链表、双向链表
## 2.1. 数组
### 2.1.1. Remove Duplicates from Sorted Array
```
描述：
    Given a sorted array, remove the duplicates in place such that each element appear only once
and return the new length.
    Do not allocate extra space for another array, you must do this in place with constant memory.
    For example, Given input array A = [1,1,2],
    Your function should return length = 2, and A is now [1,2].
```
[点击查看答案](./2.1.1.hpp)

### 2.1.2. Remove Duplicates from Sorted Array II
```
描述：
Follow up for ”Remove Duplicates”: What if duplicates are allowed at most twice?
For example, Given sorted array A = [1,1,1,2,2,3],
Your function should return length = 5, and A is now [1,1,2,2,3]
```
[点击查看答案](./2.1.2.hpp)

### 2.1.3 Search in Rotated Sorted Array
```
描述：
Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
You are given a target value to search. If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.
```
[点击查看答案](./2.1.3.hpp)

### 2.1.4 Search in Rotated Sorted Array II
```
描述：
Follow up for ”Search in Rotated Sorted Array”: What if duplicates are allowed?
Would this affect the run-time complexity? How and why?
Write a function to determine if a given target is in the array.
```
[点击查看答案](./2.1.4.hpp)

### 2.1.5 Median of Two Sorted Arrays
```
描述：
There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted
arrays. The overall run time complexity should be O(log(m + n)).
```
[点击查看答案](./2.1.5.hpp)

### 2.1.6 Longest Consecutive Sequence
```
描述：
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
For example, Given [100, 4, 200, 1, 3, 2], The longest consecutive elements sequence is [1,
2, 3, 4]. Return its length: 4.
```
[点击查看答案](./2.1.6.hpp)

### 2.1.7 Two sum
```
描述：
Given an array of integers, find two numbers such that they add up to a specific target number.
The function twoSum should return indices of the two numbers such that they add up to the target, where
index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not
zero-based.
You may assume that each input would have exactly one solution.
Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
```
[点击查看答案](./2.1.7.hpp)

### 2.1.8 3Sum
```
描述：
Given an array S of n integers, are there elements a; b; c in S such that a + b + c = 0? Find all unique
triplets in the array which gives the sum of zero.
Note:
• Elements in a triplet (a; b; c) must be in non-descending order. (ie, a  b  c)
• The solution set must not contain duplicate triplets.
For example, given array S = {-1 0 1 2 -1 -4}.
A solution set is:
(-1, 0, 1)
(-1, -1, 2)
```
[点击查看答案](./2.1.8.hpp)
2.1.9 3Sum Closest
```
描述：
Given an array S of n integers, find three integers in S such that the sum is closest to a given number,
target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
For example, given array S = {-1 2 1 -4}, and target = 1.
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
```
[点击查看答案](./2.1.9.hpp)