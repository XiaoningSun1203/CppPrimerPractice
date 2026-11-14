//修改元素
#include <iostream>
#include <vector>
#include <string>

int main(void)
{
    std::string str = "bilisbdodk";
    std::vector<char> v(str.begin(),str.end());

    v.erase(v.begin()+5);
    v.erase(v.begin(),v.begin()+2);
    //为了方便，直接返回v.data（）返回的地址，由于返回的地址的数据类型是char*，
    //所以std::cout会把它当作C语言的字符串来输出，不过，这个字符串末尾没有空字符，
    //如果直接输出的话，那么后面的一些无关的数据就会当作字符来输出，这样是不行的，
    //所以我们要在末尾添加一个空字符'\0'
    v.push_back('\0');
    std::cout << v.data() << std::endl;

    return 0;
 }
