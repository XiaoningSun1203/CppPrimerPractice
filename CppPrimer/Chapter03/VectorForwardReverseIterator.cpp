#include <iostream>
#include <vector>
#include <string>
int main()
{
    std::string str = "bilibili xiaoguyin";
    std::vector<char> v(str.begin(),str.end());
    //正向输出str
    for (std::vector<char>::iterator it = v.begin(); it != v.end(); ++it) {
        std::cout << *it;
    }
    std::cout << std::endl; //相当于换行
    //反向输出str
    for (std::vector<char>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it) {
        std::cout << *it;
    }
    std::cout << std::endl;
    return 0;
}
