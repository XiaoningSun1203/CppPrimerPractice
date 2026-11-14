#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

// 如果用ostringstream重写上面的
int main()
{
    std::vector<std::string> words {"abcdef", "10", "111"};
    std::ostringstream oss;
    for_each(words.begin(), words.end(), [&oss](const std::string& s){ oss << s << " "; });
    std::cout << oss.str();
    return 0;
}
