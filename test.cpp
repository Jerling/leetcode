#include <iostream>
#include <vector>
#include "test.hpp"

int main(void)
{
    std::vector<int> A1 = {2,4,3};
    std::vector<int> A2 = {5,6,4,5};
    ListNode *l1 = creatList(A1);
    ListNode *l2 = creatList(A2);
    visit(l1);
    visit(l2);
    // ListNode* result = mySolution().ReverseLinkedList2(l2,2,4);
    ListNode* result = Solution_1().ReverseLinkedList2(l2,2,4);
    visit(result);
    return 0;
}
