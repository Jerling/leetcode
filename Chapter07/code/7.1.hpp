#include <iostream>
#include <algorithm>
#include <vector>


auto print = [](auto a){std::cout << a << " ";};

class MySolution{
public:
    std::vector<int> search_a_range(const std::vector<int>& nums, int target){
        std::vector<int> res;
        int start = 0, end = nums.size() -1;
        int mid;
        while(start < end){
            mid = start + (end - start) / 2;
            if(nums.at(mid) == target){
                int i = 0;
                for(; nums.at(mid-i) == target ; ++i);
                res.push_back(mid-i+1);
                for(i=0; nums.at(mid+i) == target; ++i);
                res.push_back(mid+i-1);
                return res;
            }
            else if(nums.at(mid) > target) end = mid-1;
            else start = mid+1;
        }
        res = {-1, -1};
        return res;
    }
};

// Search for a Range
// 重新实现 lower_bound 和 upper_bound
// 时间复杂度O(logn)，空间复杂度O(1)
class Solution {
public:
    std::vector<int> searchRange (std::vector<int>& nums, int target) {
        auto lower = lower_bound(nums.begin(), nums.end(), target);
        auto uppper = upper_bound(lower, nums.end(), target);

        if (lower == nums.end() || *lower != target)
            return std::vector<int> { -1, -1 };
        else
            return std::vector<int> {distance(nums.begin(), lower), distance(nums.begin(), prev(uppper))};
    }

    template<typename ForwardIterator, typename T>
    ForwardIterator lower_bound (ForwardIterator first,
            ForwardIterator last, T value) {
        while (first != last) {
            auto mid = next(first, distance(first, last) / 2);

            if (value > *mid) first = ++mid;
            else              last = mid;
        }

        return first;
    }

    template<typename ForwardIterator, typename T>
    ForwardIterator upper_bound (ForwardIterator first,
            ForwardIterator last, T value) {
        while (first != last) {
            auto mid = next(first, distance (first, last) / 2);

            if (value >= *mid) first = ++mid;  // 与 lower_bound 仅此不同
            else               last = mid;
        }

        return first;
    }
};
