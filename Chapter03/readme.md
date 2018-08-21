# 3。字符串
## 3.1 Valid Palindrome
描述  
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
For example,
"A man, a plan, a canal: Panama" is a palindrome. "race a car" is not a palindrome.
\Note: Have you consider that the string might be empty? This is a good question to ask during an interview.
For the purpose of this problem, we define empty string as valid palindrome.

题意：  
判断字符串是不是回文序列

答案：[c++](code/3.1.hpp)

## 3.2 Implement strStr()
描述  
Implement strStr().
Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.

题意:  
找出子序列的起始位置

答案：[c++](code/3.2.hpp)

## 3.3 String to Integer (atoi)
描述:  
Implement atoi to convert a string to an integer.
Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

题意：  
将字符串转换成数字

答案：[c++](code/3.3.hpp)

## 3.4 Add Binary
描述：  
Given two binary strings, return their sum (also a binary string).
For example,
a = "11" b = "1"
Return "100".

题意：  
二进制数相加

答案：[c++](code/3.4.hpp)

## 3.5 Longest Palindromic Substring
描述  
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

题意：  

题目[地址](https://soulmachine.gitbooks.io/algorithm-essentials/content/cpp/string/longest-palindromic-substring.html)

答案：[c++](code/3.5.hpp)

## 3.6 Regular Expression Matching

描述

Implement regular expression matching with support for '.' and '*'.
'.' Matches any single character. '*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).
The function prototype should be:
bool isMatch(const char *s, const char *p)
Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true

题目[地址](https://soulmachine.gitbooks.io/algorithm-essentials/content/cpp/string/regular-expression-matching.html)

题意：  
对字符串进行正则匹配，实现 '.' 和 '*'的匹配  
答案：[C++](code/3.6.hpp)
