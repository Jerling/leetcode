#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <unordered_map>

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
    return head.next;
}

/*
  分析
  为了使查找、插入和删除都有较高的性能，这题的关键是要使用一个双向链表和一个HashMap，因为：
  HashMap保存每个节点的地址，可以基本保证在O(1)时间内查找节点
  双向链表能后在O(1)时间内添加和删除节点，单链表则不行
  具体实现细节：
  越靠近链表头部，表示节点上次访问距离现在时间最短，尾部的节点表示最近访问最少
  访问节点时，如果节点存在，把该节点交换到链表头部，同时更新hash表中该节点的地址
  插入节点时，如果cache的size达到了上限capacity，则删除尾部节点，同时要在hash表中删除对应的项；新节点插入链表头部
*/
/*
  代码：
  使用 c++ 的 std:list 实现，其中有个 splice 方法
*/

// LRU Cache
// 时间复杂度O(logn)，空间复杂度O(n)
class LRUCache{
private:
    struct CacheNode {
        int key;
        int value;
        CacheNode(int k, int v) :key(k), value(v){}
    };
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (cacheMap.find(key) == cacheMap.end()) return -1;

        // 把当前访问的节点移到链表头部，并且更新map中该节点的地址
        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        cacheMap[key] = cacheList.begin();
        return cacheMap[key]->value;
    }

    void set(int key, int value) {
        if (cacheMap.find(key) == cacheMap.end()) {
            if (cacheList.size() == capacity) { //删除链表尾部节点（最少访问的节点）
                cacheMap.erase(cacheList.back().key);
                cacheList.pop_back();
            }
            // 插入新节点到链表头部, 并且在map中增加该节点
            cacheList.push_front(CacheNode(key, value));
            cacheMap[key] = cacheList.begin();
        } else {
            //更新节点的值，把当前访问的节点移到链表头部,并且更新map中该节点的地址
            cacheMap[key]->value = value;
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            cacheMap[key] = cacheList.begin();
        }
    }
private:
    std::list<CacheNode> cacheList; // doubly linked list
    std::unordered_map<int, std::list<CacheNode>::iterator> cacheMap;
    int capacity;
};
