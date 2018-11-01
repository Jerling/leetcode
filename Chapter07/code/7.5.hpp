#include <iostream>
#include <algorithm>
#include <vector>


auto print = [](auto a){std::cout << a << " ";};

class MySolution
{
public:
    bool search_a_2D(const std::vector<std::vector<int> > &matrix, int target){
        std::size_t m = matrix.size();
        std::size_t n = matrix[0].size();
        std::size_t start = 0, end = m;
        while(start < end){
            auto mid = start + (end - start) / 2;
            if (matrix[mid][0] == target) return true;
            else if (matrix[mid][0] < target) start = ++mid;
            else end = mid;
        }
        auto tmp = start-1;
        start = 0, end = n;
        while(start < end){
            auto mid = start + (end-start) / 2;
            if (matrix[tmp][mid] == target) return true;
            else if (matrix[tmp][mid] < target) start = ++mid;
            else end = mid;
        }
        return false;
    }
};

// Search a 2D Matrix
// 时间复杂度O(logn)，空间复杂度O(1)
class Solution {
public:
    bool searchMatrix(const std::vector<std::vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        const size_t  m = matrix.size();
        const size_t n = matrix.front().size();

        int first = 0;
        int last = m * n;

        while (first < last) {
            int mid = first + (last - first) / 2;
            int value = matrix[mid / n][mid % n];

            if (value == target)
                return true;
            else if (value < target)
                first = mid + 1;
            else
                last = mid;
        }

        return false;
    }
};
