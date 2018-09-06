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
    bool isSameTree(TreeNode *root1, TreeNode *root2){
        if(!root1 && !root2) return true;
        if(!root2 || !root1) return false;
        return root1->val == root2->val && isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right);
    }
};

// 迭代版
class MySolution_2
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q){
        if(!q && !p) return true;
        if((!q || !p) && (p->val != q->val)) return false;
        std::queue<TreeNode *> queuep;
        std::queue<TreeNode *> queueq;
        queueq.push(q);queuep.push(p);
        while(!queuep.empty() && !queueq.empty()){
            TreeNode *tmpp = queuep.front();
            TreeNode *tmpq = queueq.front();
            queuep.pop();queueq.pop();
            if(tmpq->val != tmpp->val) return false;
            if(tmpq->left && tmpp->left){
                queuep.push(tmpp->left);
                queueq.push(tmpq->left);
            }
            else if(!tmpq->left ^ !tmpp->left) return false;
            if(tmpp->right && tmpq->right){
                queuep.push(tmpp->right);
                queueq.push(tmpq->right);
            }
            else if(!tmpq->right ^ !tmpp->right) return false;
        }
        if(!queuep.empty() || !queueq.empty()) return false;
        return true;
    }
};

// Same Tree
// 迭代版，时间复杂度O(n)，空间复杂度O(logn)
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        std::stack<TreeNode*> s;
        s.push(p);
        s.push(q);

        while(!s.empty()) {
            p = s.top(); s.pop();
            q = s.top(); s.pop();

            if (!p && !q) continue;
            if (!p || !q) return false;
            if (p->val != q->val) return false;

            s.push(p->left);
            s.push(q->left);

            s.push(p->right);
            s.push(q->right);
        }
        return true;
    }
};
