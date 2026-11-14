#include <vector>

// P347 lambda 表达式
#include <iostream>
#include <string>
#include <algorithm>
bool isShorter(const std::string &s1, const std::string &s2)
{
    return s1.size() < s2.size();
}
int main()
{
    std::vector<std::string> words { "acbdfe", "10", "111" };
    std::stable_sort(words.begin(), words.end(), isShorter);
    for(auto& ch : words)
    {
        std::cout << ch << " ";
    }
    std::cout << std::endl;
    return 0;
    // 10 111 acbdfe
}
