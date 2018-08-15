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
    ListNode* Partation(ListNode *l, int m){
        ListNode head(-1);
        head.next = l;
        ListNode *prev = l;
        ListNode *cur = prev->next==nullptr?prev:prev->next;
        for(;cur != nullptr && cur->val < m; prev = cur,cur=cur->next);
        ListNode *prev2 = cur;
        cur = cur->next==nullptr?cur:cur->next;
        for (; cur!=nullptr; prev2 = cur,cur=cur->next) {
            // std::cout << " @@" << cur->val<< "\n";
            if(cur->val < m){
                prev2->next = cur->next;
                cur->next = prev->next;
                prev->next = cur; // 尾插法
                cur = prev2;
            }
        }
        return head.next;
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
    ListNode *Partation(ListNode *head, int m){
        ListNode left_head(-1);   // 头结点
        ListNode right_head(-1);  // 头结点

        auto left_cur = &left_head;
        auto right_cur = &right_head;

        for (ListNode *cur=head; cur; cur=cur->next) {
            if(cur->val < m){
                left_cur->next = cur;
                left_cur = cur;
            }else{
                right_cur->next = cur;
                right_cur = cur;
            }
        }
        // visit(left_head.next);
        // visit(right_head.next);
        left_cur->next = right_head.next;
        right_cur->next = nullptr;
        return left_head.next;
    }
};
