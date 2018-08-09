#include <iostream>
#include <vector>
#include "test.hpp"

int main(void)
{
  std::vector<int> A1 = {5,6,7,8,9,10,11,15};
  std::vector<int> A2 = {0,1,2,3,4};
  // std::cout << Solution_1().removeDuplicates(A) << std::endl;
  // std::cout << mySolution().removeDuplicates(A) << std::endl;
  // std::cout << Solution_2().removeDuplicates(A) << std::endl;
  // std::cout << Solution_3().removeDuplicates(A) << std::endl;
  // std::cout << mySolutio_mn().removeDuplicates_2(A) << std::endl;
  // std::cout << Solution_1().removeDuplicates_2(A) << std::endl;
  // std::cout << Solution_1().serchInRSA(A, 2) << std::endl;
  std::cout << mySolution().Findmedian(A1, A2) << std::endl;
  std::cout << Solution_1().Findmedian(A1, A2) << std::endl;

  return 0;
}
