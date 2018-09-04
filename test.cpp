#include "test.hpp"

int main(void)
{

    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(2);
    TreeNode *t3 = new TreeNode(3);
    t1->right = t2;
    t1->left = t3;
    for(auto v:Solution_2().levelOrder_2(t1)){
        for(auto i:v){
            std::cout << i << "\n";
        }
    }
    return 0;
}
