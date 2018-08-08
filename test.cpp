#include <iostream>
#include <vector>
#include "test.hpp"

int main(void)
{
  std::vector<int> A = {1, 1, 2,2,2,5,7,8,8,8,8,99};
  // std::cout << Solution_1().removeDuplicates(A) << std::endl;
  // std::cout << mySolution().removeDuplicates(A) << std::endl;
  // std::cout << Solution_2().removeDuplicates(A) << std::endl;
  // std::cout << Solution_3().removeDuplicates(A) << std::endl;
  // std::cout << mySolutio_mn().removeDuplicates_2(A) << std::endl;
  // std::cout << Solution_1().removeDuplicates_2(A) << std::endl;
  std::cout << Solution_2().removeDuplicates_2(A) << std::endl;

  for(auto &i : A)
    std::cout << i << " ";
  std::cout << std::endl;
  return 0;
}
