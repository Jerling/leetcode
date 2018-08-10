#include <iostream>
#include <vector>
#include "test.hpp"

int main(void)
{
  std::vector<int> A1 = {-1,0,1,2,-3,4};
  std::vector<int> A2 = {100, 4, 200, 1, 3, 2};
  std::cout << Solution_1().threeSumClosest(A1) << std::endl;
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
