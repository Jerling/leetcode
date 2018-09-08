#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

// 递归版
class MySolution
{
public:
    bool isBalanceBinaryTree(TreeNode *root){
        if( !root ) return true;
        if( !root->left ){
            if(!root->right) return true;
            if(root->right->left || root->right->right) return false;
        }
        if(!root->right && (root->left->left || root->left->right)) return false;
        return isBalanceBinaryTree(root->left) && isBalanceBinaryTree(root->right);
    }
};

// Balanced Binary Tree
// 时间复杂度O(n)，空间复杂度O(logn)
class Solution {
public:
    bool isBalanced (TreeNode* root) {
        return balancedHeight (root) >= 0;
    }

    /**
     * Returns the height of `root` if `root` is a balanced tree,
     * otherwise, returns `-1`.
     */
    int balancedHeight (TreeNode* root) {
        if (root == nullptr) return 0;  // 终止条件

        int left = balancedHeight (root->left);
        int right = balancedHeight (root->right);

        if (left < 0 || right < 0 || abs(left - right) > 1) return -1;  // 剪枝

        return std::max(left, right) + 1; // 三方合并
    }
};

