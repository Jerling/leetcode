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

// Symmetric Tree
// 递归版，时间复杂度O(n)，空间复杂度O(logn)
class Solution_1 {
public:
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) return true;
        return isSymmetric(root->left, root->right);
    }
    bool isSymmetric(TreeNode *p, TreeNode *q) {
        if (p == nullptr && q == nullptr) return true;   // 终止条件
        if (p == nullptr || q == nullptr) return false;  // 终止条件
        return p->val == q->val      // 三方合并
            && isSymmetric(p->left, q->right)
            && isSymmetric(p->right, q->left);
    }
};

// Symmetric Tree
// 迭代版，时间复杂度O(n)，空间复杂度O(logn)
class Solution_2 {
public:
    bool isSymmetric (TreeNode* root) {
        if (!root) return true;

        std::stack<TreeNode*> s;
        s.push(root->left);
        s.push(root->right);

        while (!s.empty ()) {
            auto p = s.top (); s.pop();
            auto q = s.top (); s.pop();

            if (!p && !q) continue;
            if (!p || !q) return false;
            if (p->val != q->val) return false;

            s.push(p->left);
            s.push(q->right);

            s.push(p->right);
            s.push(q->left);
        }

        return true;
    }
};
