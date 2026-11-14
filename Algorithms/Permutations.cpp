#include <utility>

#include <iostream>
#include <vector>

void printArr(std::vector<char> v){
    for (auto i:v) {
        std::cout << i ;
    }
    std::cout << std::endl;
}
/**
 * 全排列问题
 * @param p 进行全排列的初始位置.
 * @param q 全排列结束的位置，v的最后一个元素的下标.
 */
void perm(std::vector<char> v,int p, int q)
{
    if (p == q) //递归结束的条件：只有一个元素时，全排列只有一种可能.
    {
        printArr(v);
    }
    else
    {
        for (int i = p; i <= q; ++i)
        {
            std::swap(v[p], v[i]);// 将传入的v【p】依次与后面的每一个元素swap.
            perm(v, p+1, q);
            std::swap(v[p], v[i]);// 还原成传入的v，防止重复.
        }
    }
}
int main()
{
    std::vector<char> v{'A', 'B', 'C'};
    perm(v,0,2);
    return 0;
}
