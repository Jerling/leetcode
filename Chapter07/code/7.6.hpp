#include <iostream>
#include <algorithm>
#include <vector>

auto print = [](auto a){std::cout << a << " ";};

class MySolution
{
public:
    bool search_a_2D_2(std::vector<std::vector<int> > mat, int target) {
        std::size_t m = mat.size();
        std::size_t n = mat[0].size();
        std::size_t i = 0, j = n - 1;
        while(i < m && j >=0) {
            if (mat[i][j] == target) return true;
            if (mat[i][j] < target) i++;
            else j--;
        }
        return false;
    }
};
