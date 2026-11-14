#include <string>

// P354 参数绑定
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

// 判断字符串的字符数是否大于sz
bool check_size(const string &s, string::size_type sz)
{
    return s.size() >= sz;
}

int main()
{
    // 函数check_6 的参数个数比 函数check_size 少了一个
    auto check_6 = std::bind(check_size, std::placeholders::_1, 3);
    bool b1 = check_6("hi");  // 此处bind调用只有一个占位符，表示check_6函数只接受单一参数
    
    // 利用bind解决参数个数不匹配。
    vector<string> words { "acbdfe", "10", "111" };
    auto iter = find_if(words.begin(), words.end(), std::bind(check_size, std::placeholders::_1, 3));
    cout << *iter << endl;  // acbdfe
}
