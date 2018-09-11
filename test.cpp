#include "test.hpp"

int main(void)
{

    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(2);
    TreeNode *t3 = new TreeNode(3);
    t2->left = t1;
    t2->right = t3;

    std::vector<int> v;
    for(int i=0; i<10; v.push_back(i), ++i);

    TreeNode *root = Solution().sortedArrayToBST(v);
    std::cout << root->val << std::endl;
    std::cout << root->left->val << std::endl;
    std::cout << root->right->val << std::endl;

    return 0;
}
