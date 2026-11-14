#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    std::vector<std::string> words { "acbdfe", "10", "111" };
    for_each(words.begin(), words.end(), [](const std::string& s){ std::cout << s << std::endl; });
    // acbdfe
    // 10
    // 111
    return 0;
}
