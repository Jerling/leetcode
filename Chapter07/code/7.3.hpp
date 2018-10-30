#include <iostream>
#include <algorithm>
#include <vector>


auto print = [](auto a){std::cout << a << " ";};

class MySolution
{
public:
    int search_in_rotated_sorted_array(const std::vector<int>& nums, int target){
        auto first = nums.begin();
        auto last = nums.end();
        while(first != last){
            auto mid = std::next(first, std::distance(first, last) / 2);
            if(target == *mid) return std::distance(nums.begin(), mid);
            else if(*first < *mid){
                if(target > *first && target < *mid) last = mid;
                else first = ++mid;
            }else{
                if(target > *mid && target <= *(last - 1)) first = ++mid;
                else last = mid;
            }
        }
        return -1;
    }
};

// Search in Rotated Sorted Array
// Time Complexity: O(log n)，Space Complexity: O(1)
class Solution {
public:
    int search(const std::vector<int>& nums, int target) {
        int first = 0, last = nums.size();
        while (first != last) {
            const int mid = first  + (last - first) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[first] <= nums[mid]) {
                if (nums[first] <= target && target < nums[mid])
                    last = mid;
                else
                    first = mid + 1;
            } else {
                if (nums[mid] < target && target <= nums[last-1])
                    first = mid + 1;
                else
                    last = mid;
            }
        }
        return -1;
    }
};
