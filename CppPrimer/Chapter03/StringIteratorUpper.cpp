#include <iostream>
#include <string>
#include <cctype>

int main(){
    std::string s("some string");
    if (s.begin() != s.end()) //确保s非空
    {
        auto it = s.begin();
        *it = toupper(*it);
    }
    std::cout << s << std::endl;
    return 0;
}
