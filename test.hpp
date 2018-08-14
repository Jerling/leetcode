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
  设 f(n)表示爬方法数，第 n 阶有两种走法：
  1) 从 n-1 前进一步：f(n-1)
  2) 从 n-1 前进二步：f(n-2)
  那么：f(n) = f(n-1) + f(n-1)
  方法：
  1) 递归(慢)；
  2) 迭代；
  3) 数学公式: 斐波那契数列[通项公式](https://baike.baidu.com/item/%E6%96%90%E6%B3%A2%E9%82%A3%E5%A5%91%E6%95%B0%E5%88%97)
*/
/*
  迭代：
  T: n, S: 1
*/
class Solution_1
{
public:
    int climbStairs(int n){
        int prev = 0, cur = 1;
        for (int i=0; i<n; i++) {
            int tmp = cur;
            cur += prev;
            prev = tmp;
        }
        return cur;
    }
};

/*
  数学公式:
  T: n, S: 1
*/
class Solution_2
{
public:
    int climbStairs(int n=5){
        const double s = sqrt(5);
        return floor((pow((1+s)/2, n+1) + pow((1-s)/2, n+1))/s + 0.5);
        // floor(d) 返回不超过d的最大整数
        // ceil(d) 返回不小于d的最小整数
    }
};
