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

// 初始化汇总
int main ()
{
    // 每个字节与一个地址（address）关联，== 可寻址的最小内存块称为“字节byte”
    
    
    
    // 内置类型的 初始化 P39
    int units_sold = 0;
    int units_sold(0);
       // list initialization
    int units_sold{0};
    int units_sold = {0};
    
    // 如何初始化类的对象 P76
       // 初始化 string 对象的方式
    string s1;           // 默认初始化，s1是一个空的string
    string s2 = s1;      // s2 是 s1 的副本
    string s2(s1);
    string s3 = "hiya";  // s3 是_该字符串字面值_的副本
    string s4("hiya");
    string s4(10, 'c');  // cccccccccc
    
    // P88 定义和初始化vector对象的方法
    
    // 定义和初始化内置数组 P101
}

#include <iostream>

using int_array = int[4];
// 打印指针pointer指向的4个元素
void print(int_array *pointer)
{
    for (int i = 0; i < 4; ++i)
    {
        std::cout << *(pointer + i) << " ";   // 0x430 0x440 0x450 0x460
        std::cout << (*pointer)[i] << " ";    // 8 9 10 11
        std::cout << *(*pointer + i) << " ";  // 8 9 10 11
    }
    std::cout << std::endl;
}

// 多维数组的指针使用
int main()
{
    int ia[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };
    std::cout << *ia    << std::endl;  // 0x410 查看 ia 里面放了什么，放了一个0x地址
    std::cout << *ia[0] << std::endl;  // 0 ,对第1行的第1个元素解引用
    std::cout << *ia[2] << std::endl;  // 8 ,对第3行的第1个元素解引用
    
    // 下面3个output是相同的地址，指针指向第二行第一个元素
    std::cout << *(ia+1)  << std::endl;  // 0x420
    std::cout << ia[1]    << std::endl;  // 0x420
    std::cout << &ia[1][0]<< std::endl;  // 0x420
    // 下面3个output是相同的地址，指针指向第三行第一个元素
    std::cout << *(ia+2)  << std::endl;  // 0x430
    std::cout << ia[2]    << std::endl;  // 0x430
    std::cout << &ia[2][0]<< std::endl;  // 0x430
    
   
    int (*p)[4] = ia;  //此时 数组name:ia 是一个指针，指向数组的第1行，里面有4个元素。
    std::cout << p << std::endl;   // 0x410
    std::cout << *p << std::endl;  // 0x410, output 是一个地址，是一个int[4]的第1个元素的地址
    
    p = &ia[2];  // ia[2]实际上是数组的第3行,里面有4个元素.
    std::cout << p << std::endl;   // 0x430
    std::cout << *p << std::endl;  // 0x430 ,output 是一个地址,是一个int[4]的第1个元素的地址
    print(p);
}

//P115 指针和多维数组
int main()
{
    int ia[3][4] = 
    {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };
    // 在数组前面加上一个指针类型
    for (auto p = ia; p != ia + 3; ++p)
    {
        for (auto q = *p; q != *p + 4; ++q)
        {
            std::cout << *q << ' ';
        }
        std::cout << std::endl;
    }
    
    // 使用标准库函数 begin 和 end
    for (auto p = std::begin(ia); p != std::end(ia); ++p)
    {
        for (auto q = std::begin(*p) ; q != std::end(*p); ++q)
        {
            std::cout << *q << ' ';
        }
        std::cout << std::endl;
    }
    
    return 0;
}
// P52 指向指针的引用
int main()
{
    int i = 42;
    int *p;
    
    int *&r = p;
    r = &i;
    std::cout << r << std::endl;  // 0x7ffe3a713914
    std::cout << *r << std::endl;  // 42
    
    *r = 0;  // 相当于 *p = 0
    std::cout << *r << std::endl;  // 0
    std::cout << i << std::endl;  // 0
    return 0;
}

// P53 const限定符
int main ()
{
    auto f = [] { return 3; };
    const int ia = f();
    
    std::cout << ia << std::endl; // 3
    
    return 0;
}

