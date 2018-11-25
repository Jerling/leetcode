# 贪心算法
## 1. Jump Game
```latex
\subsubsection{描述}
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:

\code{A = [2,3,1,1,4]}, return true.

\code{A = [3,2,1,0,4]}, return false.


\subsubsection{分析}
由于每层最多可以跳\fn{A[i]}步，也可以跳0或1步，因此如果能到达最高层，则说明每一层都可以到达。有了这个条件，说明可以用贪心法。

思路一：正向，从0出发，一层一层网上跳，看最后能不能超过最高层，能超过，说明能到达，否则不能到达。

思路二：逆向，从最高层下楼梯，一层一层下降，看最后能不能下降到第0层。

思路三：如果不敢用贪心，可以用动规，设状态为\fn{f[i]}，表示从第0层出发，走到\fn{A[i]}时剩余的最大步数，则状态转移方程为：
$$
f[i] = max(f[i-1], A[i-1])-1, i > 0
$$
```

