#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::string str="bilibili xiaoguyin";
    std::vector<char> v(str.begin(),str.end());
    std::cout << "第一个元素" << v.front() << std::endl;
    std::cout << "最后一个元素" << v.back() << std::endl;
    return 0;
}
