#include <iostream>
#include <algorithm>
#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 解题有误， 没有考虑左子树的所有值小于root，右子树同理
class MySolution
{
public:
    bool isBST(TreeNode *root){
        if(!root) return true;
        bool state = true;
        if(root->left && root->left->val > root->val)
                state = false;
        if(root->right && root->right->val < root->val)
                state = false;
        return state && isBST(root->left) && isBST(root->right);
    }
};

// Validate Binary Search Tree
// 时间复杂度O(n)，空间复杂度O(\logn)
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }

    bool isValidBST(TreeNode* root, long long lower, long long upper) {
        if (root == nullptr) return true;

        return root->val > lower && root->val < upper
                                                && isValidBST(root->left, lower, root->val)
            && isValidBST(root->right, root->val, upper);
    }
};
