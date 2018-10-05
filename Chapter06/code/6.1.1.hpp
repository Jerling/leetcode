#include <iostream>
#include <algorithm>
#include <vector>

template<typename T>
void printVec(T &V){
    for (auto i:V) {
        std::cout << i  << "\n";
    }
}

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(nullptr){};
};

// 时间复杂度: O(n^2)
// 空间复杂度：O(n)
class MySolution
{
public:
    std::vector<int> InsertionSortList(std::vector<int> &arr){
        std::vector<int> sorted;
        sorted.push_back(arr[0]);
        auto begin = next(arr.begin());
        for(; begin != arr.end(); begin++){
            auto first = sorted.begin();
            for(; first != sorted.end(); first++){
                if(*first > *begin){
                    sorted.insert(first, *begin);
                    break;
                }
            }
            if(first == sorted.end()){
                sorted.push_back(*begin);
            }
        }
        return sorted;
    }
};

// Insertion Sort List
// 时间复杂度O(n^2)，空间复杂度O(1)
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode dummy(INT_MIN);
        //dummy.next = head;

        for (ListNode *cur = head; cur != nullptr;) {
            auto pos = findInsertPos(&dummy, cur->val);
            ListNode *tmp = cur->next;
            cur->next = pos->next;
            pos->next = cur;
            cur = tmp;
        }
        return dummy.next;
    }

    ListNode* findInsertPos(ListNode *head, int x) {
        ListNode *pre = nullptr;
        for (ListNode *cur = head; cur != nullptr && cur->val <= x;
             pre = cur, cur = cur->next)
            ;
        return pre;
    }
};
