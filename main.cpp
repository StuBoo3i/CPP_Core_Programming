#include <iostream>

const double PI = 3.14159;

int g_a = 10;  //ȫ����
int g_b = 10;

const int c_g_a = 10;  //ȫ����
const int c_g_b = 10;

//int *function(){
//    int a = 0;   //�����ջ�����ں���ִ�����ͷ�
//    return &a;
//}
int *function2(){
    int * a = new int(10);   //���ٵ�����,ָ�뱾��Ҳ�Ǿֲ�����������ջ�ϣ�ָ�뱣��������Ƿ��ڶ���
    return a;
}
int test()   //���Բ�ͬ�ı������ڴ������е�λ��
{
    int a = 10;   //ջ��
    int b = 10;

    static int s_a = 10;  //ȫ����
    static int s_b = 10;

    const int c_l_a = 10; //ջ��
    const int c_l_b = 10;

    std::cout<< &a << std::endl;  //ջ�����ֲ�����
    std::cout<< &b << std::endl;

    std::cout<< &g_a << std::endl;  //ȫ������ȫ�ֱ���
    std::cout<< &g_b << std::endl;

    std::cout<< &s_a << std::endl;  //ȫ��������̬����
    std::cout<< &s_b << std::endl;

    std::cout<<&"Hello World"<<std::endl;  //ȫ�������ַ�������

    std::cout<< &c_g_a << std::endl;  //ȫ������const���ε�ȫ�ֳ���
    std::cout<< &c_g_b << std::endl;

    std::cout<< &c_l_a << std::endl;  //ջ����const���εľֲ�����
    std::cout<< &c_l_a << std::endl;

    return 0;
}

void test01(){
    int *pInt = function2();   //���������ݲ��Զ��ͷ�
    std::cout<< *pInt << std::endl;
    std::cout<< *pInt << std::endl;
    delete pInt;               //�����ͷ�
//    std::cout<< *pInt << std::endl;  //�޷����

}

void test02(){
    int *arr = new int[10];
    for (int i = 0;i<10;i++) {
        arr[i] = i+10*i;
    }
    for (int i = 0; i < 10; i++) {
        std::cout<<arr[i]<<std::endl;
    }
    delete[] arr;   //�ͷ������Ŀռ�

}

void new_name(){
    //����
    int a = 10;
    int &b = a;   //����
    std::cout<< a << std::endl;
    b = 20;
    std::cout<< a << std::endl;
}
//value
void swap1(int a, int b){
    int temp = a;
    a=b;
    b=temp;
}
//address
void swap2(int *a,int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}
//2.3���ô��ݣ����β�����ʵ�Σ�
void swap3(int &a,int &b){
    int temp = a;
    a=b;
    b=temp;
}
//int &test03(){
//    int a = 10;  //References can exist as return values for functions, but cannot return local variable references
//    return a;
//}
int &test04(){
//References can exist as return values for functions, static variables are stored in the global area, and the program is released by the system at the end of the program
    static int a = 10;
    return a;
}
//In the function parameter list, const can be added to modify the parameters to prevent them from changing the actual parameters.

