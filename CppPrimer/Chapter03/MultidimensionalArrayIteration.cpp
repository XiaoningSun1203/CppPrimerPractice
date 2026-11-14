#include <iostream>
#include <iterator>

//P115 指针和多维数组
int main()
{
    int ia[3][4] = 
    {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };
    // 在数组前面加上一个指针类型
    for (auto p = ia; p != ia + 3; ++p)
    {
        for (auto q = *p; q != *p + 4; ++q)
        {
            std::cout << *q << ' ';
        }
        std::cout << std::endl;
    }
    
    // 使用标准库函数 begin 和 end
    for (auto p = std::begin(ia); p != std::end(ia); ++p)
    {
        for (auto q = std::begin(*p) ; q != std::end(*p); ++q)
        {
            std::cout << *q << ' ';
        }
        std::cout << std::endl;
    }
    
    return 0;
}
