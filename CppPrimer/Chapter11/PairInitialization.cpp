#include <iostream>
#include <utility>
#include <string>

int main(void){
    std::pair<int,float> a(233,66.66);
    std::pair<long long,std::string> b(1024,"cxk");
    std::cout <<"a.first:" << a.first << "\na.second:" << a.second << std::endl;
    std::cout << "b.first:" << b.first << "\nb.second:" << b.second << std::endl;
    return 0;
}
