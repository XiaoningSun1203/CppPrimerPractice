// P221 函数指针
#include <iostream>
#include <string>

std::string::size_type get_length(const std::string &s)
{
    return s.size();
}
int main ()
{
    // 直接使用函数get_length
    std::string::size_type b3 = get_length("bye");
    std::cout << b3 << std::endl;  // 3
    // 一个等价的调用
    auto pf1 = &get_length;
    std::string::size_type b1 = pf1("one=");
    std::cout << b1 << std::endl;  // 4
    // 另一个等价的调用
    auto pf2 = get_length;
    std::string::size_type b2 = (*pf2)("another=");
    std::cout << b2 << std::endl;  // 7
    
    return 0;
}
