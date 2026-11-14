//插入元素
#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<char> v(3,'c');
    std::vector<char>::iterator it = v.begin()+1; //初始化it迭代器
    it = v.insert(it, 'p');
    //it迭代器执行等号右边会失效，但由于等号右边会返回一个迭代器，将其重新赋值给it，it又有效了。

    v.insert(it, 2, 'a');//执行后，it迭代器失效

    std::string str = "bilibili";
    v.insert(v.end(), str.begin(),str.end()); // insert第三种重载函数
    for (std::size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i] <<" ";
    }

}
