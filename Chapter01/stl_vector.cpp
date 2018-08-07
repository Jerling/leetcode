#include <iostream>
#include <vector>

int main(void)
{
  const unsigned short row_num = 10;
  const unsigned short col_num = 10;

  // 使用动态分配方式创建数组
  int** ary = new int*[row_num];
  for (int i = 0; i < row_num; i++) {
    ary[i] = new int[col_num];
  }

  // 使用vector创建二维数组
  std::vector<std::vector<int> > ary_v(row_num, std::vector<int> (col_num, 0));

  // 下面是官网关于 reserve 的例子
  std::vector<int>::size_type sz;

  std::vector<int> foo;
  sz = foo.capacity();
  std::cout << "making foo grow:\n";
  for (int i=0; i<100; ++i) {
    foo.push_back(i);
    if (sz!=foo.capacity()) {
      sz = foo.capacity();
      std::cout << "capacity changed: " << sz << '\n';
    }
  }

  std::vector<int> bar;
  sz = bar.capacity();
  bar.reserve(100);   // this is the only difference with foo above
  std::cout << "making bar grow:\n";
  for (int i=0; i<100; ++i) {
    bar.push_back(i);
    if (sz!=bar.capacity()) {
      sz = bar.capacity();
      std::cout << "capacity changed: " << sz << '\n';
    }
  }

  return 0;
}
