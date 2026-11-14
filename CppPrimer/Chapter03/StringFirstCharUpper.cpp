#include <iostream>
#include <string>
#include <cctype>
int main(void)
{
    std::string s = "some string";
    if (!s.empty()) {
        s[0] = toupper(s[0]);
    }
    return 0;
}
