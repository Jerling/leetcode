#include <iostream>
#include <algorithm>
#include <queue>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution_1
{
public:
    TreeNode *LCA(TreeNode *root, TreeNode *p, TreeNode *q){
        if (!root || !p || !q) return nullptr;
        if (std::max(p->val, q->val) < root->val)  // 情况a
            return LCA(root->left, p, q);
        else if (std::min(p->val, q->val) > root->val)   // 情况b
            return LCA(root->right, p, q);
        else           // 情况c,d
            return root;
    }
};

class Solution_2
{
public:
    // iterative LCA
    TreeNode *LCA(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root || !p || !q) return NULL;
        while(true)
        {
            if (std::max(p->val, q->val) < root->val)
                root = root->left;
            else if (std::min(p->val, q->val) > root->val)
                root = root->right;
            else
                return root;
        }
    }
};
