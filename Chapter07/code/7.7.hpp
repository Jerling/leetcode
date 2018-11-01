#include <iostream>
#include <algorithm>
#include <vector>

auto print = [](auto a){std::cout << a << " ";};

class MySolution_1
{
public:
    int min_element(std::vector<int> nums) {
        auto it = std::adjacent_find(nums.begin(), nums.end(),
                                     [](auto x, auto y) { return x > y;});
        return *std::next(it);
    }
};

class MySolution_2
{
public:
    int min_element(std::vector<int> nums) {
        std::size_t first = 0, last = nums.size() - 1;
        while (first < last) {
            std::size_t mid = first + ((last - first) >> 1);
            if (nums[last] > nums[mid]) last = mid;
            else first = ++mid;
        }
        return nums[first];
    }
};
