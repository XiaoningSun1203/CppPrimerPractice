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
