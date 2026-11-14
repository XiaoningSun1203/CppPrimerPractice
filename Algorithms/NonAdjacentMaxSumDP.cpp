#include <iostream>
#include <vector>
#include <cmath>
int dp_opt(std::vector<int> vec, std::vector<int> store, int k)
{
    for (int i = 2; i <= k; ++i) {
        store[i] = fmax(store[i-2] + vec[i], store[i-1]);
    }
    return store[vec.size()-1];
}

int main()
{
    std::vector<int> vec{1,2,4,1,7,8,3};
    std::vector<int> store(vec.size(),0);
    store[0] = vec[0];
    store[1] = fmax(vec[0], vec[1]);

    std::cout << dp_opt(vec, store, 6) << std::endl;
    return 0;
}
