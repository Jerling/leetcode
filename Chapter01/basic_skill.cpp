#include <iostream>
#include <cmath>

int main(void)
{
  float a = 1.0005;
  float b = 1.0005;

  std::cout << "a == b :" << std::endl;
  if (a == b) {
    std::cout << true << std::endl;
  } else {
    std::cout << false << std::endl;
  }

  std::cout << "fabsf(a-b) : " << std::endl;
  if (fabsf(a - b) < 1e-9) {
    std::cout << true << std::endl;
  } else {
    std::cout << false << std::endl;
  }

  int c = 3;
  if (c % 2 != 0) {
    std::cout << c << " 是奇数" << std::endl;
  }
  else {
   std::cout << c << " 不是奇数" << std::endl;
  }

  std::string str1 =  "askdjfefs";
  int arr[256] = {0};
  for(auto &i : str1){
    unsigned char c = i;
    arr[c] +=1;
  }
  for (int i = 0; i < 256; i++) {
    if (arr[i] != 0) {
      std::cout << char(i) << " : " << arr[i] << std::endl;
    }
  }
  return 0;
}
