#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

void visit(auto A){
    for(auto i : A){
        for(auto j : i)
            std::cout << j << " ";
        std::cout << "\n";
    }
}
void visit(std::vector<int> A){
    for(auto i : A){
        std::cout << "# " << i << " ";
    }
    std::cout << "\n";
}
/*
  自己的思路：
  先转置，再左右调换
 * */
class mySolution{
public:
    void RotateImage(std::vector<std::vector<int> > &vec){
        transpose(vec);
        swapcols(vec);
    }
private:
    template<typename T>
    void transpose(std::vector<std::vector<T> >& vec){
        const int length = vec.size();
        for (int i=0; i<length; i++) {
            for (int j=i; j<length; j++) {
                std::swap(vec[i][j], vec[j][i]);
            }
        }
    }
    template<typename T>
    void swapcols(std::vector<std::vector<T> > &vec){
        int end = vec.size();
        for (int it = 0;it < end; ++it) {
            // visit(vec[it]);
            reverse(vec[it].begin(), vec[it].end());
            // visit(vec[it]);
        }
    }
};

/*
  分析：
  沿着副对角线翻转一次，然后沿着水平中线翻转一次。
  该方法和自己的思路一样
  代码1
   T: n^2 S:1
*/

class Solution_1 {
public:
    void RotateImage(std::vector<std::vector<int> > & matrix){
        const int n = matrix.size();
        for (int i=0; i<n; i++) {      // 沿着副对角线翻转一次
            for (int j=0; j<n-i; j++) {
                std::swap(matrix[i][j],matrix[n-1-j][n-1-i]);
            }
        }
        for (int i=0; i<n/2; i++) {      // 沿着水平中线反转
            for (int j=0; j<n; j++) {
                std::swap(matrix[i][j], matrix[n-1-i][j]);
            }
        }
    }
};

class Solution_2 {
public:
    void RotateImage(std::vector<std::vector<int> > & matrix){
        const int n = matrix.size();
        for (int i=0; i<n/2; i++) {      // 沿着水平中线反转
            for (int j=0; j<n; j++) {
                std::swap(matrix[i][j], matrix[n-1-i][j]);
            }
        }
        for (int i=0; i<n; i++) {      // 沿着主对角线翻转一次
            for (int j=i+1; j<n; j++) {
                std::swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};
