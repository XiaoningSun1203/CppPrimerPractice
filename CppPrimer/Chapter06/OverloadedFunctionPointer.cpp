// 重载函数的指针
#include <iostream>
void ff(int*);         // 重载函数1
void ff(unsigned int); // 重载函数2
int main()
{
    void (*pf1)(unsigned int) = ff;  // pf1指向重载函数2
    void (*pf2)(int) = ff;           // error, 没有任何一个ff与该形参列表匹配
    double (*pf3)(int*) = ff;        // error, ff 和 pf3 的返回类型不匹配
}
