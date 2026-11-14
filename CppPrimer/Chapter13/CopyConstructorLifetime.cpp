#include <iostream>
using namespace std;

class Example{
private:
    int a;
public:

    Example(int x){
        a = x;
        cout<< "调用构造函数" << endl;
    }
    Example(const Example& x){
        a = x.a;
        cout<< "调用拷贝构造函数" << endl;
    }
    ~Example(){
        cout<< "调用析构函数" << endl;
    }
};
Example show(){
    Example temp(10);
    return temp;
}

int main(){

    cout <<"--------" << endl;
    show();
    cout <<"--------" << endl;
    return 0;
}
