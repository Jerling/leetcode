#include <iostream>
#include <algorithm>
#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Path Sum II
// 时间复杂度O(n)，空间复杂度O(logn)
class Solution {
public:
    std::vector<std::vector<int> > pathSum(TreeNode *root, int sum) {
        std::vector<std::vector<int> > result;
        std::vector<int> cur; // 中间结果
        pathSum(root, sum, cur, result);
        return result;
    }
private:
    void pathSum(TreeNode *root, int gap, std::vector<int> &cur,
                 std::vector<std::vector<int> > &result) {
        if (root == nullptr) return;

        cur.push_back(root->val);

        if (root->left == nullptr && root->right == nullptr) { // leaf
            if (gap == root->val)
                result.push_back(cur);
        }
        pathSum(root->left, gap - root->val, cur, result);
        pathSum(root->right, gap - root->val, cur, result);

        cur.pop_back();
    }
};
