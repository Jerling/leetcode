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

struct RandomListNode
{
    int label;
    RandomListNode *next,*random;
    RandomListNode(int x):label(x), next(nullptr), random(nullptr){}
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
  分析
*/
// Reorder List
// 时间复杂度O(n)，空间复杂度O(1)
class mySolution {
public:
    ListNode *ReoderList(ListNode *head){
        if(!head || !head->next || !head->next->next) return head;
        for(ListNode *pref=head,*front=pref->next,*pree=front,*end=pree->next;
            end;front=front->next){
            for(;end->next;pree=end,end=end->next);
            pree->next = end->next;
            pref->next = end;
            end->next = front;
            pref = end->next;
            pref = front;
            pree = front->next;
            end = !pree?pree:pree->next;
        }
        return head;
    }
};

/*
分析
题目规定要in-place，也就是说只能使用O(1)的空间。
    可以找到中间节点，断开，把后半截单链表reverse一下，再合并两个单链表
*/
// Reorder List
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    void reorderList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return;

        ListNode *slow = head, *fast = head, *prev = nullptr;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr; // cut at middle

        slow = reverse(slow);

        // merge two lists
        ListNode *curr = head;
        while (curr->next) {
            ListNode *tmp = curr->next;
            curr->next = slow;
            slow = slow->next;
            curr->next->next = tmp;
            curr = tmp;
        }
        curr->next = slow;
    }

    ListNode* reverse(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode *prev = head;
        for (ListNode *curr = head->next, *next = curr->next; curr;
             prev = curr, curr = next, next = next ? next->next : nullptr) {
            curr->next = prev;
        }
        head->next = nullptr;
        return prev;
    }
};
