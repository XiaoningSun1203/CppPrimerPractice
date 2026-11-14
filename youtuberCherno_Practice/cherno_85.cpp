namespace 01 {

    // 认识左值与右值（不必执着于准确的定义他们），对理解std::move语义很重要
#include <iostream>
int main() {
    int i = 10; // 等号左侧是一个在内存中有地址的，右侧是一个字面量没有存在内存中
}

}  // namespace 01

namespace 02 {

    // 右值不仅可以是字面量，也可以是函数的结果
int GetValue() {
    return 10; 
}
int main() {
    //GetValue返回一个右值（临时值）,因为即使它返回一个int，它也没有存储空间，它只返回值10
    int i = GetValue(); //取这个右值，然后把它存储到左值 i 中
    //GetValue() = 5; // 错误，因为这是一个右值，如果我们试着给这个右值赋值，是行不通的
}

}  // namespace 02

namespace 03 {
    //如果想要GetValue()返回一个左值，可以通过返回 int& (左值引用)来实现
    //那么就要为这个值提供某种存储空间，比如使用一个静态int，然后返回它
#include <iostream>
int& GetValue() {
    static int value = 10;
    return value;
}
int main() {
    int i = GetValue();
    std::cout << "i : " << i << std::endl;//i : 10
    GetValue() = 5; // 正确，由于返回的是个左值引用，所以可以对它赋值
    std::cout << "GetValue() : " << GetValue() << std::endl; //GetValue() : 5
    return 0;
}

}  // namespace 03

namespace 04 {
    
#include <iostream>

void SetValue(int value) { }
int main() {
    int i = 3;
    SetValue(i); //参数是左值
    SetValue(10);//参数是右值，当函数被调用时，这个右值会被用来创建一个左值
    return 0;
}

}   // namespace 04

namespace 05 {

#include <iostream>

void SetValue(int& value) {}//被左值引用的，只能是左值
int main() {
    int i = 3;
    SetValue(i); //正确
    SetValue(10);//错误
    return 0;
}

}  // namespace 05

namespace 06 {

#include <iostream>
void SetValue(const int& value) { //const左值引用的，可以同时接受左值、右值
}
int main() {
    int i = 3;
    SetValue(i); //正确
    SetValue(10);//正确
    return 0;
}

}  // namespace 06

namespace 07 {
#include <iostream>
#include <string>

void PrintName(std::string &name) {
    std::cout << name << std::endl;
}
int main() {
    std::string firstname = "Yan";
    std::string lastname  = "Cherno";
    std::string fullname  = firstname + lastname; //由这两个组成一个临时字符串，然后把它赋值给一个左值
    
    PrintName(fullname);//传入的参数正确
    PrintName(firstname + lastname);//传入的参数错误,因为传入的是右值
    return 0;
}
    // ！！！！这就是为什么C++更推荐写const引用，因为它兼容右值和左值！！！！！！！
}  // namespace 07

namespace 08 {
    // 有一种方法来检测某个值是否为右值，这就需要用到右值引用了&&
#include <iostream>
#include <string>

void PrintName(std::string &&name) { //<-
    std::cout << name << std::endl;
}
int main() {
    std::string firstname = "Yan";
    std::string lastname  = "Cherno";
    std::string fullname  = firstname + lastname; 
    
    PrintName(fullname);//传入的参数错误
    PrintName(firstname + lastname);//传入的参数正确
    return 0;
}

}  // namespace 08

namespace 09 {
    //重载PrintName()函数
#include <iostream>
#include <string>

void PrintName(std::string &&name) { 
    std::cout << "[rvalue:]" << name << std::endl;
}
void PrintName(std::string &name) { 
    std::cout << "[lvalue:]" << name << std::endl;
}
int main() {
    std::string firstname = "Yan";
    std::string lastname  = "Cherno";
    std::string fullname  = firstname + lastname; 
    
    PrintName(fullname); //[lvalue:]YanCherno
    PrintName(firstname + lastname); //[rvalue:]YanCherno

    //std::cin.get();//这样控制台不会关闭
}
    //右值引用将用在std::move中，本课的主要优势在于优化，如果我们知道传入的是一个临时对象的话，
    //那么我们就不需要担心它们是否可用、是否拷贝。我们可以简单的偷它的资源，给到特定的地方
}  // namespace 09