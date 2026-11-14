#include <vector>

using namespace std;

// 引用捕获有时是必要的。 P351不能拷贝ostream对象，因此捕获os的唯一方法就是捕获其引用。
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
int main()
{
    std::vector<std::string> words { "acbdfe", "10", "111" };
    std::ostream os(std::cout.rdbuf());  // shares buffer with cout
    // rdbuf()可以实现一个流对象指向的内容用另一个流对象来输出,比如想把
    // 一个文件的内容输出到显示器上,我们可以两行代码完成:
    // ifstream infile("test.txt");
    // cout << infile.rdbuf();
    for_each(words.begin(), words.end(), [&os](const std::string& s){ os << s << " "; });

    return 0;
    // acbdfe 10 111 
}
