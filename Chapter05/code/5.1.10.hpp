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

// Recover Binary Search Tree
// 中序遍历,递归
// 时间复杂度O(n)，空间复杂度O(logn)
// 本代码仅仅是为了帮助理解题目
class Solution_1 {
public:
    void recoverTree(TreeNode *root) {
        inOrder( root);
        std::swap(p1->val, p2->val);
    }
private:
    void inOrder(TreeNode *root) {
        if ( root ==  nullptr ) return;
        if ( root->left != nullptr ) inOrder(root->left);

        if ( prev != nullptr && root->val < prev->val ) {
            if ( p1 == nullptr) {
                p1 = prev;
                p2 = root;
            } else {
                p2 = root;
            }
        }
        prev = root;
        if ( root->right != nullptr ) inOrder(root->right);
    }
    TreeNode *p1 = nullptr;
    TreeNode *p2 = nullptr;
    TreeNode *prev = nullptr;
};

// Recover Binary Search Tree
// Morris中序遍历，时间复杂度O(n)，空间复杂度O(1)
class Solution_2 {
public:
    void recoverTree(TreeNode* root) {
        std::pair<TreeNode*, TreeNode*> broken;
        TreeNode* prev = nullptr;
        TreeNode* cur = root;

        while (cur != nullptr) {
            if (cur->left == nullptr) {
                detect(broken, prev, cur);
                prev = cur;
                cur = cur->right;
            } else {
                auto node = cur->left;

                while (node->right != nullptr && node->right != cur)
                    node = node->right;

                if (node->right == nullptr) {
                    node->right = cur;
                    //prev = cur; 不能有这句！因为cur还没有被访问
                    cur = cur->left;
                } else {
                    detect(broken, prev, cur);
                    node->right = nullptr;
                    prev = cur;
                    cur = cur->right;
                }
            }
        }

        swap(broken.first->val, broken.second->val);
    }

    void detect(pair<TreeNode*, TreeNode*>& broken, TreeNode* prev,
                TreeNode* current) {
        if (prev != nullptr && prev->val > current->val) {
            if (broken.first == nullptr) {
                broken.first = prev;
            } //不能用else，例如 {0,1}，会导致最后 swap时second为nullptr，
              //会 Runtime Error
            broken.second = current;
        }
    }
};
