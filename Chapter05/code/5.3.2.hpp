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
// Unique Binary Search Trees II
// 时间复杂度TODO，空间复杂度TODO
class Solution {
public:
    std::vector<TreeNode *> generateTrees(int n) {
        if (n == 0) return std::vector<TreeNode*>();
        return generate(1, n);
    }
private:
    std::vector<TreeNode *> generate(int start, int end) {
        std::vector<TreeNode*> subTree;
        if (start > end) {
            subTree.push_back(nullptr);
            return subTree;
        }
        for (int k = start; k <= end; k++) {
            std::vector<TreeNode*> leftSubs = generate(start, k - 1);
            std::vector<TreeNode*> rightSubs = generate(k + 1, end);
            for (auto i : leftSubs) {
                for (auto j : rightSubs) {
                    TreeNode *node = new TreeNode(k);
                    node->left = i;
                    node->right = j;
                    subTree.push_back(node);
                }
            }
        }
        return subTree;
    }
};
