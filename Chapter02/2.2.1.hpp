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
  加1.考虑是否需要进位
  T: n, S: 1
*/
class mySolution
{
public:
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2){
        ListNode head(-1);
        ListNode * result = &head;
        int jinwei = 0;
        do{
            result->next = new ListNode((l1->val+l2->val+jinwei)%10);
            jinwei = (l1->val+l2->val)/10;
            l1 = l1->next;
            l2 = l2->next;
            result = result->next;
        }while (l1->next && l2->next);
        // 计算最后一个节点
        // std::cout << l1->val << " " << l2->val << "#\n";
        result->next = new ListNode((l1->val+l2->val+jinwei)%10);
        jinwei = (l1->val+l2->val)/10;
        // visit(head.next);
        if(l1->next != nullptr){
            if(jinwei){
                l1->val += 1;
            }
            result=result->next;
            result->next = l1;
        }
        else if(l2->next != nullptr){
            // std::cout << " ##";
            // visit(l2);
            if(jinwei)
                l2->val += 1;
            result=result->next;
            result->next = l2->next;
            // visit(head.next);
        }else{
            if (jinwei) {
                result = new ListNode(1);
            }
        }
        return head.next;
    }
};

/*
  分析：
  直接相加，为nulptr的设为0
*/
/*
  迭代：
  T: n+m, S: 1
*/
class Solution_1
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head(-1);
        int carry = 0;
        ListNode *prev = &head;
        for(ListNode*p1 = l1, *p2 = l2;
            p1 != nullptr || p2 != nullptr;
            p1 = p1 == nullptr?nullptr : p1->next,p2 = p2 == nullptr?nullptr : p2->next, prev=prev->next){
            const int ai = p1 == nullptr?0:p1->val;
            const int bi = p2 == nullptr?0:p2->val;
            const int value = (ai + bi + carry)%10;
            carry = (ai + bi + carry)/10;
            prev->next = new ListNode(value); // insert on tail
        }
        if(carry){
            prev->next = new ListNode(carry);
        }
        return head.next;
    }
};
