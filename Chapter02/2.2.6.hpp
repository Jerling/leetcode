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
    ListNode *RotateList(ListNode *l, int k){
        if(!l || k < 0)
            return nullptr;
        ListNode head(-1);
        head.next = l;
        ListNode *tail = l;
        int i = 0;
        for(; tail && i<k; ++i,tail=tail->next);
        if (i < k) return l;
        ListNode *prev = l;
        for(; tail->next ; tail=tail->next, prev=prev->next);
        tail->next = l;
        head.next = prev->next;
        prev->next = nullptr;
        return head.next;
    }
};

/*
  分析：

*/
// Remove Rotate List
// 时间复杂度O(n)，空间复杂度O(1)
class Solution_1 {
public:
    ListNode *RotateList(ListNode *head, int k) {
        if (head == nullptr || k == 0) return head;

        int len = 1;
        ListNode* p = head;
        while (p->next != nullptr) { // 求长度
            len++;
            p = p->next;
        }
        k = len - k % len;

        p->next = head; // 首尾相连
        for(int step = 0; step < k; step++) {
            p = p->next;  //接着往后跑
        }
        head = p->next; // 新的首节点
        p->next = nullptr; // 断开环
        return head;
    }
};
