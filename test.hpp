#include <iostream>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <cmath>
#include <limits.h>

/*
  分析：
  从后往前读，用ascll相减得到int值
*/
class MySolution
{
public:
    int atoi(const std::string str){
        auto end = str.end();
        while(!isdigit(*end)) std::cout<<*end,end=prev(end);
        auto begin = str.begin();
        while(!isdigit(*begin) || *end!='-') begin=next(begin);
        int n = 0, result = 0, tmp;
        while(begin != end){
            tmp = std::pow(10, n) * int(*end - '0');
            if(*begin == '-' && INT_MAX - result < tmp) return 0;
            if(INT_MAX - result <= tmp) return 0;
            result += tmp;
            end=prev(end);
        }
        if(*begin == '-') return 0-result;
        tmp = std::pow(10, n) * int(*end - '0');
        if(INT_MAX - result <= tmp) return 0;
        result += tmp;
        return result;
    }
};
