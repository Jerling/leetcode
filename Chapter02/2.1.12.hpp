#include <iostream>
#include <vector>
#include <algorithm>

/* 分析：https://www.cnblogs.com/houkai/p/3675270.html
   全排序：
   从n个不同元素中任取m（m≤n）个元素，按照一定的顺序排列起来，叫做从n个不同元素中取出m个元素的一个排列。当m=n时所有的排列情况叫全排列。例如n=3，全排序为：123、132、213、231、312、321共6种。
   字典序法：
   对给定的字符集中的字符规定了一个先后关系，在此基础上规定两个全排列的先后是：从左到右逐个比较对应的字符大小。字符集{1,2,3}，较小的数字较先，这样按字典序生成的全排列即：123、132、213、231、312、321。
   现在假设输入全排序中的一串数字，要求得到它在字典序全排列中对应的下一个排列数。比如：输入123输出132，输入12435输出12453。
 * */
class mySolution{
  public:
    void NextPermutation(std::vector<int> &vec){
        int length = vec.size();
        int i;
        if (length <= 1) return;
        for (i = length-2; i > 0; i--) {
            // std::cout << "i = " << vec[i] << std::endl;
            if (vec[i+1] > vec[i]) {
                break;
            }
        }
        if (i == 0) {
            return;
        }
        for(int j=length-1; j>i; j--){
            if(vec[j] > vec[i]){
                std::swap(vec[i], vec[j]);
                break;
            }
        }
        ++i; // 只要转置 i 后边的
        for(int j=length-1; j > i; j--){
            std::swap(vec[i],vec[j]);
        }
    }
};

/* 代码1
   T: n S:1
*/
class Solution_1
{
public:
    void NextPermutation(std::vector<int> &vec){
        next_Permutation(vec.begin(), vec.end());
    }
private:
    template<typename BidiIt>
    bool next_Permutation(BidiIt first, BidiIt last){
        const auto rfirst = std::reverse_iterator<BidiIt>(last);
        // 反向迭代器，便于反方向访问
        const auto rlast = std::reverse_iterator<BidiIt>(first);

        auto pivot = next(rfirst); // 取最后一个数值(因为没有值，所以取前一个)
        while (pivot != rlast && *pivot >= *prev(pivot)) {
            ++pivot;               // 找到第一次出现变小的位置
        }
        if (pivot == rlast) {      // 检查是否到第一个位置
            reverse(rfirst, rlast);
        }
        // 找到从尾部rfirst开始找第一次出现变大的位置
        std::cout << *pivot << std::endl;
        auto change = find_if(rfirst, pivot, std::bind1st(std::less<int>(), *pivot));
        // bind1st(const Fn2& Func,const Ty& left);  //1st指:传进来的参数应该放左边，也就是第1名
        // bind2nd(const Fn2& Func,const Ty& right); //2nd指:传进来的参数应该放右边,也就是第2名
        std::cout << *change<< std::endl;
        std::swap(*change, *pivot);
        reverse(rfirst, pivot);  // 反转后边的部分

        return true;
    }
};
