#include <iostream>
#include <algorithm>
#include <vector>


auto print = [](auto a){std::cout << a << " ";};

class MySolution_1
{
public:
    int search_insert_position(const std::vector<int> & nums, int target){
        auto it_pos = std::find(nums.begin(), nums.end(), target);
        return it_pos != nums.end() ? std::distance(nums.begin(), it_pos) + 1 : 0;
    }
};

class MySolution_2
{
public:
    int search_insert_position(const std::vector<int>& nums, int target){
        auto it_pos = std::lower_bound(nums.begin(), nums.end(), target);
        return it_pos != nums.end() ? std::distance(nums.begin(), it_pos) + 1: 0;
    }
};

class Solution
{
public:
    int search_insert_position(const std::vector<int>& nums, int target){
        auto it_pos = lower_bound(nums.begin(), nums.end(), target);
        return it_pos != nums.end() ? std::distance(nums.begin(), it_pos) + 1: 0;
    }
private:
    template<typename forwardIterator>
    forwardIterator lower_bound(forwardIterator first, forwardIterator last, int target){
        while(first != last){
            auto mid = next(first, distance(first, last) / 2);
            if(*mid == target) return mid;
            else if(*mid < target) first = ++mid;
            else last = mid;
        }
        return first;
    }
};
