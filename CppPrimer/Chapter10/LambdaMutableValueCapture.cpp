// P352 可变lambda
#include <iostream>
using namespace std;

int main()
{
    size_t v1 = 42;  // v1是局部变量
    // 如果想要改变被捕获变量 v1 的"值",需要加 mutable
    auto f1 = [v1]()mutable { return ++v1; };
    v1 = 0;
    std::cout << f1();  // 43 ,v1的值被从42改成了43
    return 0;
}
