#include <iostream>
#include <string>
#include <vector>

// 初始化汇总
int main ()
{
    // 每个字节与一个地址（address）关联，== 可寻址的最小内存块称为“字节byte”
    
    
    
    // 内置类型的 初始化 P39
    int units_sold = 0;
    int units_sold(0);
       // list initialization
    int units_sold{0};
    int units_sold = {0};
    
    // 如何初始化类的对象 P76
       // 初始化 string 对象的方式
    string s1;           // 默认初始化，s1是一个空的string
    string s2 = s1;      // s2 是 s1 的副本
    string s2(s1);
    string s3 = "hiya";  // s3 是_该字符串字面值_的副本
    string s4("hiya");
    string s4(10, 'c');  // cccccccccc
    
    // P88 定义和初始化vector对象的方法
    
    // 定义和初始化内置数组 P101
}
