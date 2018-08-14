#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

void visit(auto vec){
    for(auto i : vec)
        std::cout << i << " ";
    std::cout << "\n";
}
/*
  分析:
  加1.考虑是否需要进位
  T: n, S: 1
*/
class mySolution
{
public:
    std::vector<int> PlusOne(std::vector<int> & digits, int c=1){
        auto rfirst = std::reverse_iterator<std::vector<int>::iterator>(digits.end());
        // 逆向访问
        auto rend = std::reverse_iterator<std::vector<int>::iterator>(digits.begin());
        auto jinwei = c;
        while(rfirst != rend){
            *rfirst += jinwei;
            if (*rfirst >= 10) {
                *rfirst -= 10;
                jinwei = 1;
            }else{
                jinwei = 0;
            }
            rfirst++;
        }
        if(jinwei) // 判断最后一位是否进位
            digits.insert(digits.begin(),1);
        return digits;
    }
};

/*
  T: n, S: 1
*/
class Solution_1
{
public:
    std::vector<int> PlusOne(std::vector<int> &digits){
        add(digits, 1);
        return digits;
    }

private:
    void add(std::vector<int> &digits, int digit){
        int c = digit;
        for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
            *it += c;
            c = *it / 10;
            *it %= 10;
        }
        if(c)
            digits.insert(digits.begin(),1);
    }
};

/*
  这种解法使用lambda表达式
  T: n, S: 1
*/
class Solution_2 {
public:
    std::vector<int> plusOne(std::vector<int> &digits) {
        add(digits, 1);
        return digits;
    }
private:
// 0 <= digit <= 9
    void add(std::vector<int> &digits, int digit) {
        int c = digit; // carry,进位
        for_each(digits.rbegin(), digits.rend(), [&c](int &d){
            d += c;
            c = d / 10;
            d %= 10;
        });
        if (c > 0) digits.insert(digits.begin(), 1);
    }
}
