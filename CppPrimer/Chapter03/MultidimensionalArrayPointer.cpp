#include <iterator>

#include <iostream>

using int_array = int[4];
// 打印指针pointer指向的4个元素
void print(int_array *pointer)
{
    for (int i = 0; i < 4; ++i)
    {
        std::cout << *(pointer + i) << " ";   // 0x430 0x440 0x450 0x460
        std::cout << (*pointer)[i] << " ";    // 8 9 10 11
        std::cout << *(*pointer + i) << " ";  // 8 9 10 11
    }
    std::cout << std::endl;
}

// 多维数组的指针使用
int main()
{
    int ia[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };
    std::cout << *ia    << std::endl;  // 0x410 查看 ia 里面放了什么，放了一个0x地址
    std::cout << *ia[0] << std::endl;  // 0 ,对第1行的第1个元素解引用
    std::cout << *ia[2] << std::endl;  // 8 ,对第3行的第1个元素解引用
    
    // 下面3个output是相同的地址，指针指向第二行第一个元素
    std::cout << *(ia+1)  << std::endl;  // 0x420
    std::cout << ia[1]    << std::endl;  // 0x420
    std::cout << &ia[1][0]<< std::endl;  // 0x420
    // 下面3个output是相同的地址，指针指向第三行第一个元素
    std::cout << *(ia+2)  << std::endl;  // 0x430
    std::cout << ia[2]    << std::endl;  // 0x430
    std::cout << &ia[2][0]<< std::endl;  // 0x430
    
   
    int (*p)[4] = ia;  //此时 数组name:ia 是一个指针，指向数组的第1行，里面有4个元素。
    std::cout << p << std::endl;   // 0x410
    std::cout << *p << std::endl;  // 0x410, output 是一个地址，是一个int[4]的第1个元素的地址
    
    p = &ia[2];  // ia[2]实际上是数组的第3行,里面有4个元素.
    std::cout << p << std::endl;   // 0x430
    std::cout << *p << std::endl;  // 0x430 ,output 是一个地址,是一个int[4]的第1个元素的地址
    print(p);
}
