#include <iostream>
#include <sstream>
#include <string>

int main()
{
    // 出内存
    std::ostringstream oss;
    oss << "\nline ";
    oss << "5" << std::endl;
    std::cout << oss.str();  // 返回oss所保存的string的拷贝
    oss.str("");          // 清除旧的内容
    oss << "这是多余的\n";
    std::cout << oss.str();
    //输出结果如下：
    //line 5
    //这是多余的
        
    // 入内存
    std::istringstream iss("from a stringstream");
    std::string container;

    iss >> container;                     // 把 “from” 写入字符串对象中
    std::cout << container << std::endl;  // from
    iss >> container;                     // 把 “a” 写入字符串对象中
    std::cout << container << std::endl;  // a
    iss >> container;                     // 把 “stringstream” 写入字符串对象中
    std::cout << container << std::endl;  // stringstream

    return 0;
}
