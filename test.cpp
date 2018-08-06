#include <iostream>

int main(void)
{
  float a = 1.0005;
  float b = 1.0004;
  if (a == b) {
    std::cout << true << std::endl;
  } else {
    std::cout << false << std::endl;
  }
  return 0;
}
