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

class MySolution
{
public:
    TreeNode * createBst(std::vector<int> &sorted){
        return create(begin(sorted), end(sorted));
    }
private:
    template<class T>
    TreeNode* create(T start, T end){
        if(start == end) return nullptr;
        int len = std::distance(start, end);
        T mid = next(start, len/2);
        TreeNode *tmp = new TreeNode(*mid);
        tmp->left = create(start, mid);
        tmp->right = create(next(mid), end);
        return tmp;
    }
};

// Convert Sorted Array to Binary Search Tree
// 二分法，时间复杂度O(n)，空间复杂度O(logn)
class Solution {
public:
    TreeNode* sortedArrayToBST (std::vector<int>& num) {
        return sortedArrayToBST(num.begin(), num.end());
    }

    template<class RandomAccessIterator>
    TreeNode* sortedArrayToBST (RandomAccessIterator first,
                                RandomAccessIterator last) {
        const auto length = distance(first, last);
        if (length > 0){
            RandomAccessIterator mid = next(first, length/2);
            TreeNode *root = new TreeNode(*mid);
            root->left = sortedArrayToBST(first, mid);
            root->right = sortedArrayToBST(mid + 1, last);

            return root;
        }
        return nullptr;
    }
};
