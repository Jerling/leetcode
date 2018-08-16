#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <string>

void visit(auto var){
    while(var){
        std::cout << var->val << " ";
        var = var->next;
    }
    std::cout << std::endl;
}

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(nullptr){}
};

ListNode* creatList(int n){
    ListNode head(-1);
    ListNode* result = &head;
    for (int i=0; i<n; i++) {
        result->next = new ListNode(i);
        result = result->next;
    }
    return head.next;
}

ListNode* creatList(const std::vector<int> vec){
    ListNode head(-1);
    ListNode* result = &head;
    for_each(vec.begin(), vec.end(), [&result](auto n){result->next = new ListNode(n);result=result->next;});
    return head.next;
}
/*
  分析:
  直接删除
  T: n, S: 1
*/
class mySolution
{
public:
    ListNode *SwapNodesinPairs(ListNode *l){
        if (!l || !l->next) return l;
        ListNode head(-1);head.next = l;
        ListNode *tail = l, *prev = &head, *tmp;
        for ( ; tail; prev=tail, tail=tail->next){
            tmp = tail->next;
            tail->next = tmp->next;
            prev->next = tmp;
            tmp->next = tail;
        }
        return head.next;
    }
};

/*
  分析：
*/
// Swap Nodes in Pairs
// 时间复杂度O(n)，空间复杂度O(1)
class Solution_1 {
public:
    ListNode *swapPairs(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode dummy(-1);
        dummy.next = head;

        for(ListNode *prev = &dummy, *cur = prev->next, *next = cur->next;
            next;
            prev = cur, cur = cur->next, next = cur ? cur->next: nullptr) {
            prev->next = next;
            cur->next = next->next;
            next->next = cur;
        }
        return dummy.next;
    }
};

// 这种方法更简单
// Swap Nodes in Pairs
// 时间复杂度O(n)，空间复杂度O(1)
class Solution_2 {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* p = head;

        while (p && p->next) {
            std::swap(p->val, p->next->val);
            p = p->next->next;
        }

        return head;
    }
};
