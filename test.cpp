#include "test.hpp"

int main(void)
{

    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(2);
    TreeNode *t3 = new TreeNode(3);
    t1->right = t2;
    t2->left = t3;
    for(auto v:Solution_2().postorderTraversal(t1)){
        std::cout << v << "\n";
    }
    return 0;
}
