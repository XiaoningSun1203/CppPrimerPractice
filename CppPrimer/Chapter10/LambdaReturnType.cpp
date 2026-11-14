#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 指定lambda返回类型（现在即使不用尾置返回类型，也能正常编译通过）
int main()
{
    std::vector<int> vec {-1, 0, 2, -3};
    transform(vec.begin(), vec.end(), vec.begin(), [](int i)
    {
        if (i < 0) return -i; else return i;
    });
    // transform(vec.begin(), vec.end(), vec.begin(), [](int i) { return i < 0 ? -i : i; };
    for (auto item : vec)
    {
        std::cout << item << " ";
    }
    return 0;
    // 1 0 2 3 
}
