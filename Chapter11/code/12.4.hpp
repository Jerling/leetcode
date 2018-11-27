#include <iostream>
#include <vector>


// Best Time to Buy and Sell Stock II
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    int maxProfit(std::vector<int> &prices) {
        int sum = 0;
        for (size_t i = 1; i < prices.size(); i++) {
            int diff = prices[i] - prices[i - 1];
            if (diff > 0) sum += diff;
        }
        return sum;
    }
};
