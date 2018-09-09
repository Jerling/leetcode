#include "test.hpp"

int main(void)
{

    std::vector<int> preorder;
    for (int i=1; i<4; ++i) preorder.push_back(i);
    std::vector<int> inorder = preorder;
    std::swap(inorder[0], inorder[1]);
    std::cout << preorder[0] << " " << inorder[0] << "\n";
    TreeNode *root =  Solution().buildTree(preorder, inorder);
    std::cout << root->left->val << std::endl;

    return 0;
}
