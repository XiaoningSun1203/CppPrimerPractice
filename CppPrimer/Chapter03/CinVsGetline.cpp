#include <iostream>
#include <string>

int main(void){
    std::string str;
    std::cin >> str; //以空白符作为停止
    //std::getline(std::cin, str); //以换行符作为停止
    std::cout << str << std::endl;
    return 0;
}
