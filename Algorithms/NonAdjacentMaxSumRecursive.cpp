#include <iostream>
#include <vector>
#include <cmath>

int rec_opt(std::vector<int> v, int k)
{
    if (k == 0)
    {
        return v[0];
    }
    else if (k == 1)
    {
        return fmax(v[0],v[1]);
    }
    else
    {
        return fmax(rec_opt(v, k-2) + v[k], rec_opt(v, k-1));
    }
}
int main()
{
    std::vector<int> v{1,2,4,1,7,8,3};
    std::cout << rec_opt(v, 6) << std::endl;
    return 0;
}
