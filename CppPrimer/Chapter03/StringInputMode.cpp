// 3.3
//3.3
#include <iostream>
#include <string>// std::string std::getline()

int main()
{
    std::string word,line;
    std::cout << "请选择读取字符串的方式：1表示逐字读取，2表示整行读取" << std::endl;
    char ch;
    std::cin >> ch;
    if(ch=='1')
    {
        std::cout << "请输入字符串：   Welcome to C++ family!" << std::endl;
        std::cin >> word;
        std::cout << "系统读取的有效字符串是：" <<std::endl;
        std::cout << word << std::endl;
        return 0;
    }
    std::cin.clear();
    std::cin.sync();
    if(ch=='2')
    {
        std::cout << "请输入字符串：   Welcome to C++ family!" << std::endl;
        std::getline(std::cin, line); //不知道为什么不能输入？
        std::cout << "系统读取的有效字符串是：" <<std::endl;
        std::cout << line << std::endl;
        return 0;
    }
    std::cout <<"您的输入有误";
    return -1;
}
