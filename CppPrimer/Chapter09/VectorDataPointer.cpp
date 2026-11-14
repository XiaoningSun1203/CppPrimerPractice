#include <iostream>
#include <vector>
int main()
{
    std::vector<int> v(5,1024);
    int *pointer = v.data();
    pointer[2] = 66;
    for (std::size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i] << std::endl;
    }
    return 0;
}
