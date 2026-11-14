#include <iostream>
#include <string>

int main ()
{
    auto f = [] (const std::string &a, const std::string &b) { return a.size() == b.size(); };
    std::cout << f("hello", "hello") << std::endl;  // 1

    auto function = [](int a, int b){ return a + b; };
    std::cout << function(1,2) << std::endl;
    return 0;
}
