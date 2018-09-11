#include <iostream>
#include <algorithm>
#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr){}
};

// Convert Sorted List to Binary Search Tree
// 二分法，类似于 Convert Sorted Array to Binary Search Tree，
// 自顶向下，时间复杂度O(nlogn)，空间复杂度O(logn)
class Solution_1 {
public:
    TreeNode* sortedListToBST (ListNode* head) {
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return new TreeNode(head->val);

        ListNode *mid = cutAtMiddle(head);

        TreeNode *root = new TreeNode(mid->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);

        return root;
    }

    ListNode* cutAtMiddle(ListNode *head) {
        if(head == nullptr) return nullptr;

        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *prev_slow = head;

        while(fast != nullptr && fast->next != nullptr){
            prev_slow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev_slow->next = nullptr;
        return slow;
    }
};
// Convert Sorted List to Binary Search Tree
// bottom-up，时间复杂度O(n)，空间复杂度O(logn)
class Solution_2 {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        int len = 0;
        ListNode *p = head;
        while (p) {
            len++;
            p = p->next;
        }
        return sortedListToBST(head, 0, len - 1);
    }
private:
    TreeNode* sortedListToBST(ListNode*& list, int start, int end) {
        if (start > end) return nullptr;

        int mid = start + (end - start) / 2;
        TreeNode *leftChild = sortedListToBST(list, start, mid - 1);
        TreeNode *parent = new TreeNode(list->val);
        parent->left = leftChild;
        list = list->next;
        parent->right = sortedListToBST(list, mid + 1, end);
        return parent;
    }
};
