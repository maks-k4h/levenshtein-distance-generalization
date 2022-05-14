
#ifndef DIST_H_
#define DIST_H_

#include <cctype>
#include <string>
#include <vector>

// T must provide .size() and access by index.
// Elements of arr_ must be comparable by '==' .
template <typename T>
size_t editDistance(const T &arr1, const T &arr2) {
    std::vector<std::vector<size_t>>
            memo(arr1.size() + 1, std::vector<size_t>(arr2.size() + 1));
    for (auto i = 0; i < arr1.size() + 1; ++i)
        memo[i][0] = i;
    for (auto i = 0; i < arr2.size() + 1; ++i)
        memo[0][i] = i;

    for (auto i = 1; i < arr1.size() + 1; ++i)
        for (auto j = 1; j < arr2.size() + 1; ++j)
            if (arr1[i - 1] == arr2[j - 1])
                memo[i][j] = memo[i - 1][j - 1];
            else
                memo[i][j] = 1 + std::min({
                        memo[ i- 1][j],
                        memo[i][j - 1],
                        memo[i - 1][j - 1]});

    return memo[arr1.size()][arr2.size()];
}

#endif //DIST_H_
