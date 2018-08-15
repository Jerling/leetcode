#include <iostream>
#include <vector>
#include "test.hpp"

int main(void)
{
   std::vector<int> A1 = {1,2,2};
    std::vector<int> A2 = {5,6,4,5};
    ListNode *l1 = creatList(A1);
    ListNode *l2 = creatList(A2);
    visit(l1);
    visit(l2);
    visit(Solution_1().RemoveDuplicates(l1));
    return 0;
}
