# 5. 二叉树
LeetCode 上的二叉树的节点定义：
```cpp
// 树的节点
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }
};
```

## 5.1. 二叉树的遍历
树的遍历有两类：深度优先遍历和宽度优先遍历。深度优先遍历又可分为两种：先根（次序）遍历和后根（次序）遍历。
树的先根遍历是：先访问树的根结点，然后依次先根遍历根的各棵子树。树的先跟遍历的结果与对应二叉树（孩子兄弟表示法）的先序遍历的结果相同。
树的后根遍历是：先依次后根遍历树根的各棵子树，然后访问根结点。树的后跟遍历的结果与对应二叉树的中序遍历的结果相同。
二叉树的先根遍历有：先序遍历(root->left->right)，root->right->left；后根遍历有：后序遍历(left->right->root)，right->left->root；二叉树还有个一般的树没有的遍历次序，中序遍历(left->root->right)。

### 5.1.1 Binary Tree Preorder Traversal

描述

Given a binary tree, return the preorder traversal of its nodes' values.
For example: Given binary tree {1,#,2,3},

 ``` cpp-objdump
 1
  \
   2
  /
 3
 ```

return [1,2,3].
Note: Recursive solution is trivial, could you do it iteratively?

题意：

给出二叉树的先序遍历

答案： [C++](code/5.1.1.hpp)

### 5.1.2 Binary Tree Inorder Traversal

描述

Given a binary tree, return the inorder traversal of its nodes' values.
For example:
Given binary tree {1,#,2,3},

 ``` cpp-objdump
 1
  \
   2
  /
 3
 ```

return [1,3,2].
Note: Recursive solution is trivial, could you do it iteratively?

题意：

中序遍历

答案：[C++](code/5.1.2.hpp)

### 5.1.3 Binary Tree Postorder Traversal

描述

Given a binary tree, return the postorder traversal of its nodes' values.
For example: Given binary tree {1,#,2,3},

 ``` cpp-objdump
 1
  \
   2
  /
 3
 ```

return [3,2,1].
Note: Recursive solution is trivial, could you do it iteratively?

题意: 后序遍历

答案：[C++](code/5.1.3.hpp)

### 5.1.4 Binary Tree Level Order Traversal
描述
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
For example: Given binary tree {3,9,20,#,#,15,7},

``` cpp-objdump
    3
   / \
  9  20
    /  \
   15   7
```

return its level order traversal as:

``` cpp-objdump
[
  [3],
  [9,20],
  [15,7]
]
```

题意：按层次保存

答案：[C++](code/5.1.4.hpp)

### 5.1.5 Binary Tree Level Order Traversal II

描述

Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
For example: Given binary tree {3,9,20,#,#,15,7},

``` cpp-objdump
    3
   / \
  9  20
    /  \
   15   7
```

return its bottom-up level order traversal as:

``` cpp-objdump
[
  [15,7]
  [9,20],
  [3],
]
```

题意：层次逆序遍历

答案：[C++](code/5.1.5.hpp)

### 5.1.6 Binary Tree Right Side View

描述

Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
For example, given the following binary tree,

``` cpp-objdump
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
```

You should return [1, 3, 4]

题意：返回树右边的节点

答案：[C++](code/5.1.6.hpp)

### 5.1.7 Invert Binary Tree

描述

Invert a binary tree.

``` cpp-objdump
     4
   /   \
  2     7
 / \   / \
1   3 6   9
to

     4
   /   \
  7     2
 / \   / \
9   6 3   1
```

题意：交换树的左右分支

答案：[C++](code/5.1.7.hpp)

### 5.1.9 Binary Tree Zigzag Level Order Traversal

描述

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
For example:
Given binary tree {3,9,20,#,#,15,7},
```cpp
    3
   / \
  9  20
    /  \
   15   7
```
return its zigzag level order traversal as:

``` cpp-objdump
[
  [3],
  [20,9],
  [15,7]
]
```

题意：之字形层次访问

答案：[C++](code/5.1.9.hpp)

### 5.1.10 Recover Binary Search Tree

描述

Two elements of a binary search tree (BST) are swapped by mistake.
Recover the tree without changing its structure.
Note: A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

题意：修复损坏的BST

分析

O(logn)空间的解法是，中序递归遍历，用两个指针存放在遍历过程中碰到的两处逆向的位置。
本题要求O(1)空间，只能用Morris中序遍历。

### 5.1.12 Same Tree

描述

Given two binary trees, write a function to check if they are equal or not.
Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

题意：判断两个二叉树是否相同

答案：[C++](code/5.1.12.hpp)

### 5.1.13 Symmetric Tree

描述

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
```cpp
    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
```
Note: Bonus points if you could solve it both recursively and iteratively.

题意：判断两个二叉树是否对称

答案：[C++](code/5.1.13.hpp)

### 5.1.14 Balanced Binary Tree

描述

Given a binary tree, determine if it is height-balanced.
For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

题意: 高度平衡二叉树

答案：[C++](code/5.1.14.hpp)

### 5.1.14 Flatten Binary Tree to Linked List

描述

Given a binary tree, flatten it to a linked list in-place.
For example, Given

``` cpp-objdump
         1
        / \
       2   5
      / \   \
     3   4   6
```

The flattened tree should look like:

``` cpp-objdump
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
```

题意：将二叉树展平

答案：[C++](code/5.1.15.hpp)

### 5.1.16 Populating Next Right Pointers in Each Node II

描述

Follow up for problem "Populating Next Right Pointers in Each Node".
What if the given tree could be any binary tree? Would your previous solution still work?
Note: You may only use constant extra space.
For example, Given the following binary tree,

``` cpp-objdump
         1
       /  \
      2    3
     / \    \
    4   5    7
```

After calling your function, the tree should look like:

``` cpp-objdump
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
```

题意：将二叉树的每一层用next指针链接起来

答案：[C++](code/5.1.16.hpp)

## 5.2. 二叉树的构建
### 5.2.1 Construct Binary Tree from Preorder and Inorder Traversal

描述

Given preorder and inorder traversal of a tree, construct the binary tree.
Note: You may assume that duplicates do not exist in the tree.

题意：根据先序和中序构建二叉树

答案：[C++](code/5.2.1.hpp)

### 5.2.2 Construct Binary Tree from Inorder and Postorder Traversal

描述

Given inorder and postorder traversal of a tree, construct the binary tree.+

Note: You may assume that duplicates do not exist in the tree.

题意：使用中序和后序构建二叉树

## 5.3. 二叉查找树
### 5.3.1 Unique Binary Search Trees

描述

Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
For example, Given n = 3, there are a total of 5 unique BST's.

   ``` cpp-objdump
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
   ```
   
题意：求1-n之间有多少颗二叉查找树

答案：[C++](code/5.3.1.hpp) [https://soulmachine.gitbooks.io/algorithm-essentials/content/cpp/binary-tree/bst/unique-binary-search-trees.html](https://soulmachine.gitbooks.io/algorithm-essentials/content/cpp/binary-tree/bst/unique-binary-search-trees.html)

### 5.3.2 Unique Binary Search Trees II

描述

Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.
For example, Given n = 3, your program should return all 5 unique BST's shown below.

   ``` cpp-objdump
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
   ```
   
题意：生成所有的二叉查找树

答案：[C++](code/5.3.2.hpp) [https://soulmachine.gitbooks.io/algorithm-essentials/content/cpp/binary-tree/bst/unique-binary-search-trees-ii.html](https://soulmachine.gitbooks.io/algorithm-essentials/content/cpp/binary-tree/bst/unique-binary-search-trees-ii.html)

### 5.3.3 Validate Binary Search Tree

描述

Given a binary tree, determine if it is a valid binary search tree (BST).
Assume a BST is defined as follows:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

题意：判断二叉树是否为BST

答案：[C++](code/5.3.3.hpp)

### 5.3.4 Convert Sorted Array to Binary Search Tree

描述

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

题意：将给定的有序序列转换成平衡 BST

答案：[C++](code/5.3.4.hpp)

### 5.3.5 Convert Sorted List to Binary Search Tree

描述

Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

题意：将单链表构建成平衡BST

答案：[C++](code/5.3.5) [https://soulmachine.gitbooks.io/algorithm-essentials/content/cpp/binary-tree/bst/convert-sorted-list-to-binary-search-tree.html](https://soulmachine.gitbooks.io/algorithm-essentials/content/cpp/binary-tree/bst/convert-sorted-list-to-binary-search-tree.html)

### 5.3.6 LCA of BST

描述

Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

      ``` cpp-objdump
      _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   1      _4       7       9
         /  \
         3   5
      ```

For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

题意：寻找最小的共同祖先

答案：[C++](code/5.3.6.hpp) && [https://soulmachine.gitbooks.io/algorithm-essentials/content/cpp/binary-tree/bst/lca-of-bst.html](https://soulmachine.gitbooks.io/algorithm-essentials/content/cpp/binary-tree/bst/lca-of-bst.html)

### 5.3.7 Kth Smallest Element in a BST
描述

Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:

You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:

What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

Hint:

    Try to utilize the property of a BST.
    What if you could modify the BST node's structure?
    The optimal runtime complexity is O(height of BST).

题意：寻找第k个最小值

答案：[C++](code/5.3.7.hpp)

## 5.4. 二叉递归树
### 5.4.1 Minimum Depth of Binary Tree
描述  
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

题意： 找最小的深度

答案: [c++](code/5.4.1.hpp)

### 5.4.2 Maximum Depth of Binary Tree
描述  
Given a binary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

题意：寻找最大深度

答案：[C++](code/5.4.2.hpp)

### 5.4.3 Path Sum

描述

Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
For example: Given the below binary tree and sum = 22,

          ``` cpp-objdump
          5
         / \
        4   8
       /   / \
      11  13  4
     /  \      \
    7    2      1
          ```

return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

题意：判断是否存在一条路径之和等于给定的sum

答案： [C++](code/5.4.3.hpp)

### 5.4.4 Path Sum II
描述

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example: Given the below binary tree and `sum = 22`,

``` cpp-objdump
          5
         / \
        4   8
       /   / \
      11  13  4
     /  \    / \
    7    2  5   1
```

return

``` cpp-objdump
[
   [5,4,11,2],
   [5,8,4,5]
]
```

### 5.4.5 Binary Tree Maximum Path Sum
描述  
Given a binary tree, find the maximum path sum.
The path may start and end at any node in the tree. For example: Given the below binary tree,
```cpp
  1
 / \
2   3
```
Return 6

题意：找出任意两个节点之间最大距离的路径

答案： [https://soulmachine.gitbooks.io/algorithm-essentials/content/cpp/binary-tree/recursion/binary-tree-maximum-path-sum.html](https://soulmachine.gitbooks.io/algorithm-essentials/content/cpp/binary-tree/recursion/binary-tree-maximum-path-sum.html)

### 5.4.6 Populating Next Right Pointers in Each Node
描述

Given a binary tree

``` cpp-objdump
struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
```

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

    You may only use constant extra space.
    You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).

For example,

``` cpp-objdump
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
```

After calling your function, the tree should look like:

``` cpp-objdump
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
```

题意：将带有next指针的二叉树从左到右链接起来

答案：[C++](code/5.4.6.hpp)
