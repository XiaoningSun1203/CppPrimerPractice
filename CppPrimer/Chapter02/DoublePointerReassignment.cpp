#include <iostream>
#include <cstdio>

#include <stdio.h>
void move_p(int **pointer, int arr[]){
    (*pointer) = &arr[1];
}

int main(){
    int arr[] = {5,6,7,8,9};
    int *p = &arr[0]; // p指向数组首地址
    move_p(&p,arr);
    std::cout << "*p = " << *p << std::endl;//*p = 6
    return 0;
}
