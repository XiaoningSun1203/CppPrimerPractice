// 可以这么认为:可以根据<< 或 >>箭头的方向来理解流的过程.
// 比如:cout<<n; 由于<<箭头方向向左,所以意思就是将n的值流入cout。cout是标准输出流,所以cout<<n;就把n显示到了屏幕上.
// 对于cin>>n;来说由于>>箭头方向向右,所以意思就是将cin中的数据流入n变量,cin是标准输入流,所以cin>>n;就把屏幕上的数据写入n变量.
// 也就是说箭头的方向相当于流的方向,也就是数据的流向.对于其他流对象(xxxstream)也是一样的道理

// #include <iostream>  // 可见域的操作, std::cin/std::cout 是对窗口的操作
// #include <fstream>   // 对文件进行的操作
// #include <sstream>   // 对内存的一种操作

#include <iostream>
#include <fstream>
int main()
{
    std::ofstream ofs("test.txt", std::ofstream::trunc);  // 创建一个ofstream对象，打开一个文件test.txt初始化这个对象。
    // trunc: 覆盖存在的文件，即清空原来文件中的数据，清空后再写入。

    ofs << "this is a new test\n";
    ofs.close();  // 关闭与文件流ofs绑定的文件
    return 0;
    // 文件之前不存在于是test.txt被新建，并在其中保存了this is a new test
}
