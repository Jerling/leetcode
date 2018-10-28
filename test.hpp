#include <iostream>
#include <algorithm>
#include <vector>

// Sort Colors
// Counting Sort
// 时间复杂度O(n)，空间复杂度O(1)
class Solution_1 {
public:
    void sortColors(std::vector<int>& A) {
        int counts[3] = { 0 }; // 记录每个颜色出现的次数

        for (int i = 0; i < A.size(); i++)
            counts[A[i]]++;

        for (int i = 0, index = 0; i < 3; i++)
            for (int j = 0; j < counts[i]; j++)
                A[index++] = i;
    }
};



// Sort Colors
// 双指针，时间复杂度O(n)，空间复杂度O(1)
class Solution_2 {
public:
    void sortColors(std::vector<int>& A) {
        // 一个是red的index，一个是blue的index，两边往中间走
        int red = 0, blue = A.size() - 1;

        for (int i = 0; i < blue + 1;) {
            if (A[i] == 0)
                swap(A[i++], A[red++]);
            else if (A[i] == 2)
                swap(A[i], A[blue--]);
            else
                i++;
        }
    }
};

// Sort Colors
// 重新实现 partition()
// 时间复杂度O(n)，空间复杂度O(1)
class Solution_3 {
public:
    void sortColors(std::vector<int>& nums) {
        partition(partition(nums.begin(), nums.end(), bind1st(equal_to<int>(), 0)),
                  nums.end(), bind1st(equal_to<int>(), 1));
    }
private:
    template<typename ForwardIterator, typename UnaryPredicate>
    ForwardIterator partition(ForwardIterator first, ForwardIterator last,
                              UnaryPredicate pred) {
        auto pos = first;

        for (; first != last; ++first)
            if (pred(*first))
                swap(*first, *pos++);

        return pos;
    }
};
