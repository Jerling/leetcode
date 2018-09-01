# 4. 栈和队列
## 4.1 栈 
### 4.1.1 Valid Parentheses

描述

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

题意:  
判断给定的括号是否为有效的

答案：[C++](code/4.1.1.hpp)

### 4.1.2 Longest Valid Parentheses
描述：  􏰟􏰠
Given a string containing just the characters '(' and ')', find the length of the longest valid (well- formed) parentheses substring.
For "(()", the longest valid parentheses substring is "()", which has length = 2.
Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

题意：  
找出括号中所有有效的成对括号的个数

答案：[C++](code/4.1.2.hpp)

### 4.1.3 Largest Rectangle in Histogram
描述：  
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

题意:  
给出一串数字表示高度，宽度都为1，求出最大矩形的面积。

答案:  [C++](code/4.1.3.hpp)

### Evaluate Reverse Polish Notation

描述

Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are +, -, *, /. Each operand may be an integer or another expression.
Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
  
题意： 求解逆波兰式

答案：[C++](code/4.1.4.hpp)
