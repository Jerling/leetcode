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

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

// 时间复杂度O(n), 空间复杂度O(n)
class MySolution
{
public:
    TreeLinkNode* nextRightNodes(TreeLinkNode* root){
        if(!root) return nullptr;
        std::queue<TreeLinkNode*> q;
        q.push(root);
        size_t level = q.size();
        while(!q.empty()){
            for(size_t i=0; i<level-1; i++){
                TreeLinkNode* tmp = q.front();q.pop();
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
                TreeLinkNode* next = q.front();
                tmp->next = next;
            }
            TreeLinkNode* tail = q.front();q.pop();
            if(tail->left) q.push(tail->left);
            if(tail->right) q.push(tail->right);
            tail->next = nullptr;
            level = q.size();
        }
        return root;
    }
};

// Populating Next Right Pointers in Each Node
// 时间复杂度O(n)，空间复杂度O(logn)
class Solution {
public:
    void connect(TreeLinkNode *root) {
        connect(root, NULL);
    }
private:
    void connect(TreeLinkNode *root, TreeLinkNode *sibling) {
        if (root == nullptr)
            return;
        else
            root->next = sibling;

        connect(root->left, root->right);
        if (sibling)
            connect(root->right, sibling->left);
        else
            connect(root->right, nullptr);
    }
};
