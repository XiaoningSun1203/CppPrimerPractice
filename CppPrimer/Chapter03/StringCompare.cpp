#include <iostream>
#include <string>

int main()
{
    std::string str1 = "12345678956";
    std::string str2 = "1234";
    std::cout << std::boolalpha;
    std::cout << (str1 == str2) << std::endl;
    std::cout << (str1.compare(str2) == 0) << std::endl;
    return 0;
}
