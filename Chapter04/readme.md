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

### 4.1.4 Evaluate Reverse Polish Notation

描述

Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are +, -, *, /. Each operand may be an integer or another expression.
Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
  
题意： 求解逆波兰式

答案：[C++](code/4.1.4.hpp)

### 4.1.5 Implement Stack using Queues
描述:  
Implement the following operations of a stack using queues.
push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Notes:
You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).

题意：  
用队列实现栈

分析:  
可以用两个队列，q和tmp，q存放元素，tmp用来作中转。
push(x)，先将x push 到tmp，然后把q中的元素全部弹出来，存入tmp，最后切换q和tmp
pop()，直接将q的队首元素弹出来即可
该算法push的算法复杂度是O(n), pop的算法复杂度O(1)。
另个一个方法是，让pop是O(n), push是O(1)，思路很类似，就不赘述了。

## 4.2 队列
### 4.2.1 Implement Queue using Stacks

描述:

Implement the following operations of a queue using stacks.
push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Notes:
You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).

分析:

可以用两个栈，s和tmp，s存放元素，tmp用来作中转。
push(x)，先将s中的元素全部弹出来，存入tmp，把x push 到tmp，然后把tmp中的元素全部弹出来，存入s
pop()，直接将s的栈顶元素弹出来即可
该算法push的算法复杂度是O(n), pop的算法复杂度O(1)。
另个一个方法是，让pop是O(n), push是O(1)，思路很类似，就不赘述了。

