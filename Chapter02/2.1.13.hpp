#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

/*
  使用NextPermutationSequence()
*/
// LeetCode, Permutation Sequence
// 使用 next_permutation()，TLE
class Solution_1 {
public:
    string getPermutation(int n, int k) {
        string s(n, '0');
        for (int i = 0; i < n; ++i)
            s[i] += i+1;
        for (int i = 0; i < k-1; ++i)
            next_permutation(s.begin(), s.end());
        return s;
    }
    template<typename BidiIt>
    bool next_permutation(BidiIt first, BidiIt last) {
        // Get a reversed range to simplify reversed traversal.
        const auto rfirst = reverse_iterator<BidiIt>(last);
        const auto rlast = reverse_iterator<BidiIt>(first);
        // Begin from the second last element to the first element.
        auto pivot = next(rfirst);
        // Find `pivot`, which is the first element that is no less than its
        // successor. `Prev` is used since `pivort` is a `reversed_iterator`.
        while (pivot != rlast && *pivot >= *prev(pivot))
            ++pivot;
        // No such elemenet found, current sequence is already the largest
        // permutation, then rearrange to the first permutation and return false.
        if (pivot == rlast) {
            reverse(rfirst, rlast);
            return false;
        }
        // Scan from right to left, find the first element that is greater than
        // `pivot`.
        auto change = find_if(rfirst, pivot, bind1st(less<int>(), *pivot));
        swap(*change, *pivot);
        reverse(rfirst, pivot);
        return true;
    }
};

/*
  分析：
  1）简单暴力解决：如自己的思路，调用 k-1 次NextPermutation()
  1) 利用康托编码思想，假设有 n 个不重要的元素，第 k 个排序是 a1,a2,a3,...,an,那么a1是哪个位置呢？
  把 a1 去掉，那么剩下的排列为 a2,a3,...,an,共n-1个元素。共有 (n-1)! 个排列。
  于是就可以知道 : a1 = k/(n-1)!。同理：
  k2 = k%(n-1)! a2 = k2/(n-2)!
  k3 = k%(n-2)! a3 = k3/(n-4)!
  ...
  kn-1 = kn-2%2! an-1 = kn-1/1!
  an = 0

  代码1
   T: n S:1
*/

class Solution_2 {
public:
    std::string PermutaionSequence(int n, int k) {
        std::string s(n, '0');
        std::string result;
        for (int i = 0; i < n; ++i)
            s[i] += i + 1;
        return kth_permutation(s, k);
    }
private:
    int factorial(int n) {
        // n!
        int result = 1;
        for (int i = 1; i <= n; ++i)
            result *= i;
        return result;
    }
// seq 已经排好序
    template<typename Sequence>
    Sequence kth_permutation(const Sequence &seq, int k) {
        const int n = seq.size();
        Sequence S(seq);
        Sequence result;
        int base = factorial(n - 1);
        --k; // 康托编码从0开始
        for (int i = n - 1; i > 0; k %= base, base /= i, --i) {
            auto a = next(S.begin(), k / base);
            result.push_back(*a);
            S.erase(a);
        }
        result.push_back(S[0]); // 最后一个
        return result;
    }
};
