#include <iostream>
#include <utility>

void print_pair_long_long(std::pair<long long, long long> p){
    std::cout <<"p.first:" << p.first <<std::endl;
    std::cout <<"p.second:" << p.second <<std::endl;
}
int main(void){
    long long a = 0;
    long long b = 0;
    std::cin >> a >> b;
    print_pair_long_long(std::make_pair(a,b));
    return 0;
}
