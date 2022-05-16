
#ifndef DIST_H_
#define DIST_H_

#include <cctype>
#include <string>
#include <vector>
#include <array>

// T must provide .size() and access by index.
// Elements of arr_ must be comparable by '==' .
template <typename T>
size_t editDistance(const T &arr1, const T &arr2) {
    std::array<std::vector<size_t>, 2> memo{
        std::vector<size_t>(arr2.size() + 1),
        std::vector<size_t>(arr2.size() + 1)
    };
    for (auto i = 0; i < arr2.size() + 1; ++i)
        memo[0][i] = i;

    for (auto i = 1; i < arr1.size() + 1; ++i) {
        for (auto j = 1; j < arr2.size() + 1; ++j) {
            memo[1][0] = i;
            if (arr1[i - 1] == arr2[j - 1])
                memo[1][j] = memo[0][j - 1];
            else
                memo[1][j] = 1 + std::min(
                        {memo[0][j], memo[0][j-1], memo[1][j - 1]});
        }
        memo[0] = memo[1];
    }

    return *(memo[1].end() - 1);
}

// T must provide access by index.
// Elements of arr_ must be comparable by '==' .
template <typename T>
size_t editDistance(const T &arr1, size_t sz1, const T &arr2, size_t sz2) {
    std::array<std::vector<size_t>, 2> memo{
            std::vector<size_t>(sz2 + 1),
            std::vector<size_t>(sz2 + 1)
    };
    for (auto i = 0; i < sz2 + 1; ++i)
        memo[0][i] = i;

    for (auto i = 1; i < sz1 + 1; ++i) {
        for (auto j = 1; j < sz2 + 1; ++j) {
            memo[1][0] = i;
            if (arr1[i - 1] == arr2[j - 1])
                memo[1][j] = memo[0][j - 1];
            else
                memo[1][j] = 1 + std::min(
                        {memo[0][j], memo[0][j-1], memo[1][j - 1]});
        }
        memo[0] = memo[1];
    }

    return *(memo[1].end() - 1);
}

#endif //DIST_H_
