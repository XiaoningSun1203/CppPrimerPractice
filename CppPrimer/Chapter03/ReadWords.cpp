#include <iostream>
#include <string>

// 读取未知数量的string对象
int main()
{
    std::string word;
    while(std::cin >> word) //以空白符作为停止
    {
        std::cout << word << std::endl;
    }
    return 0;
}
