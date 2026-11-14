#include <iostream>
#include <string>

bool lengthCompare(const std::string &, const std::string &);
std::string::size_type sumLength(const std::string &, const std::string &);
bool cstringCompare(const char*, const char*);

int main ()
{
    bool (*pf)(const std::string &, const std::string &);
    pf = 0;               // 正确，pf不指向任何函数
    pf = sumLength;       // error，返回类型不匹配
    pf = cstringCompare;  // error，形参类型不匹配
    pf = lengthCompare;   // 正确，函数lengthCompare 和 指针pf 的类型精确匹配

    return 0;
}
