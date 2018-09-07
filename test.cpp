#include "test.hpp"

int main(void)
{

    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(2);
    TreeNode *t3 = new TreeNode(2);
    t1->right = t2;
    t2->right = t3;

    std::cout << MySolution().isBalanceBinaryTree(t1) << "\n";

    return 0;
}
