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
    int miniDepth(TreeNode *root){
        if(!root) return 0;
        std::queue<TreeNode *> q;
        q.push(root);
        int levelnums = q.size();
        int level = 1;
        while(!q.empty()){
            while(levelnums > 0){
                TreeNode *tmp = q.front(); q.pop();
                if(!tmp->right && !tmp->left) return level;
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
                --levelnums;
            }
            ++level;levelnums = q.size();
        }
        return level;
    }
};

// Minimum Depth of Binary Tree
// 递归版，时间复杂度O(n)，空间复杂度O(logn)
class Solution_1 {
public:
    int minDepth(const TreeNode *root) {
        return minDepth(root, false);
    }
private:
    static int minDepth(const TreeNode *root, bool hasbrother) {
        if (!root) return hasbrother ? INT_MAX : 0;

        return 1 + std::min(minDepth(root->left, root->right != NULL),
                       minDepth(root->right, root->left != NULL));
    }
};

// Minimum Depth of Binary Tree
// 迭代版，时间复杂度O(n)，空间复杂度O(logn)
class Solution_2 {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int result = INT_MAX;

        std::stack<std::pair<TreeNode*, int> > s;
        s.push(std::make_pair(root, 1));

        while (!s.empty()) {
            auto node = s.top().first;
            auto depth = s.top().second;
            s.pop();

            if (node->left == nullptr && node->right == nullptr)
                result = std::min(result, depth);

            if (node->left && result > depth) // 深度控制，剪枝
                s.push(std::make_pair(node->left, depth + 1));

            if (node->right && result > depth) // 深度控制，剪枝
                s.push(std::make_pair(node->right, depth + 1));
        }

        return result;
    }
};
