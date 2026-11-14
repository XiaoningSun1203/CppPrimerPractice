#include <iostream>
#include <vector>

int sum_all_elem (int a, int b){
    int sum = 0;
    for (int i = a; i <= b; ++i){
        sum = sum + i;
    }
    return sum;
}
int main(){
    // std::vector<int> vec = {2,3,4,5,6,7};
    // int start = vec.front();
    // int end = vec.back();
    std::cout << sum_all_elem(2, 7) << std::endl;
    return 0;
}
