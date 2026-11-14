// insert返回的指针:一直是指向首元素
#include <iostream>
#include <string>
#include <list>

int main ()
{
    std::list<std::string> lst;
    auto iter = lst.begin();
    std::string word;
    while (std::cin >> word)  // d e f g
    {
        iter = lst.insert(iter, word);
    }
    for (auto i : lst)
    {
        std::cout << i << " ";
        // g f e d
    }
    return 0;
}
