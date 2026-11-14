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
