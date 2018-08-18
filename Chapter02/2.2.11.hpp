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
    result->next = head.next;
    return head.next;
}

/*
  分析：
  题目中没有说不能改变链表的值，把访问过的记为-1
*/
// 时间复杂度O(n)，空间复杂度O(1)
class mySolution {
public:
    bool LinkedListCycle(ListNode *head){
        for(ListNode *p=head; p ; p = p->next){
            if(p->val == -1) return true;
            else p->val = -1;
        }
        return false;
    }
};

// Linked List Cycle
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // 设置两个指针，一个快一个慢
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};
