#include <iostream>

int main()
{
    size_t v1 = 42;
    auto f1 = [&v1]()mutable { return ++v1; };
    v1 = 0;
    std::cout << f1();  // 1 ,v1的值
    return 0;
}
