#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

// 递归版：
class MySolution
{
public:
    std::vector<std::vector<int> > BinaryTreeZigzagLevel(TreeNode *root){
        std::vector<std::vector<int> > result;
        if (!root) return result;
        std::queue<TreeNode *> pre;
        pre.push(root);
        int len = pre.size(), i=1;
        while (len > 0){
            std::cout << "len(" << i << ") = " <<len << "\n";
            std::vector<int> level;
            for(int i = 0; i < len; ++i){
                TreeNode *p = pre.front();
                if (p->left) pre.push(p->left);
                if (p->right) pre.push(p->right);
                level.push_back(p->val);
                pre.pop();
            }
            if(i%2 != 1) std::reverse(level.begin(), level.end());
            result.push_back(level);
            len = pre.size();++i;
        }
        return result;
    }
};

// Binary Tree Level Order Traversal
// 递归版，时间复杂度O(n)，空间复杂度O(n)
class Solution_1 {
public:
    std::vector<std::vector<int> > BinaryTreeZigzagLevel(TreeNode *root) {
        std::vector<std::vector<int> > result;
        traverse(root, 1, result);
        for(size_t i=1; i<result.size(); i+=2)
            std::reverse(result[i].begin(), result[i].end());
        return result;
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
    std::vector<std::vector<int> > BinaryTreeZigzagLevel(TreeNode *root) {
        std::vector<std::vector<int> > result;
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
            result.push_back(level);
            swap(next, current);
        }
        for(size_t i=1; i<result.size(); i+=2)
            std::reverse(result[i].begin(), result[i].end());
        return result;
    }
};
