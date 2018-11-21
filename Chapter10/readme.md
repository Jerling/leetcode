# 深度优先搜索 #

## Palindrome Partitioning ##

描述

Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab", Return

``` cpp-objdump
  [
    ["aa","b"],
    ["a","a","b"]
  ]
```

分析

在每一步都可以判断中间结果是否为合法结果，用回溯法。

一个长度为n的字符串，有n-1个地方可以砍断，每个地方可断可不断，因此复杂度为O(2n−1)O(2^{n-1})O(2​n−1​​)

答案: [c++](code/10.1.hpp)  [https://soulmachine.gitbooks.io/algorithm-essentials/content/cpp/dfs/palindrome-partitioning.html](https://soulmachine.gitbooks.io/algorithm-essentials/content/cpp/dfs/palindrome-partitioning.html)
## Unique Paths ##

描述

A robot is located at the top-left corner of a m × n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

答案：[C++](code/10.2.hpp)  [https://soulmachine.gitbooks.io/algorithm-essentials/content/cpp/dfs/unique-paths.html](https://soulmachine.gitbooks.io/algorithm-essentials/content/cpp/dfs/unique-paths.html)

## N-Queens ##
描述

The n-queens puzzle is the problem of placing n queens on an `n × n` chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example, There exist two distinct solutions to the 4-queens puzzle:

``` cpp-objdump
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
```

分析

经典的深搜题。

设置一个数组 `vector<int> C(n, 0)`, C[i] 表示第i行皇后所在的列编号，即在位置 (i, C[i])上放了一个皇后，这样用一个一维数组，就能记录整个棋盘。

答案：[https://soulmachine.gitbooks.io/algorithm-essentials/content/cpp/dfs/n-queens.html](https://soulmachine.gitbooks.io/algorithm-essentials/content/cpp/dfs/n-queens.html)

## Restore IP Address ##
描述
Given a string containing only digits, restore it by returning all possible valid IP address combinations.
For example: Given "25525511135",
return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
分析
必须要走到底部才能判断解是否合法，深搜。
答案：https://soulmachine.gitbooks.io/algorithm-essentials/content/cpp/dfs/restore-ip-addresses.html

## Combination Sum ##

描述
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
The same repeated number may be chosen from C unlimited number of times.
Note:
- All numbers (including target) will be positive integers.
- Elements in a combination (a_1, a_2, ..., a_ka​1​​ ,a​2​​ ,...,a​k​​ ) must be
in non-descending order. (ie, a_1 \leq a_2 \leq ... \leq a_ka​1​​ ≤a​2​​ ≤...≤a​k​​ ).
- The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, A solution set is:

``` cpp-objdump
[7] 
[2, 2, 3]
```
答案：https://soulmachine.gitbooks.io/algorithm-essentials/content/cpp/dfs/combination-sum.html

## Word Search ##

描述
Given a 2D board and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighbouring. The same letter cell may not be used more than once.
For example, Given board =

``` cpp-objdumpcpp
[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
```

word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

答案：https://soulmachine.gitbooks.io/algorithm-essentials/content/cpp/dfs/word-search.html

# 小结 #
## 1.  适用场景
输入数据：如果是递归数据结构，如单链表，二叉树，集合，则百分之百可以用深搜；如果是非递归数据结构，如一维数组，二维数组，字符串，图，则概率小一些。

## 2.  状态转换图：树或者DAG。
求解目标：多阶段存在性问题。必须要走到最深（例如对于树，必须要走到叶子节点）才能得到一个解，这种情况适合用深搜。

## 3. 思考的步骤
1. 是求路径条数，还是路径本身（或动作序列）？
深搜最常见的三个问题，求可行解的总数，求一个可行解，求所有可行解。如果是路径条数，则不需要存储路径。
如果是求路径本身，则要用一个数组path[]存储路径。跟宽搜不同，宽搜虽然最终求的也是一条路径，但是需要存储扩展过程中的所有路径，
在没找到答案之前所有路径都不能放弃；而深搜，在搜索过程中始终只有一条路径，因此用一个数组就足够了。
只要求一个解，还是要求所有解？如果只要求一个解，那找到一个就可以返回；如果要求所有解，找到了一个后，还要继续扩展，直到遍历完。
广搜一般只要求一个解，因而不需要考虑这个问题（广搜当然也可以求所有解，这时需要扩展到所有叶子节点，
相当于在内存中存储整个状态转换图，非常占内存，因此广搜不适合解这类问题）。

2. 如何表示状态？
即一个状态需要存储哪些些必要的数据，才能够完整提供如何扩展到下一步状态的所有信息。跟广搜不同，深搜的惯用写法，
不是把数据记录在状态struct里，而是添加函数参数（有时为了节省递归堆栈，用全局变量），struct里的字段与函数参数一一对应。

3. 如何扩展状态？
这一步跟上一步相关。状态里记录的数据不同，扩展方法就不同。对于固定不变的数据结构（一般题目直接给出，作为输入数据），
如二叉树，图等，扩展方法很简单，直接往下一层走，对于隐式图，要先在第1步里想清楚状态所带的数据，想清楚了这点，那如何扩展就很简单了。

4. 终止条件是什么？
终止条件是指到了不能扩展的末端节点。对于树，是叶子节点，对于图或隐式图，是出度为0的节点。

5. 收敛条件是什么？
收敛条件是指找到了一个合法解的时刻。如果是正向深搜（父状态处理完了才进行递归，即父状态不依赖子状态，递归语句一定是在最后，尾递归），
则是指是否达到目标状态；如果是逆向深搜（处理父状态时需要先知道子状态的结果，此时递归语句不在最后），则是指是否到达初始状态。


由于很多时候终止条件和收敛条件是是合二为一的，因此很多人不区分这两种条件。仔细区分这两种条件，还是很有必要的。
为了判断是否到了收敛条件，要在函数接口里用一个参数记录当前的位置（或距离目标还有多远）。如果是求一个解，直接返回这个解；如果是求所有解，要在这里收集解，即把第一步中表示路径的数组path[]复制到解集合里。

## 4. 关于判重
1. 是否需要判重？
如果状态转换图是一棵树，则不需要判重，因为在遍历过程中不可能重复；如果状态转换图是一个DAG，则需要判重。这一点跟BFS不一样，BFS的状态转换图总是DAG，必须要判重。

2. 怎样判重？
跟广搜相同，见第九节。同时，DAG说明存在重叠子问题，此时可以用缓存加速，见第8步。

3. 如何加速？
    - 剪枝   
    深搜一定要好好考虑怎么剪枝，成本小收益大，加几行代码，就能大大加速。这里没有通用方法，只能具体问题具体分析，要充分观察，充分利用各种信息来剪枝，在中间节点提前返回。
    - 缓存  
        - 前提条件：状态转换图是一个DAG。DAG=>存在重叠子问题=>子问题的解会被重复利用，用缓存自然会有加速效果。如果依赖关系是树状的（例如树，单链表等），
        没必要加缓存，因为子问题只会一层层往下，用一次就再也不会用到，加了缓存也没什么加速效果。
        - 具体实现：可以用数组或HashMap。维度简单的，用数组；维度复杂的，用HashMap，C++有map，C++ 11以后有unordered_map，比map快。
        

拿到一个题目，当感觉它适合用深搜解决时，在心里面把上面8个问题默默回答一遍，代码基本上就能写出来了。对于树，不需要回答第5和第8个问题。
如果读者对上面的经验总结看不懂或感觉“不实用”，很正常，因为这些经验总结是我做了很多题目后总结出来的，从思维的发展过程看，“经验总结”要晚于感性认识，
所以这时候建议读者先做做前面的题目，积累一定的感性认识后，再回过头来看这一节的总结，一定会有共鸣。
## 5. 代码模板

``` cpp-objdumpcpp
/**
 * dfs模板.
 * @param[in] input 输入数据指针
 * @param[out] path 当前路径，也是中间结果
 * @param[out] result 存放最终结果
 * @param[inout] cur or gap 标记当前位置或距离目标的距离
 * @return 路径长度，如果是求路径本身，则不需要返回长度
 */
void dfs(type &input, type &path, type &result, int cur or gap) {
    if (数据非法) return 0;   // 终止条件
    if (cur == input.size()) { // 收敛条件
    // if (gap == 0) {
        将path放入result
    }

    if (可以剪枝) return;

    for(...) { // 执行所有可能的扩展动作
        执行动作，修改path
        dfs(input, step + 1 or gap--, result);
        恢复path
    }
}
```

## 6. 深搜与回溯法的区别
深搜(Depth-first search, DFS)的定义见 http://en.wikipedia.org/wiki/Depth_first_search，回溯法(backtracking)的定义见 http://en.wikipedia.org/wiki/Backtracking
回溯法 = 深搜 + 剪枝。一般大家用深搜时，或多或少会剪枝，因此深搜与回溯法没有什么不同，可以在它们之间画上一个等号。本书同时使用深搜和回溯法两个术语，但读者可以认为二者等价。
深搜一般用递归(recursion)来实现，这样比较简洁。
深搜能够在候选答案生成到一半时，就进行判断，抛弃不满足要求的答案，所以深搜比暴力搜索法要快。
- 深搜与递归的区别
   - 深搜经常用递归(recursion)来实现，二者常常同时出现，导致很多人误以为他俩是一个东西。
   - 深搜，是逻辑意义上的算法，递归，是一种物理意义上的实现，它和迭代(iteration)是对应的。
   - 深搜，可以用递归来实现，也可以用栈来实现；而递归，一般总是用来实现深搜。可以说，递归一定是深搜，深搜不一定用递归。

递归有两种加速策略，一种是 剪枝(prunning)，对中间结果进行判断，提前返回；一种是缓存，缓存中间结果，防止重复计算，用空间换时间。
其实，递归+缓存，就是 memorization。所谓memorization（翻译为备忘录法，就是"top-down with cache"（自顶向下+缓存），
它是Donald Michie 在1968年创造的术语，表示一种优化技术，在top-down 形式的程序中，使用缓存来避免重复计算，从而达到加速的目的。
memorization 不一定用递归，就像深搜不一定用递归一样，可以在迭代(iterative)中使用 memorization 。
递归也不一定用 memorization，可以用memorization来加速，但不是必须的。只有当递归使用了缓存，它才是 memorization 。
既然递归一定是深搜，为什么很多书籍都同时使用这两个术语呢？在递归味道更浓的地方，一般用递归这个术语，在深搜更浓的场景下，用深搜这个术语，
读者心里要弄清楚他俩大部分时候是一回事。在单链表、二叉树等递归数据结构上，递归的味道更浓，这时用递归这个术语；在图、隐式图等数据结构上，深搜的味道更浓，这时用深搜这个术语。

# 分治法 #

## Pow(x, n) ##
描述
Implement pow(x, n).

答案：[C++](code/11.1.hpp)

## Sqrt ##
描述
Implement int sqrt(int x).
Compute and return the square root of x.
分析
二分查找

答案：https://soulmachine.gitbooks.io/algorithm-essentials/content/cpp/divide-and-conquer/sqrt.html
