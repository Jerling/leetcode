#include <iostream>
#include <algorithm>
#include <vector>

struct ProfitNode {
  unsigned int day_;
  int price_;
  ProfitNode(unsigned int day, int price):day_(day),price_(price) {}
  bool operator > (const ProfitNode &lr) {
    return day_ > lr.day_ && price_ > lr.price_;
  }
};

class Solution_1
{
public:
  int maxProfit(const std::vector<int> &prices) {
    if (!prices.size()) return 0;
    ProfitNode Min(0, prices[0]);
    ProfitNode Max = Min;
    int res = 0;
    size_t i = 0;
    size_t len = prices.size();
    for (; i<len; ++i) {
      if (Min.price_ > prices[i]) {
        Min.day_ = i;
        Min.price_ = prices[i];
      }
      if (Max.price_ < prices[i]) {
        Max.day_ = i;
        Max.price_ = prices[i];
      }
      if ( Max > Min ) {
        res = std::max(Max.price_-Min.price_, res);
      }
    }
    return res;
  }

private:
};
// Best Time to Buy and Sell Stock
// 时间复杂度O(n)，空间复杂度O(1)
class Solution_2 {
public:
    int maxProfit(std::vector<int> &prices) {
        if (prices.size() < 2) return 0;
        int profit = 0;  // 差价，也就是利润
        int cur_min = prices[0]; // 当前最小

        for (size_t i = 1; i < prices.size(); i++) {
            profit = std::max(profit, prices[i] - cur_min);
            cur_min = std::min(cur_min, prices[i]);
        }
        return profit;
    }
};
