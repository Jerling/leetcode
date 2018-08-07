# 1. 编程技巧
## 1.1. 基本技巧
- 在判断两个浮点数是否相等时，应使用绝对值fabs(a-b)是否小于某个阈值，如 1e-9。
- 判断整数是否为奇数时，用 x% 2 ！= 0；因为x可能为负数。
- 用char做数组下标统计字符次数时，先强制转换为 `unsigned char`；因为char可能为负。

## 1.2. STL技巧
### 1.2.1. vector和string优先于动态分配的数组
- 性能： `vector`内存分配连续，性能跟原始数组相当
- 动态分配如果用 `new`，后面就要`delete`，否则会出现 bug
- 如果多维数组，只能一个个 `new`

### 1.2.2. 使用reserve 来避免不必要的重新分配
reserve是容器预留空间，但并不真正创建元素对象，在创建对象之前，不能引用容器内的元素，因此当加入新的元素时，需要用push_back()/insert()函数。  
官网参考：[http://www.cplusplus.com/reference/vector/vector/reserve/](http://www.cplusplus.com/reference/vector/vector/reserve/)