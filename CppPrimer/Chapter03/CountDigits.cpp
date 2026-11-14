#include <iostream>
#include <string>
#include <cctype>//std::isdigit()

int main()
{
    std::string str;
    std::getline(std::cin, str);

    int count = 0;
    for (size_t i=0; i < str.size(); ++i) {
        if(isdigit(str[i]))
        {
            count++;
        }
    }
    std::cout << count <<std::endl;
    return 0;
}
