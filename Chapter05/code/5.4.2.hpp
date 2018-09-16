#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class MySolution
{
public:
    int maxDepth(TreeNode *root){
        if(!root) return 0;
        std::queue<TreeNode *> q;
        q.push(root);
        int levelnums = q.size();
        int level = 0;
        while(!q.empty()){
            while(levelnums > 0){
                TreeNode *tmp = q.front(); q.pop();
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
                --levelnums;
            }
            ++level;levelnums = q.size();
        }
        return level;
    }
};

// Maximum Depth of Binary Tree
// 时间复杂度O(n)，空间复杂度O(logn)
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (root == nullptr) return 0;

        return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
