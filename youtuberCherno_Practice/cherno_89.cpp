    //移动语义必须用到右值引用
    //讲 移动构造函数
namespace 01 {

#include <iostream>
#include <string>

class String {
public:
    String() = default;
    String(const char *s) {
        std::cout << "String 类构造函数！！！" << std::endl;
        m_size = strlen(s);
        m_data = new char[m_size];
        memcpy(m_data, s, m_size);
    }
    String(const String &other_s) {
        std::cout << "String 类 copy 构造函数！！！" << std::endl;
        m_size = other_s.m_size;
        m_data = new char[m_size];
        memcpy(m_data, other_s.m_data, m_size);
    }
    
    void print() {
        for(std::size_t i = 0; i < m_size; ++i){
            printf("%c", m_data[i]);
        }
        printf("\n");
    }
    ~String() {
        std::cout << "Destroyed！！！" << std::endl;
        delete m_data;
    }
private:
    char* m_data;
    std::size_t m_size;
};

class Entity {
public:
    Entity(const String& name) : m_name(name) { 
        std::cout << "Entity 类左值引用的构造函数！！！" << std::endl; 
    }
    Entity(String&& name) : m_name(name) { 
        std::cout << "Entity 类右值引用的构造函数！！！" << std::endl; 
    }
    void PrintName() {
        m_name.print();
    }
private:
    String m_name;
};

int main(){
    String str("Cherno");
    Entity entity(str);
    //Entity entity("Cherno");//隐式转换

    entity.PrintName(); 
    
    return 0;
}
    //String 类构造函数！！！
    //String 类 copy 构造函数！！！
    //Entity 类右值引用的构造函数！！！
    //Destroyed！！！
    //Cherno
    //Destroyed！！！
    //我们在创建一个 Entity 类的对象 Cherno 时，需要把一些字符串放在 m_name 中,但却因此分配了两次内存
}  // namespace 01

namespace 02 {
#include <iostream>
#include <string>

class String {
public:
    String() = default;
    String(const char *s) {
        std::cout << "String 类构造函数！！！" << std::endl;
        m_size = strlen(s);
        m_data = new char[m_size];
        memcpy(m_data, s, m_size);
    }
    String(const String &other_s) {
        std::cout << "String 类拷贝构造函数！！！" << std::endl;
        m_size = other_s.m_size;
        m_data = new char[m_size];
        memcpy(m_data, other_s.m_data, m_size);
    }
    String(String &&other) noexcept {                         //<---
        std::cout << "String 类 move 构造函数！！！" << std::endl;
        m_size = other.m_size;
        m_data = other.m_data;//只赋值指针，现在两个指针指向同一块内存
        
        //由于指向同一块内存，other被销毁时，也会影响this->m_data指向的内存，因此一定要处理other
        other.m_data = nullptr;
        other.m_size = 0;
        //other字符串现在是一个空的状态，当旧字符串实例被销毁时，delete m_data实际上会删除nullptr
    }
    void print() {
        for(std::size_t i = 0; i < m_size; ++i){
            printf("%c", m_data[i]);
        }
        printf("\n");
    }
    ~String() {
        std::cout << "Destroyed！！！" << std::endl;
        delete m_data;
    }
private:
    char* m_data;
    std::size_t m_size;
};


class Entity {
public:
    Entity(const String& name) : m_name(name) { 
        std::cout << "Entity 类左值引用的构造函数！！！" << std::endl; 
    }
    // (String &&)name 也可以写成 std::move(name)目的是转换成临时值 
    Entity(String&& name) : m_name((String &&)name) {
        std::cout << "Entity 类右值引用的构造函数！！！" << std::endl; 
    }
    void PrintName(){
        m_name.print();
    }
private:
    String m_name;
};

int main(){
    // String str("Cherno");
    // Entity entity(str);
    Entity entity("Cherno");//隐式转换

    entity.PrintName(); 
    
    return 0;
}
    //String 类构造函数！！！
    //String 类 move 构造函数！！！
    //Entity 类右值引用的构造函数！！！
    //Destroyed！！！
    //Cherno
    //Destroyed！！！
}  // namespace 02
