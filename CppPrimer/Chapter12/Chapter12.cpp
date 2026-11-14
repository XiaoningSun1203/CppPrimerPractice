/**
 * 第12章动态内存与智能指针
 */
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <stdexcept>

class StrBlob {
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    size_type size() const { return m_data->size(); }
    bool empty() const { return m_data->empty(); }
    //添加和删除元素
    void push_back(const std::string &t){m_data->push_back(t); }
    void pop_back();
    //元素访问
    std::string& front();
    std::string& back();

private:
    std::shared_ptr<std::vector<std::string>> m_data;
    void check(size_type i, const std::string &msg) const {};
};

StrBlob::StrBlob():m_data(std::make_shared<std::vector<std::string>>()) {}
StrBlob::StrBlob(std::initializer_list<std::string> il):\
    m_data(std::make_shared<std::vector<std::string>>(il)) {}

//如果check成功，这些成员函数继续利用底层vector操作来完成自己的工作
void StrBlob::check(size_type i, const std::string &msg) const {
    if(i >= m_data->size()){
        throw out_of_range(msg);
    }
}

std::string& StrBlob::front(){
    check(0, "front on empty StrBlob");
    return m_data->front();
}

std::string& StrBlob::back(){
    check(0, "back on empty StrBlob");
    return m_data->back();
}

void StrBlob::pop_back(){
    check(0, "pop_back on empty StrBlob");
    return m_data->pop_back();
}


//
// int *p1 = new int;//默认初始化，*p1是未定义
// int *p2 = new int();//值初始化，*p2=0
// std::vector<int> *pv = new std::vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
// std::string *ps = new std::string(10, '9');
