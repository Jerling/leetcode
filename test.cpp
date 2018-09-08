#include "test.hpp"

int main(void)
{

    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(2);
    TreeNode *t3 = new TreeNode(3);
    t1->left = t2;
    t1->right = t3;

    std::cout<<t1->right->val;
    MySolution().FlattenBinaryTree2LinkedList(t1);
    std::cout<<t2->right->val;

    return 0;
}
