#include "test.hpp"

int main(void)
{

    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(2);
    TreeNode *t3 = new TreeNode(3);
    TreeNode *t4 = new TreeNode(4);
    TreeNode *t5 = new TreeNode(5);
    t2->left = t1;
    t2->right = t3;
    t3->left = t4;
    t1->left = t5;
    return 0;
}
