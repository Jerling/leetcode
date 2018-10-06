#include "test.hpp"

int main(void)
{
    ListNode* t1 = new ListNode(1);
    ListNode* t2 = new ListNode(5);
    ListNode* t3 = new ListNode(7);
    ListNode* t4 = new ListNode(6);
    ListNode* t5 = new ListNode(8);
    ListNode* t6 = new ListNode(9);
    t1->next = t2;t2->next = t3;
    t4->next = t5;t5->next = t6;
    auto tmp = MySolution().MergeListed(t1, t4);
    while(tmp){
        std::cout << tmp->val << "\n";
        tmp=tmp->next;
    }
    return 0;
}
