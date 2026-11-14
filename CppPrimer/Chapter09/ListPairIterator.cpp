#include <utility>

#include <iostream>
#include <list>
#include <iterator>
#include <string>
int main(void)
{
    std::list<std::pair<int,std::string>> c;
    
    c.push_back(std::make_pair(11,"sss"));
    c.push_back(std::make_pair(22,"sdf"));
    c.push_front(std::make_pair(33, "dhhjd"));
    c.push_back(std::make_pair(44, "efeferfer"));
    c.pop_back();
    c.pop_front();
    
    //使用迭代器访问和修改元素
    std::list<std::pair<int,std::string>>::iterator it = c.begin();
    std::advance(it,1); // 让迭代器it前进1位
    *it = std::make_pair(77, "sdfdf"); //对it解引用并赋值新元素
    
    //使用迭代器循环输出每一个元素
    for(it=c.begin(); it != c.end(); ++it)
    {
        std::cout << it->first << it->second << std::endl;
    }

    return 0;
}
