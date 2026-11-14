#include <iostream>
#include <string>
#include <cctype>

int main(void)
{
    std::string s("some string");
    for (decltype(s.size()) i = 0; i != s.size()&& !isspace(s[i]); ++i) {
        s[i] = toupper(s[i]);
    }
    std::cout << s << std::endl;
    return 0;
}
