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
### 2.1.9 3Sum Closest
```
描述：
Given an array S of n integers, find three integers in S such that the sum is closest to a given number,
target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
For example, given array S = {-1 2 1 -4}, and target = 1.
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
```
[点击查看答案](./2.1.9.hpp)

### 2.1.11 Remove Element
```
描述：
Given an array and a value, remove all instances of that value in place and return the new length.
The order of elements can be changed. It does't matter what you leave beyond the new length.
```
[点击查看答案](./2.1.11.hpp)

### 2.1.12
```
描述：
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation
of numbers.
If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending
order).
The replacement must be in-place, do not allocate extra memory.
Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the
right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,12.1.12
```
[点击查看答案](./2.1.12.hpp)

### 2.1.13 Permutation Sequence
```
描述：
The set [1,2,3,􀄉,n] contains a total of n! unique permutations.
By listing and labeling all of the permutations in order, We get the following sequence (ie, for n = 3):
"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.
Note: Given n will be between 1 and 9 inclusive.
```
[点击查看答案](./2.1.13.hpp)

### 2.1.16 Rotate Image
```
描述
You are given an n × n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).
Follow up: Could you do this in-place?
```
[点击查看答案](./2.1.16.hpp)

### 2.1.17 Plus One
```
描述
Given a number represented as an array of digits, plus one to the number.
```
[点击查看答案](./2.1.17.hpp)

### 2.1.18 Climbing Stairs
```
描述：
You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
```
[点击查看答案](./2.1.18.hpp)
## 2.2 单链表
单链表定义：
```cpp
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr){}
};
```

### 2.2.1 Add Two Numbers
```
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse
order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
```
[点击查看答案](./2.2.1.hpp)

### 2.2.2 Reverse Linked List ||
```
Reverse a linked list from position m to n. Do it in-place and in one-pass.
For example: Given 1->2->3->4->5->nullptr, m = 2 and n = 4,
return 1->4->3->2->5->nullptr.
Note: Given m, n satisfy the following condition: 1 ≤ m ≤ n ≤ length of list.
```
[点击查看答案](./2.2.2.hpp)

### 2.2.3 Partition List
```
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater
than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.
For example, Given 1->4->3->2->5->2 and x = 3, return 1->2->2->4->3->5.
```
[点击查看答案](./2.2.3.hpp)

### 2.2.4 Remove Duplicates from Sorted List
```
Given a sorted linked list, delete all duplicates such that each element appear only once.
For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
```
[点击查看答案](./2.2.4.hpp)

### 2.2.5 Remove Duplicates from Sorted List II
```
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers
from the original list.
For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
```
[点击查看答案](./2.2.5.hpp)

### 2.2.6 Rotate List
```
描述
Given a list, rotate the list to the right by k places, where k is non-negative.
For example: Given 1->2->3->4->5->nullptr and k = 2, return 4->5->1->2->3->nullptr.
```
[点击查看答案](./2.2.6.hpp)

### 2.2.7 Remove Nth Node From End of List ###
```
描述
Given a linked list, remove the n-th node from the end of list and return its head.
For example, Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
```
[点击查看答案](./2.2.7.hpp)

### 2.2.8 Swap Nodes in Pairs ###

```
描述
Given a linked list, swap every two adjacent nodes and return its head.
For example, Given 1->2->3->4, you should return the list as 2->1->4->3.
Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
```
[点击查看答案](./2.2.8.hpp)

### 2.2.9 Reverse Nodes in k-Group ###

```
描述
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
You may not alter the values in the nodes, only nodes itself may be changed.
Only constant memory is allowed.
For example, Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5
[点击查看答案](./2.2.9.hpp)
```
### 2.2.10 Copy List with Random Pointer
```
描述
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
Return a deep copy of the list.
```
[点击查看答案](./2.2.10.hpp)

### 2.1.11 Linked List Cycle ###
```
描述
Given a linked list, determine if it has a cycle in it.
Follow up: Can you solve it without using extra space?
[点击查看答案](./2.2.11.hpp)
```

### 2.2.12 Linked List Cycle II ###
```
描述
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
Follow up: Can you solve it without using extra space?
```
[点击查看答案](./2.2.12.hpp)

### 2.2.13 Reorder List ###
```
描述
Given a singly linked list L: L_0 \rightarrow L_1 \rightarrow \cdots \rightarrow L_{n-1} \rightarrow L_nL:L
​0
​​ →L
​1
​​ →⋯→L
​n−1
​​ →L
​n
​​ , reorder it to: L_0 \rightarrow L_n \rightarrow L_1 \rightarrow L_{n-1} \rightarrow L_2 \rightarrow L_{n-2} \rightarrow \cdotsL
​0
​​ →L
​n
​​ →L
​1
​​ →L
​n−1
​​ →L
​2
​​ →L
​n−2
​​ →⋯
You must do this in-place without altering the nodes' values.

For example, Given {1,2,3,4}, reorder it to {1,4,2,3}.
```
