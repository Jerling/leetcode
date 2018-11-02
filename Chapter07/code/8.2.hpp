#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;


// Subsets II
// 增量构造法，版本1，时间复杂度O(2^n)，空间复杂度O(n)
class Solution_1 {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());  // 必须排序

        vector<vector<int> > result;
        vector<int> path;

        dfs(S, S.begin(), path, result);
        return result;
    }

private:
    static void dfs(const vector<int> &S, vector<int>::iterator start,
                    vector<int> &path, vector<vector<int> > &result) {
        result.push_back(path);

        for (auto i = start; i < S.end(); i++) {
            if (i != start && *i == *(i-1)) continue;
            path.push_back(*i);
            dfs(S, i + 1, path, result);
            path.pop_back();
        }
    }
};

// Subsets II
// 增量构造法，版本2，时间复杂度O(2^n)，空间复杂度O(n)
class Solution_2 {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &nums) {
        vector<vector<int> > result;
        sort(nums.begin(), nums.end()); // 必须排序

        map<int, int> count_map; // 记录每个元素的出现次数
        for (int i : nums) {
            if (count_map.find(i) != count_map.end())
                count_map[i]++;
            else
                count_map[i] = 1;
        }

        // 将map里的pair拷贝到一个vector里
        vector<pair<int, int> > elems;
        for (auto p : count_map) {
            elems.push_back(p);
        }
        sort(elems.begin(), elems.end());
        vector<int> path; // 中间结果

        dfs(elems, 0, path, result);
        return result;
    }

private:
    static void dfs(const vector<pair<int, int> > &elems,
            size_t step, vector<int> &path, vector<vector<int> > &result) {
        if (step == elems.size()) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i <= elems[step].second; i++) {
            for (int j = 0; j < i; ++j) {
                path.push_back(elems[step].first);
            }
            dfs(elems, step + 1, path, result);
            for (int j = 0; j < i; ++j) {
                path.pop_back();
            }
        }
    }
};

// Subsets II
// 位向量法，时间复杂度O(2^n)，空间复杂度O(n)
class Solution_3 {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &nums) {
        vector<vector<int> > result; // 必须排序
        sort(nums.begin(), nums.end());
        // 记录每个元素的出现次数
        map<int, int> count_map;
        for (int i : nums) {
            if (count_map.find(i) != count_map.end())
                count_map[i]++;
            else
                count_map[i] = 1;
        }
        // 将map里的pair拷贝到一个vector里
        vector<pair<int, int> > counters;
        for (auto p : count_map) {
            counters.push_back(p);
        }
        sort(counters.begin(), counters.end());

        // 每个元素选择了多少个
        map<int, int> selected;
        for (auto p : counters) {
            selected[p.first] = 0;
        }

        dfs(nums, counters, selected, 0, result);
        return result;
    }

private:
    static void dfs(const vector<int> &S, const vector<pair<int, int> >& counters,
            map<int, int>& selected, size_t step, vector<vector<int> > &result) {
        if (step == counters.size()) {
            vector<int> subset;
            for (auto p : counters) {
                for (int i = 0; i < selected[p.first]; ++i) {
                    subset.push_back(p.first);
                }
            }
            result.push_back(subset);
            return;
        }

        for (int i = 0; i <= counters[step].second; i++) {
            selected[counters[step].first] = i;
            dfs(S, counters, selected, step + 1, result);
        }
    }
};

// Subsets II
// 增量构造法
// 时间复杂度O(2^n)，空间复杂度O(1)
class Solution_4 {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end()); // 必须排序
        vector<vector<int> > result(1);

        size_t previous_size = 0;
        for (size_t i = 0; i < S.size(); ++i) {
            const size_t size = result.size();
            for (size_t j = 0; j < size; ++j) {
                if (i == 0 || S[i] != S[i-1] || j >= previous_size) {
                    result.push_back(result[j]);
                    result.back().push_back(S[i]);
                }
            }
            previous_size = size;
        }
        return result;
    }
};

// Subsets II
// 二进制法，时间复杂度O(2^n)，空间复杂度O(1)
class Solution_5 {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end()); // 必须排序
        // 用 set 去重，不能用 unordered_set，因为输出要求有序
        set<vector<int> > result;
        const size_t n = S.size();
        vector<int> v;

        for (size_t i = 0; i < 1U << n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                if (i & 1 << j)
                    v.push_back(S[j]);
            }
            result.insert(v);
            v.clear();
        }
        vector<vector<int> > real_result;
        copy(result.begin(), result.end(), back_inserter(real_result));
        return real_result;
    }
};
