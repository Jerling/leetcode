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
    int SumofR2L(TreeLinkNode* root){
        int result=0;
        if(!root) return result;
        int cur=0;
        calculate(root, cur, result, false);
        return result;
    }
private:
    void calculate(TreeLinkNode* root, int &cur, int &re, bool isRight){
        if(!root->left && !root->right){
            cur += root->val;
            re += cur;
            if(isRight)
                cur /= 10;   // 如果便利到右孩子，则直接跳到祖宗节点
            return;
        }
        cur += root->val;
        if(root->left){
            cur *= 10;
            calculate(root->left, cur, re, false);
        }
        cur /= 10;          // 从左孩子跳到右孩子是去掉该节点的值
        if(root->right){
            cur *= 10;
            calculate(root->right, cur, re, true);
        }
    }
};

// Sum root to leaf numbers
// 时间复杂度O(n)，空间复杂度O(logn)
class Solution {
public:
    int sumNumbers(TreeNode *root) {
        return dfs(root, 0);
    }
private:
    int dfs(TreeNode *root, int sum) {
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr)
            return sum * 10 + root->val;

        return dfs(root->left, sum * 10 + root->val) +
            dfs(root->right, sum * 10 + root->val);
    }
};
