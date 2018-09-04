#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

// 自己迭代版：
class MySolution
{
public:
    std::vector<int> BinaryTreeRightSideViews(TreeNode *root){
        std::vector<int> result;
        if (!root) return result;
        std::queue<TreeNode *> pre;
        pre.push(root);
        int len = pre.size(), i=0;
        while (len > 0){
            std::cout << "len(" << i << ") = " <<len << "\n";
            for(int i = 0; i < len; ++i){
                TreeNode *p = pre.front();
                if (p->left) pre.push(p->left);
                if (p->right) pre.push(p->right);
                if(i == len-1)
                    result.push_back(p->val);
                pre.pop();
            }
            len = pre.size();++i;
        }
        return result;
    }
};

// Binary Tree Level Order Traversal
// 递归版，时间复杂度O(n)，空间复杂度O(n)
class Solution_1 {
public:
    std::vector<int> BinaryTreeRightSideViews(TreeNode *root) {
        std::vector<std::vector<int> > result;
        traverse(root, 1, result);
        std::vector<int> ret;
        for(auto v:result) ret.push_back(v.back());
        return ret;
    }

    void traverse(TreeNode *root, size_t level, std::vector<std::vector<int> > &result) {
        if (!root) return;

        if (level > result.size())
            result.push_back(std::vector<int>());

        result[level-1].push_back(root->val);
        traverse(root->left, level+1, result);
        traverse(root->right, level+1, result);
    }
};

// Binary Tree Level Order Traversal
// 迭代版，时间复杂度O(n)，空间复杂度O(1)
class Solution_2 {
public:
    std::vector<int> BinaryTreeRightSideViews(TreeNode *root) {
        std::vector<int> result;
        std::queue<TreeNode*> current, next;

        if(root == nullptr) {
            return result;
        } else {
            current.push(root);
        }

        while (!current.empty()) {
            std::vector<int> level; // elments in one level
            while (!current.empty()) {
                TreeNode* node = current.front();
                current.pop();
                level.push_back(node->val);
                if (node->left != nullptr) next.push(node->left);
                if (node->right != nullptr) next.push(node->right);
            }
            result.push_back(level.back());
            swap(next, current);
        }
        return result;
    }
};
