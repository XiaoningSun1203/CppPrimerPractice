#include <iostream>
#include <vector>
int main()
{
    std::vector<int> v(5);
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i] << std::endl;
    }
    return 0;
}
