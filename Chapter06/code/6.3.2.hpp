#include <iostream>
#include <algorithm>
#include <vector>

class MySolution
{
public:
    int k_th_largest_element(std::vector<int>& vec, int k){
        quick_sort(vec, 0, vec.size()-1, k);
        return vec[vec.size() - k];
    }
private:
    int quick_sort(std::vector<int>& vec, int start, int end, int k){
        if(start < end){
            int mid = partition(vec, start, end);
            if(mid+k == (int) vec.size()) return vec[mid];
            quick_sort(vec, start, mid - 1, k);
            quick_sort(vec, mid + 1, end, k);
        }
    }
    int partition(std::vector<int>& vec, int start, int end){
        auto part = vec[start];
        while(start < end){
            while(vec[end] >= part && start < end){
                --end;
            }
            if(start < end) vec[start++] = vec[end];
            while(vec[start] <= part && start < end){
                ++start;
            }
            if(start < end) vec[--end] = vec[start];
        }
        vec[start] = part;
        return start;
    }
};
