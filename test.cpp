#include "test.hpp"

int main(void)
{

    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(2);
    TreeNode *t3 = new TreeNode(3);
    t1->right = t2;
    t1->left = t3;
    for(auto v:MySolution().BinaryTreePreTraversal(t1)){
        std::cout << v << " ";
    }
    std::cout << std::endl;
    for(auto i:MySolution().BinaryTreePreTraversal(MySolution_2().InvertBinaryTree(t1))){
        std::cout << i << " ";
    }
    return 0;
}
