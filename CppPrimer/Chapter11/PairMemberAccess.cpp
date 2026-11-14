#include <iostream>
#include <utility>
#include <string>

int main(int argc, const char * argv[]) {
    std::pair<int ,std::string> stu;
    stu.first = 233;
    stu.second = "cxkk";
    std::cout<<"学号:"<<stu.first<<"\n姓名:"<<stu.second<<std::endl;
    return 0;
}
