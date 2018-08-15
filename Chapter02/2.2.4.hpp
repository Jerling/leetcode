#include <iostream>
#include <vector>
#include <algorithm>
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
  用尾插法更新
  T: n, S: 1
*/
class mySolution
{
public:
    ListNode *RemoveDuplicates(ListNode *head){
        if(!head) return head;
        auto prev = head;
        for (auto p=prev->next; p ; prev=p, p=p->next) {
            if(prev->val == p->val){
                prev->next = p->next;
                delete p;
                p = prev;
            }
        }
        return head;
    }
};

/*
  分析：

*/
/*
  迭代：
  T: n, S: 1
*/
class Solution_1
{
public:
    ListNode *RemoveDuplicates(ListNode *head) {
        if (!head) return head;
        ListNode dummy(head->val + 1);
        dummy.next = head;
        recur(&dummy, head);
        return dummy.next;
    }
private:
    static void recur(ListNode *prev, ListNode *cur) {
        if (cur == nullptr) return;
        if (prev->val == cur->val) {
            prev->next = cur->next;
            delete cur;
            recur(prev, prev->next);
        } else {
            recur(prev->next, cur->next);
        }
    }
};
