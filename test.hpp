#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

// Largest Rectangle in Histogram
// 时间复杂度O(n)，空间复杂度O(n)
class Solution {
public:
    int largestRectangleArea(std::vector<int> &heights) {
        std::stack<int> s;
        heights.push_back(0);
        int result = 0;
        for (size_t i = 0; i < heights.size(); ) {
            if (s.empty() || heights[i] > heights[s.top()])
                s.push(i++);
            else {
                int tmp = s.top();
                s.pop();
                result = max(result,
                             heights[tmp] * (s.empty() ? i : i - s.top() - 1));
            }
        }
        return result;
    }
private:
    int max(int a, int b){
        return a > b ? a : b;
    }
};