void show_value(const int &val){
    std::cout<< "val:"<<val<<std::endl;
}
//In C++, the formal parameters in the function's formal parameter list can have default values.
int func(int a,int b = 10, int c= 20){
    return a+b+c;
}
void func(int a){
    std::cout<<"overload 1."<<std::endl;
}
void func2(const int &a){
    std::cout<<"overload 4."<<std::endl;
}
void func2(int &a){
    std::cout<<"overload 5."<<std::endl;
}
void func2(int a,int b, double c){
    std::cout<<"overload 2."<<std::endl;
}
void func2(int a,double c, int b){
    std::cout<<"overload 3."<<std::endl;
}
//The formal parameter list of C++functions can have a placeholder parameter, which must be filled in when calling the function.
int func3(int a, int){
    std::cout<<"this!"<<std::endl;
}
void main_cp(){
    test();
//    int *p = function();
//    std::cout<< *p << std::endl; //�����ں����������ͷţ��޷�����
    int *p2 = function2();
    std::cout<< *p2 << std::endl;
    test01();
    test02();
    new_name();
    int a=5,b=10;
    swap1(a,b);
    std::cout<< a << " " << b << std::endl;
    swap2(&a,&b);
    std::cout<< a << " " << b << std::endl;
    swap3(a,b);
    std::cout<< a << " " << b << std::endl;
//    int &ref = test03();
//    std::cout<< ref << std::endl;   //Cannot Building
    int &ref2 = test04();
    std::cout<< ref2 << std::endl;
    test04() = 1000;                 //The return value of a function is a reference type that can be called as a lvalue
    std::cout<< ref2 << std::endl;
    //const reference
    int a2 = 10;
    int & ref3 = a;    // must refer legitimate variables.   e.g.cannot use "int & ref = 10;"

    //add const, the compiler will modify the code to "int temp = 10; int & ref = temp;"
    const int & ref4 = 10;
    //ref = 20; cannot use,after add const.

    show_value(a);
    int a3 =10;
    func2(15,1.0,1);
    func2(15,1,1.0);
    func2(a3);
    func2(10);
    std::cout<<func(15,2,2)<<std::endl;
//    std::cout<<func(15)<<std::endl;   //Function overload conflicts with default parameters, try to avoid
    func3(10,3);
}

class Circle{
public:

    int m_r;

    double get_perimeter(){
        return 2*PI*m_r;
    }

};
class Person{
public:
    std::string m_name;

protected:
    std::string m_car;

private:
    int m_password;

public:
    void func(){
        m_name = "Jam";
        m_car = "tractor";
        m_password = 123456;
    }
};
class Person2{

private:
    std::string name;       //�ɶ���д
    int age = 20;           //ֻ��
    int id;                 //�ɶ���д(������0-1000֮��)
    std::string idol;       //ֻд

public:
    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        Person2::name = name;
    }

    int getAge() const {
        return age;
    }

    void setIdol(const std::string &idol) {
        Person2::idol = idol;
    }

    int getId() const {
        return id;
    }
    //Check the validity of data
    void setId(int id) {
        if (id>1000||id<0){
            std::cout<<"id error��"<<std::endl;
            return;
        }
        Person2::id = id;
    }
};
class Person3{
public:
    Person3(){
        std::cout<<"Person3 called"<<std::endl;
    }
    Person3(int a){
        age = a;
        std::cout<<"Person3 parametric construction called"<<std::endl;
    }
    Person3(const Person3 &p){
        age = p.age;
        std::cout<<"Person3 copy construction called"<<std::endl;
    }
    ~Person3(){
        std::cout<<"Person3 dropped"<<std::endl;
    }
    int age;

};

void class_and_obj(){
    //create object(Instantiation)
    Circle c1;
    c1.m_r = 10;
    std::cout << "Perimeter:" << c1.get_perimeter() << std::endl;

    Person p1;
    p1.m_name = "Frank";
    //p1.m_car = "Van"; //cannot use;

    Person2 P2;
    P2.setName("Tom");
    std::cout << "Name:" << P2.getName() << std::endl;
    std::cout << "Age:" << P2.getAge() << std::endl;
    P2.setId(1400);
    P2.setId(140);
    std::cout << "id:" << P2.getId() << std::endl;

    //Data on the stack.
    Person3 p2;         //Do not add parentheses, the compiler will consider it a declaration of a function.
    Person3 p3(1);
    Person3 p4(p3);

    //Do not initialize anonymous objects with copy constructors.
    Person3 p5;         //Anonymous objects will be immediately reclaimed by the system after the current line execution ends.
    Person3 p6  =Person3(10);
    Person3 p7  =Person3(p6);

    Person3 p8 = 10;
    Person3 P9 = p8;

}
void do_work(Person3 p){

}
Person3 do_work2(){
    Person3 p1;
    return p1;
}
void obj_tra(){
    Person3 p1(20);  //Person3 parametric construction called
    Person3 p2(p1);     //Person3 copy construction called
    Person3 p3;         //Person3 called
    do_work(p3);     //Person3 copy construction called
    Person3 p4 = do_work2(); //Person3 called
    std::cout<<&p4<<std::endl;
}
int main() {
//    main_cp();
//    class_and_obj();
    obj_tra();
    return 0;
}