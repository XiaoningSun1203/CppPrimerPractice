#include <iostream>
#include <vector>
#include <iterator>
int main(void)
{
    std::vector<int> v{1,2,3,4,5};
    if (!v.empty()) {
        auto val1 = *v.begin();
        auto val2 = *(--v.end());

        auto val3 = v.front();
        auto val4 = v.back();
        std::cout << val1 << std::endl;
        std::cout << val2 << std::endl;
        std::cout << val3 << std::endl;
        std::cout << val4 << std::endl;
    }
    return 0;
}
