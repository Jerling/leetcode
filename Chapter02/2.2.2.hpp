#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

void visit(auto var){
    while(var){
        std::cout << var->val << " ";
        var = var->next;
    }
    std::cout << "\n";
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
  Make mistake when look up question...
  T: n, S: 1
*/
class mySolution
{
public:
    ListNode* ReverseLinkedList2(ListNode *l1, int m, int n){
        ListNode *pm=l1,*pn=l1;
        int count = 1;
        for (ListNode*p = l1; p != nullptr; p = p==nullptr?nullptr:p->next,count++) {
            if(count < m){
                pm = pm->next; // ptr of position m
            }
            if(count < n){
                pn = pn->next;  // ptr of position m
            }
            if(count == n){
                std::swap(pm->val,pn->val); // exchane val of position m and position n
                return l1;
            }
        }
    }
};

/*
  分析：
  
*/
/*
  迭代：
  T: n+m, S: 1
*/
class Solution_1
{
public:
    ListNode *ReverseLinkedList2(ListNode *head, int m, int n){
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *prev = &dummy;
        for(int i=0; i< m-1; ++i)
            prev = prev->next;
        ListNode* const head2 = prev;
        prev = head2->next;
        ListNode *cur = prev->next;
        for (int i=m; i<n; i++) {
            prev->next = cur->next;
            cur->next = head2->next;
            head2->next = cur;       // insert on front
            cur = prev->next;
        }
        return dummy.next;
    }
};
