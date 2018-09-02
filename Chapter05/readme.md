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
 1
  \
   2
  /
 3
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
 1
  \
   2
  /
 3
return [1,3,2].
Note: Recursive solution is trivial, could you do it iteratively?

题意：

中序遍历

答案：[C++](code/5.1.2.hpp)
