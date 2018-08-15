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
    ListNode* RemoveDulicates2(ListNode *l){
        if(!l || !(l->next)) return l;
        ListNode head(-1);
        head.next = l;
        auto pprev = l;
        auto prev = pprev->next;
        for (auto cur=prev->next; cur; cur=cur==nullptr?cur:cur->next) {
            if(prev->val == cur->val){
                pprev->next = cur->next;
                delete cur;
                delete prev;
                prev = pprev->next;
                cur = prev;
            }else{
                pprev=prev;
                prev = cur;
            }
        }
        if(prev && prev->val == pprev->val)
            return nullptr;
        return head.next;
    }
};

/*
  分析：

*/
/*
  递归
  T: n, S: 1
*/
class Solution_1
{
public:
    ListNode *RemoveDulicates2(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *p = head->next;
        if (head->val == p->val) {
            while (p && head->val == p->val) {
                ListNode *tmp = p;
                p = p->next;
                delete tmp;
            }
            delete head;
            return RemoveDulicates2(p);
        } else {
            head->next = RemoveDulicates2(head->next);
            return head;
        }
    }
};
/*
  迭代版
*/
class Solution_2 {
public:
    ListNode *RemoveDulicates2(ListNode *head) {
        if (head == nullptr) return head;
        ListNode dummy(INT_MIN); // 头结点
        dummy.next = head;
        ListNode *prev = &dummy, *cur = head;
        while (cur != nullptr) {
            bool duplicated = false;
            while (cur->next != nullptr && cur->val == cur->next->val) {
                duplicated = true;
                ListNode *temp = cur;
                cur = cur->next;
                delete temp;
            }
            if (duplicated) { // 删除重复的最后一个元素
                ListNode *temp = cur;
                cur = cur->next;
                delete temp;
                continue;
            }
            prev->next = cur;
            prev = prev->next;
            cur = cur->next;
        }
        prev->next = cur;
        return dummy.next;
    }
};
