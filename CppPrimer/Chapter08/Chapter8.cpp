/**
 * c++Primer练习8.1
 * 问题：输入a后不显示"数据错误，请重试" 
 */
#include <stdexcept>
#include <iostream>
#include <string>
using namespace std;

istream& func(istream &in){
    int v;
    //in >> s:从istream对象读取数据放入s中，兼具判断读操作成功的任务
    //in.eof()用来判断流有没有结束
    while(in >> v && !in.eof()){
        if(in.bad()){   //.bad()为Trueg++代表流已崩溃
            throw runtime_error("IO流错误");    // throw会中止程序
        }
        if (in.fail()){    //.fail()为真代表IO操作失败
            cerr << "数据错误，请重试" << endl;
            in.clear();    //使in有效
            in.ignore(100,'\n');
            continue;     // 结束本次循环，进入下一次循环
        }
        cout << v << endl;
    }
    in.clear();
    return in;
}

int main(){
    cout << "请输入一些字符，按Ctrl+Z结束" << endl;
    func(cin);
    return 0;
}
