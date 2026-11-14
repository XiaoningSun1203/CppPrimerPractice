#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    // 在vector中寻找第一个大于等于给定长度的元素。
    std::string sz("abc");
    std::vector<std::string> words { "acbdfe", "10", "111" };
    auto iter = std::find_if(words.begin(), words.end(), [sz](const std::string &s){ return s.size() >= sz.size(); } );

    std::cout << *iter << std::endl;
    return 0;
    // acbdfe
}
