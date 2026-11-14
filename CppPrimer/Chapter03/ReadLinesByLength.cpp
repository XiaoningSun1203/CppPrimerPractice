#include <iostream>
#include <string>

int main()
{
    std::string word;
    while(std::getline(std::cin,word)) // 以换行符作为停止
    {
        if(word.size()>4)
            std::cout << word << std::endl;
    }
    return 0;
}
