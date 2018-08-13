#include <iostream>
#include <vector>
#include "test.hpp"

int main(void)
{
    std::vector<std::vector<int> > A = {{1,2,3},{4,5,6},{7,8,9}};
    // visit(A);
    mySolution().RotateImage(A);
    visit(A);

    // auto vec = mySolution().PermutaionSequence(3,4);
    // for (auto it = vec.begin(); it != vec.end(); ++it) {
    //   std::cout << *it << " ";
    // }
    // std::cout << Solution_1().PermutaionSequence(3,4);
    // mySolution().NextPermutation(A1);
    // // Solution_1().NextPermutation(A1);
    // for (auto i = A1.begin(); i != A1.end(); ++i) {
    //     std::cout << *i << std::endl;
    // }

    // std::cout << mySolution().removeElement(A1, 1) << std::endl;
    // std::cout << Solution_1().removeElement(A1, 1) << std::endl;
    // std::cout << Solution_2().removeElement(A1, 1) << std::endl;
    // std::cout << Solution_1().threeSumClosest(A1) << std::endl;
    // std::cout << mySolution().threeSumClosest(A2) << std::endl;
    // for(auto &i : Solution_1().threeSum(A1))
    // std::cout << i << " ";
    // std::cout << std::endl;
    // for(auto &i : mySolution().threeSum(A1))
    // std::cout << i << " ";
    // std::cout << mySolution().LongestConsecutiveSequence(A2) << std::endl;
    // std::cout << Solution_1().LongestConsecutiveSequence(A2) << std::endl;
    // std::cout << Solution_2().LongestConsecutiveSequence(A2) << std::endl;
    // std::cout << Solution_1().removeDuplicates(A) << std::endl;
    // std::cout << mySolution().removeDuplicates(A) << std::endl;
    // std::cout << Solution_2().removeDuplicates(A) << std::endl;
    // std::cout << Solution_3().removeDuplicates(A) << std::endl;
    // std::cout << mySolutio_mn().removeDuplicates_2(A) << std::endl;
    // std::cout << Solution_1().removeDuplicates_2(A) << std::endl;
    // std::cout << Solution_1().serchInRSA(A, 2) << std::endl;
    // std::cout << mySolution().Findmedian(A1, A2) << std::endl;
    // std::cout << Solution_1().Findmedian(A1, A2) << std::endl;

    return 0;
}
