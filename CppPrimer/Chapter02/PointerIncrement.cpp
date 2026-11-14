#include <iostream>
#include <cstdio>

#include <stdio.h>
void increament(int *p){
    (*p)++;
}
int main(){
    int a = 10;
    increament(&a);
    std::cout << "a = " << a << std::endl;
    return 0;
}
