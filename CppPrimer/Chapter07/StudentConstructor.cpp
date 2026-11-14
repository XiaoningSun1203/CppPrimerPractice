#include <iostream>
#include <string>
using namespace std;

class Student{
private:
    string m_name;
    const int m_age;
    float m_score;
public:
    Student();
    //声明构造函数
    Student(string name, int age, float score);

    //声明普通成员函数
    void show();
};

//定义构造函数
Student::Student(string name, int age, float score):m_name(name),m_age(age),m_score(score)
{

}

//定义普通成员函数
void Student::show(){
    cout << m_name <<"的年龄是："<< m_age <<",的成绩是" << m_score << endl;
}

int main(){
    //创建对象时向构造函数传参
    Student stu{"小明", 15, 92.5f};
    stu.show();
    //创建对象时向构造函数传参
    Student *p = new Student("李华",16, 96);
    p->show();
    delete p;

    return -1;
}
