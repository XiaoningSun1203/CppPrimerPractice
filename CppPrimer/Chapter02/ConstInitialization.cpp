#include <iostream>

// P53 const限定符
int main ()
{
    auto f = [] { return 3; };
    const int ia = f();
    
    std::cout << ia << std::endl; // 3
    
    return 0;
}
