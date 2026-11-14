#include <string>

#include <iostream>
#include <vector>
int main()
{
    std::string str = "creeper";
    std::vector<char> v(str.begin(),str.end());
    for (std::size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i] <<" ";
    }
}