namespace 函数指针
{
// P221 函数指针
#include <iostream>
#include <string>

std::string::size_type get_length(const std::string &s)
{
    return s.size();
}
int main ()
{
    // 直接使用函数get_length
    std::string::size_type b3 = get_length("bye");
    std::cout << b3 << std::endl;  // 3
    // 一个等价的调用
    auto pf1 = &get_length;
    std::string::size_type b1 = pf1("one=");
    std::cout << b1 << std::endl;  // 4
    // 另一个等价的调用
    auto pf2 = get_length;
    std::string::size_type b2 = (*pf2)("another=");
    std::cout << b2 << std::endl;  // 7
    
    return 0;
}

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

// 重载函数的指针
#include <iostream>
void ff(int*);         // 重载函数1
void ff(unsigned int); // 重载函数2
int main()
{
    void (*pf1)(unsigned int) = ff;  // pf1指向重载函数2
    void (*pf2)(int) = ff;           // error, 没有任何一个ff与该形参列表匹配
    double (*pf3)(int*) = ff;        // error, ff 和 pf3 的返回类型不匹配
}
}  // namespace 函数指针

// P347 lambda 表达式
namespace lambda expression
{
#include <iostream>
#include <string>
#include <algorithm>
bool isShorter(const std::string &s1, const std::string &s2)
{
    return s1.size() < s2.size();
}
int main()
{
    std::vector<std::string> words { "acbdfe", "10", "111" };
    std::stable_sort(words.begin(), words.end(), isShorter);
    for(auto& ch : words)
    {
        std::cout << ch << " ";
    }
    std::cout << std::endl;
    return 0;
    // 10 111 acbdfe
}
int main ()
{
    auto f = [] (const std::string &a, const std::string &b) { return a.size() == b.size(); };
    std::cout << f("hello", "hello") << std::endl;  // 1

    auto function = [](int a, int b){ return a + b; };
    std::cout << function(1,2) << std::endl;
    return 0;
}
int main()
{
    // 在vector中寻找第一个大于等于给定长度的元素。
    std::string sz("abc");
    std::vector<std::string> words { "acbdfe", "10", "111" };
    auto iter = std::find_if(words.begin(), words.end(), [sz](const std::string &s){ return s.size() >= sz.size(); } );

    std::cout << *iter << std::endl;
    return 0;
    // acbdfe
}
int main()
{
    std::vector<std::string> words { "acbdfe", "10", "111" };
    for_each(words.begin(), words.end(), [](const std::string& s){ std::cout << s << std::endl; });
    // acbdfe
    // 10
    // 111
    return 0;
}
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
// 如果用ostringstream重写上面的
int main()
{
    std::vector<std::string> words {"abcdef", "10", "111"};
    std::ostringstream oss;
    for_each(words.begin(), words.end(), [&oss](const std::string& s){ oss << s << " "; });
    std::cout << oss.str();
    return 0;
}

}  // lambda expression


namespace chapter8
{
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
#include <iostream>
#include <fstream>
#include <string>
int main()
{
    int i = 4;
    while (--i)
    {
        std::string fileName = "test.txt";
        std::ofstream ofs(fileName + std::to_string(i), std::ofstream::trunc);

        ofs << "first line\n";
        ofs << i << std::endl;
        ofs << "this is end line\n";
        ofs.close(); 
    }
    return 0;
    // 新建了3个文件，分别是test1.txt、test2.txt、test3.txt
}
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
bool writePimcDataToFile(vector<U32>& data, const std::string& fileName)
{
    std::ofstream file(fileName, std::ios::trunc);  // 创建一个ofstream对象，把文件打开并与之关联，文件模式为覆盖trunc
    if (file.is_open())  // 如果文件被打开了
    {
        std::copy(data.begin(), data.end() - 1, std::ostream_iterator<U32>(file, ","));  // 将vector中的第一个到倒数第二个保存到文件中
        file << data.back();  // 把最后一个元素保存到文件中
        file.close();  // 关闭文件
        RADIO_INFO("Raw data has been written to %s successfully.", fileName.c_str());
    }
    else
    {
        RADIO_ERROR("Unable to open the file:%s", fileName.c_str());
        return false;
    }
    return true;
}

// P314 输入输出流
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct PersonInfo
{
    string name;
    vector<string> phoneNumber;
};

int main()
{
    string record1 {"liming 010213 010345"};
    string record2 {"anNi 010343 010215"};

    // 把两条记录塞入一个输出流
    ostringstream oss;
    oss << record1 << std::endl;
    oss << record2 << std::endl;
    
    string line, word;  // line 用来存储一行， word 用来存储两个空格间的一个词
    istringstream inputStream(record1);

    // getline 函数，从一个给定的 istream 读取一行数据，存入一个给定的 string 对象中。
    while (getline(inputStream, line))
    {
        PersonInfo person;
        istringstream record(line);
        record >> person.name;
        std::cout << person.name << std::endl;

        while (record >> word)
        {
            person.phoneNumber.push_back(word);
            std::cout << word << std::endl;
        }
    }
    // liming
    // 010213
    // 010345
    return 0;
}


} // namespace chapter8

