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
    ListNode *RemoveNthNodeFromEndofList(ListNode *l, int n){
        if (!l || n <= 0) return l;
        ListNode *tail = l;
        int i = 0;
        for ( ; i<n && tail; ++i, tail=tail->next);
        if (i < n) return l;
        ListNode *prev = l;
        for ( ; tail->next; tail=tail->next, prev=prev->next);
        ListNode *tmp = prev->next;
        prev->next = tmp->next;
        delete tmp;
        return l;
    }
};

/*
  分析：
  先让指针p先走n步，再一起走
*/
// Remove Nth Node From End of List
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *p = &dummy, *q = &dummy;

        for (int i = 0; i < n; i++)  // q先走n步
            q = q->next;

        while(q->next != nullptr) { // 一起走
            p = p->next;
            q = q->next;
        }
        ListNode *tmp = p->next;
        p->next = p->next->next;
        delete tmp;
        return dummy.next;
    }
};
