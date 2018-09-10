#include "test.hpp"

int main(void)
{

    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(2);
    TreeNode *t3 = new TreeNode(3);
    t2->left = t1;
    t2->right = t3;

    std::cout << MySolution().isBST(t1) << "\n";
    return 0;
}
