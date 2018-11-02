#include <iostream>
#include <algorithm>
#include <vector>

// Subsets
// 增量构造法，深搜，时间复杂度O(2^n)，空间复杂度O(n)
class Solution_1 {
public:
    std::vector<std::vector<int> > subsets(std::vector<int> &S) {
        sort(S.begin(), S.end());  // 输出要求有序
        std::vector<std::vector<int> > result;
        std::vector<int> path;
        subsets(S, path, 0, result);
        return result;
    }

private:
    static void subsets(const std::vector<int> &S, std::vector<int> &path, int step,
                        std::vector<std::vector<int> > &result) {
        if (step == S.size()) {
            result.push_back(path);
            return;
        }
        // 不选S[step]
        subsets(S, path, step + 1, result);
        // 选S[step]
        path.push_back(S[step]);
        subsets(S, path, step + 1, result);
        path.pop_back();
    }
};
// Subsets
// 位向量法，深搜，时间复杂度O(2^n)，空间复杂度O(n)
class Solution_2 {
public:
    std::vector<std::vector<int> > subsets(std::vector<int> &S) {
        sort(S.begin(), S.end());  // 输出要求有序

        std::vector<std::vector<int> > result;
        std::vector<bool> selected(S.size(), false);
        subsets(S, selected, 0, result);
        return result;
    }

private:
    static void subsets(const std::vector<int> &S, std::vector<bool> &selected, int step,
                        std::vector<std::vector<int> > &result) {
        if (step == S.size()) {
            std::vector<int> subset;
            for (int i = 0; i < S.size(); i++) {
                if (selected[i]) subset.push_back(S[i]);
            }
            result.push_back(subset);
            return;
        }
        // 不选S[step]
        selected[step] = false;
        subsets(S, selected, step + 1, result);
        // 选S[step]
        selected[step] = true;
        subsets(S, selected, step + 1, result);
    }
};

// Subsets
// 迭代版，时间复杂度O(2^n)，空间复杂度O(1)
class Solution_3 {
public:
    std::vector<std::vector<int> > subsets(std::vector<int> &S) {
        sort(S.begin(), S.end()); // 输出要求有序
        std::vector<std::vector<int> > result(1);
        for (auto elem : S) {
            result.reserve(result.size() * 2);
            auto half = result.begin() + result.size();
            copy(result.begin(), half, back_inserter(result));
            for_each(half, result.end(), [&elem](decltype(result[0]) &e){
                                             e.push_back(elem);
                                         });
        }
        return result;
    }
};
// Subsets
// 二进制法，时间复杂度O(2^n)，空间复杂度O(1)
class Solution_4 {
public:
    std::vector<std::vector<int> > subsets(std::vector<int> &S) {
        sort(S.begin(), S.end()); // 输出要求有序
        std::vector<std::vector<int> > result;
        const size_t n = S.size();
        std::vector<int> v;

        for (size_t i = 0; i < 1 << n; i++) {
            for (size_t j = 0; j < n; j++) {
                if (i & 1 << j) v.push_back(S[j]);
            }
            result.push_back(v);
            v.clear();
        }
        return result;
    }
};
