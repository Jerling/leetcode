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
        auto i = vec.end();
        for(; i != vec.begin()+1, --i){
            if (*(i-1) < *i) {
                swap(i-1, i+1);
                break;
            }
        }
        for (auto j = vec.end(); j>i; j--,i++) {
            swap(i,j);
        }
    }
private:
    template<typename T>
    void swap(T t1, T t2){
        auto tmp = t1;
        t1 = t2;
        t2 = tmp;
    }
};

/* 代码1
   T: n S:1
*/
class Solution_1
{
public:
    int removeElement(std::vector<int> &vec, const int target){
        int index = 0;
        for (int i = 0; i < vec.size(); ++i) {
            if (vec[i] != target) {
                vec[index++] = vec[i];
            }
        }
        return index;
    }
};

/* 代码2
   使用remove()
   T: n, S: 1
*/
class Solution_2
{
public:
    int removeElement(std::vector<int> & vec, int target){
        return distance(vec.begin(), remove(vec.begin(), vec.end(), target));;
    }
};
