#include <iostream>

// P52 指向指针的引用
int main()
{
    int i = 42;
    int *p;
    
    int *&r = p;
    r = &i;
    std::cout << r << std::endl;  // 0x7ffe3a713914
    std::cout << *r << std::endl;  // 42
    
    *r = 0;  // 相当于 *p = 0
    std::cout << *r << std::endl;  // 0
    std::cout << i << std::endl;  // 0
    return 0;
}
