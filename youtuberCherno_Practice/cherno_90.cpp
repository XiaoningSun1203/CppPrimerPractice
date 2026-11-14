    //运行出错了！！！！！因为63行中的<<
    //如果想要将现有的对象移动到另一个对象中（移动赋值），而不是构造一个新对象（移动构造），会发生什么？
    //当我们决定把一个字符串作为临时变量时，要怎么弄呢？那就是使用std::move
namespace 01 {
#include <iostream>
#include <string>

class String {
public:
    String() = default;
    String (const char *s) {
        std::cout << "String 类构造函数！！！" << std::endl;
        m_size = strlen(s);
        m_data = new char[m_size];
        memcpy(m_data, s, m_size);
    }
    String (const String &other_s) {
        std::cout << "String 类拷贝构造函数！！！" << std::endl;
        m_size = other_s.m_size;
        m_data = new char[m_size];
        memcpy(m_data, other_s.m_data, m_size);
    }
    String (String &&other) noexcept {                         
        std::cout << "String 类 move 构造函数！！！" << std::endl;
        m_size = other.m_size;
        m_data = other.m_data;
        
        other.m_data = nullptr;
        other.m_size = 0;
    }
    String& operator=(String &&other) {                         // <------move 赋值函数
        std::cout << "String 类 move 赋值函数！！！" << std::endl;
        if (this != &other){
            delete[] m_data;
            m_size = other.m_size;
            m_data = other.m_data;
        
            other.m_data = nullptr;
            other.m_size = 0;
        }
        return *this; 
    }

    void print() {
        for (std::size_t i = 0; i < m_size; ++i) {
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

int main() {
    String apple = "apple!";
    String dest;
    std::cout << "apple : " << std::endl;
    apple.print();
    std::cout << "dest : " <<  std::endl;
    dest.print();

    dest = std::move(apple);
    std::cout << "apple : " << std::endl;
    apple.print();
    std::cout << "dest : " <<  std::endl;
    dest.print();
    return 0;
}
   
}  // namespace 01
