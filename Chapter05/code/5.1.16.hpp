#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

struct TreeLinkNode
{
    int val;
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
    TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr){}
};

// 递归版
class MySolution
{
public:
    TreeLinkNode *next_right_2(TreeLinkNode *root){
        if(!root) return root;
        std::queue<TreeLinkNode *> level;
        level.push(root);
        size_t len = level.size();
        while(!level.empty()){
            TreeLinkNode *pre = nullptr;
            while(len > 0){
                TreeLinkNode* tmp = level.front();level.pop();
                if(pre) pre->next = tmp;
                pre = tmp;
                if(tmp->left) level.push(tmp->left);
                if(tmp->right) level.push(tmp->right);
                --len;
            }
            if(pre->next) pre->next->next = nullptr;
            len = level.size();
        }
        return root;
    }
};

// Populating Next Right Pointers in Each Node II
// 时间复杂度O(n)，空间复杂度O(1)
class Solution_1 {
public:
    void connect(TreeLinkNode *root) {
        if (root == nullptr) return;

        TreeLinkNode dummy(-1);
        for (TreeLinkNode *curr = root, *prev = &dummy;
             curr; curr = curr->next) {
            if (curr->left != nullptr){
                prev->next = curr->left;
                prev = prev->next;
            }
            if (curr->right != nullptr){
                prev->next = curr->right;
                prev = prev->next;
            }
        }
        connect(dummy.next);
    }
};

// Populating Next Right Pointers in Each Node II
// 时间复杂度O(n)，空间复杂度O(1)
class Solution_2 {
public:
    void connect(TreeLinkNode *root) {
        while (root) {
            TreeLinkNode * next = nullptr; // the first node of next level
            TreeLinkNode * prev = nullptr; // previous node on the same level
            for (; root; root = root->next) {
                if (!next) next = root->left ? root->left : root->right;

                if (root->left) {
                    if (prev) prev->next = root->left;
                    prev = root->left;
                }
                if (root->right) {
                    if (prev) prev->next = root->right;
                    prev = root->right;
                }
            }
            root = next; // turn to next level
        }
    }
};
