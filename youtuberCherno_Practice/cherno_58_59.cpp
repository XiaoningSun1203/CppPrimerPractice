namespace 58_01 {
    //C语言中的原始raw函数指针
#include <iostream>

void HelloWorld(int x)
{
    std::cout << x << "Hello World!" << std::endl;
}
int main()
{
    //声明一个指向函数的指针pf,  void(*pf)(int);
    //把一个函数赋值给一个变量,   pf = HelloWorld;
    auto pf = &HelloWorld; // 拆成两步

    pf(5); //5Hello World!
    pf(6); //6Hello World!
    return 0;
}

#include <iostream>

void HelloWorld(int x)
{
    std::cout << x << "Hello World!" << std::endl;
}
int main()
{
    void(*pf)(int); //声明一个指向函数的指针pf
    pf = HelloWorld;//把一个函数赋值给一个变量

    pf(5); //5Hello World!
    pf(6); //6Hello World!

    return 0;
}

}  // namespace 58_01

namespace 58_02 {

#include <iostream>

void HelloWorld(int x)
{
    std::cout << x << "Hello World!" << std::endl;
}
int main()
{
    typedef void(*PF)(int); //如果不用auto，可以用typedef
    PF pf = HelloWorld;
    
    pf(5);
    pf(6);

    return 0;
}  

}  // namespace 58_02

namespace an_example {

#include <iostream>
#include <vector>

void PrintValue(int v){
    std::cout << "Value:" << v << std::endl;
}
void ForEach(const std::vector<int> &values, void(*func)(int)){ //
    for(int v : values){
        func(v);
    }
}
int main(){
    std::vector<int> values = {1,2,4,6};
    ForEach(values, PrintValue); // 函数 PrintValue 作为实参传入
    return 0;
}

}  // namespace an_example

namespace lambda_example{

#include <iostream>
#include <vector>
void ForEach(const std::vector<int> &values, void(*func)(int)){
    for(int v : values){
        func(v);
    }
}
int main(){
    std::vector<int> values = {1,2,3,4};
    ForEach(values, [](int v)
    {
        std::cout << "Value:" << v << std::endl;
    });
}

}  // namespace lambda_example

namespace lambda_02{

    //lambda表达式用处:在未来决定如何调用ForEach函数
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional> // <-new
void ForEach(const std::vector<int> &values, const std::function<void(int)> &func) 
                                             // 编译不通过void(*func)(int)
{
    for(int v : values){
        func(v);
    }
}
int main(){
    int a = 8;
    std::vector<int> values = {1, 5, 4, 6};
    // 什么是捕获？如果我们想把外部变量 a 放到lambda函数内部使用，
    // 既可以按值传入a,也可以按引用传入a
    // [=] 以值传入a ,或者[&]  以引用传入a,
    // [a] 以值传入a ,或者[&a] 以引用传入a,
    auto lambda = [a](int v){ std::cout << "a:" << a << std::endl; };
    ForEach(values, lambda);
    return 0;
}

}  // namespace lambda_02

namespace lambda_03 {

#include <iostream>
#include <vector>
#include <algorithm>
int main(){
    std::vector<int> values = {1, 3, 8, 7};
    auto iter = std::find_if(values.begin(), values.end(), [=](int v){ return v > 3; });
    std::cout << *iter << std::endl; //8
    return 0;
}

}  // namespace lambda_03