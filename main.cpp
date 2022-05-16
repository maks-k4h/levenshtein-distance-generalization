
#include "dist.h"

#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> tokenize(const std::string &str) {
    std::vector<std::string> res;
    for (auto i = 0; i < str.size(); ++i)
        if (isspace(str[i]) && i < str.size() - 1 && !isspace(str[i + 1]))
            res.emplace_back("");
        else {
            if (res.empty())
                res.emplace_back();
            res[res.size() - 1] += str[i];
        }
    return res;
}

void tolower(std::string &str) {
    for (auto &ch : str)
        ch = tolower(ch);
}

int main() {
    std::string str1 = "grammar", str2 = "grandma";
    std::cout << "character d(str1,str2) = "
        << editDistance(str1, str2) << '\n';

    std::string text1 = "You may write me down in history\n"
                        "With your bitter, twisted lies,";
    std::string text2 = "You may trod me in the very dirt\n"
                        "But still, like dust, I’ll rise.";
    std::cout << "character d(text1,text2) = "
        << editDistance(text1, text2) << '\n';

    tolower(text1);
    tolower(text2);

    auto text1_tokens = tokenize(text1);
    auto text2_tokens = tokenize(text2);

    std::cout << "words d(text1,text2) = "
        << editDistance(text1_tokens, text2_tokens) << '\n';
    return 0;
}
