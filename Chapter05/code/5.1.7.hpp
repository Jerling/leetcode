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
class MySolution_1
{
public:
    TreeNode * InvertBinaryTree(TreeNode *root){
        invert(root);
        return root;
    }
private:
    void invert(TreeNode *root){
        if(!root) return;
        std::swap(root->left, root->right);
        invert(root->left);
        invert(root->right);
    }
};

class MySolution_2
{
public:
    TreeNode *InvertBinaryTree(TreeNode *root){
        std::queue<TreeNode *> tmp;
        tmp.push(root);
        while(!tmp.empty()){
            TreeNode *p = tmp.front();
            std::swap(p->left, p->right);
            if(p->left) tmp.push(p->left);
            if(p->right) tmp.push(p->right);
            tmp.pop();
        }
        return root;
    };
};
