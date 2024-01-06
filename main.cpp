#include <iostream>
#include "Inheritance.h"
#include "Page.h"
#include "Polymorphism.h"
#include "file.h"

const double PI = 3.14159;

int g_a = 10;  //全局区
int g_b = 10;

const int c_g_a = 10;  //全局区
const int c_g_b = 10;

//int *function(){
//    int a = 0;   //存放在栈区，在函数执行完释放
//    return &a;
//}
int *function2(){
    int * a = new int(10);   //开辟到堆区,指针本质也是局部变量，放在栈上，指针保存的数据是放在堆区
    return a;
}
int test()   //测试不同的变量在内存区域中的位置
{
    int a = 10;   //栈区
    int b = 10;

    static int s_a = 10;  //全局区
    static int s_b = 10;

    const int c_l_a = 10; //栈区
    const int c_l_b = 10;

    std::cout<< &a << std::endl;  //栈区，局部变量
    std::cout<< &b << std::endl;

    std::cout<< &g_a << std::endl;  //全局区，全局变量
    std::cout<< &g_b << std::endl;

    std::cout<< &s_a << std::endl;  //全局区，静态变量
    std::cout<< &s_b << std::endl;

    std::cout<<&"Hello World"<<std::endl;  //全局区，字符串常量

    std::cout<< &c_g_a << std::endl;  //全局区，const修饰的全局常量
    std::cout<< &c_g_b << std::endl;

    std::cout<< &c_l_a << std::endl;  //栈区，const修饰的局部变量
    std::cout<< &c_l_a << std::endl;

    return 0;
}

void test01(){
    int *pInt = function2();   //堆区的数据不自动释放
    std::cout<< *pInt << std::endl;
    std::cout<< *pInt << std::endl;
    delete pInt;               //主动释放
//    std::cout<< *pInt << std::endl;  //无法输出

}

void test02(){
    int *arr = new int[10];
    for (int i = 0;i<10;i++) {
        arr[i] = i+10*i;
    }
    for (int i = 0; i < 10; i++) {
        std::cout<<arr[i]<<std::endl;
    }
    delete[] arr;   //释放连续的空间

}

void new_name(){
    //别名
    int a = 10;
    int &b = a;   //引用
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
//2.3引用传递，让形参修饰实参，
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
void func3(int a, int){
    std::cout<<"this!"<<std::endl;
}
void main_cp(){
    test();
//    int *p = function();
//    std::cout<< *p << std::endl; //数据在函数结束后释放，无法调用
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
    std::string name;       //可读可写
    int age = 20;           //只读
    int id;                 //可读可写(必须在0-1000之间)
    std::string idol;       //只写

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
            std::cout<<"id error！"<<std::endl;
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
//4.2.5
class Person4{
public:
    Person4(){
        std::cout<<"Person4 called"<<std::endl;
    }
    Person4(int a, int h){
        age = a;
        height = new int(h);  //Release heap data before object destruction
        std::cout<<"Person4 parametric construction called"<<std::endl;
    }
    Person4(const Person4 &p){
        age = p.age;
        //Modify default implementation
        height = new int(*p.height);
        std::cout<<"Person3 copy construction called"<<std::endl;
    }
    ~Person4(){
        //The code of the destructor function is used to release the data we have opened in the heap area
        if (height != nullptr){
            delete height;
            height = nullptr;
        }
        std::cout<<"Person4 dropped"<<std::endl;
    }
    int age;
    int *height;

};
//The data in the stack here is first in and last out.
//If the compiler provides a copy constructor, a shallow copy operation will be performed, only copying the address of the data in the heap area.
void test05(){
    Person4 p1(18,160);
    std::cout<<"p1.age:"<<p1.age<<"  p1.height:"<<*p1.height<<std::endl;
    Person4 p2(p1);
    std::cout<<"p2.age:"<<p2.age<<"  p2.height:"<<*p2.height<<std::endl;
}
//4.2.6
class Test{
public:
    //Traditional initialization operation
//    Test(int a,int b,int c){
//        this->a = a;
//        this->b = b;
//        this->c = c;
//    }
    //new method,Null constructor.
    Test(int a,int b,int c):a(a),b(b),c(c){

    }
    int a,b,c;
};
void test06(){
    Test t(30,20,10);
    std::cout<<"t.a:"<<t.a<<" t.b:"<<t.b<<" t.c:"<<t.c<<std::endl;
}
//4.2.8
class Person5{
public:
    Person5(){
        std::cout<<"Person5 called"<<std::endl;
    }
    Person5(int a, int h){
        age = a;
        height = new int(h);  //Release heap data before object destruction
        std::cout<<"Person5 parametric construction called"<<std::endl;
    }
    Person5(const Person5 &p){
        age = p.age;
        //Modify default implementation
        height = new int(*p.height);
        std::cout<<"Person5 copy construction called"<<std::endl;
    }
    ~Person5(){
        //The code of the destructor function is used to release the data we have opened in the heap area
        if (height != nullptr){
            delete height;
            height = nullptr;
        }
        std::cout<<"Person5 dropped"<<std::endl;
    }
    static int age;
    int *height;

    static void func(){
        age = 50;
        std::cout<< "static function called"<< std::endl;
    }

};
int Person5::age = 20;
void test07(){
    Person5 person5;
    std::cout<<person5.age<<std::endl;
    Person5 p2;
    p2.age = 30;
    std::cout<<person5.age<<std::endl;
    std::cout<<Person5::age<<std::endl;
    person5.func();
    Person5::func();
    std::cout<<person5.age<<std::endl;
}
//4.3.1
class Person6{
public:
//    Person6(){
//        std::cout<<"Person6 called"<<std::endl;
//    }
//    Person6(int a, int h){
//        age = a;
//        height = new int(h);  //Release heap data before object destruction
//        std::cout<<"Person6 parametric construction called"<<std::endl;
//    }
//    Person6(const Person6 &p){
//        age = p.age;
//        //Modify default implementation
//        height = new int(*p.height);
//        std::cout<<"Person6 copy construction called"<<std::endl;
//    }
//    ~Person6(){
//        //The code of the destructor function is used to release the data we have opened in the heap area
//        if (height != nullptr){
//            delete height;
//            height = nullptr;
//        }
//        std::cout<<"Person6 dropped"<<std::endl;
//    }
        int age;
//    int *height;
//
//    static void func(){
//        age = 50;
//        std::cout<< "static function called"<< std::endl;
//    }

};
void test08(){
    Person6 p;
    //Empty objects occupy memory size of 1B
    std::cout<< sizeof(p)<<std::endl;

}
//4.3.2
class Test2{
public:
    //Traditional initialization operation
    Test2(int a,int b,int c){
        this->a = a;
        this->b = b;
        this->c = c;
    }
    int a,b,c;
    //Return the form of a reference
    Test2& add(Test2 &p){
        this->a += p.a;
        return *this;
    }
};
void test09(){
    Test2 t1(30,20,10);
    Test2 t2(30,20,10);
    //Chain programming idea.
    t2.add(t1).add(t1).add(t1).add(t1).add(t1);
    std::cout<<"t2.a:"<<t2.a<<" t2.b:"<<t2.b<<" t2.c:"<<t2.c<<std::endl;
}
//4.3.3
class Test3{
public:
    void ShowClassName(){
        std::cout<<"Test3"<<std::endl;
    }
    void ShowTestA(){
        if (this == nullptr){
            return;
        }
        std::cout<<this->a<<std::endl;
    };
    int a;
};
void test10(){
    Test3 *p = nullptr;
    p->ShowClassName();
    p->ShowTestA();   //The pointer passed in is empty and the variable cannot be accessed.
}
//4.3.4
class Test4{
public:
//'this' pointer is essentially a pointer constant, and the direction it points to cannot be modified.Its value can be modified.
    void showT() const {
//        this = nullptr;
        this->b = 100;
        std::cout<< this->b<<std::endl;
    }
    int a;
    mutable int b;
};
void test11(){
    const Test4 t{};
    t.showT();
    t.b = 200;
    std::cout<< t.b<<std::endl;
}
//4.4.1
class Building{
    friend void GoodFriend1(Building &building);
public:
    std::string SittingRoom;

    Building(){
        SittingRoom = "SittingRoom";
        BedRoom = "BedRoom";
    }

private:
    std::string BedRoom;
};
void GoodFriend1(Building &building){
    std::cout<<"Good friend is visiting "<< building.SittingRoom << "." <<std::endl;
    std::cout<<"Good friend is visiting "<< building.BedRoom << "." <<std::endl;
}
void test12(){
    Building b;
    GoodFriend1(b);
}
//4.4.2
class Building2{
//    friend void GoodFriend(Building &building);
    friend class GoodFriend;
public:
    std::string SittingRoom;

    Building2(){
        SittingRoom = "SittingRoom";
        BedRoom = "BedRoom";
    }

private:
    std::string BedRoom;
};
class GoodFriend{
public:
    GoodFriend(){
        this->building = new Building2;
    }
    void visit(){
        std::cout<<"Good friend is visiting "<< building->SittingRoom << "." <<std::endl;
        std::cout<<"Good friend is visiting "<< building->BedRoom << "." <<std::endl;
    }

    Building2* building;
};
void test13(){
    GoodFriend f;
    f.visit();
}
//4.4.3
class Building3;
class GoodFriend2{
public:
    GoodFriend2();
    void visit();

    Building3* building;
};
class Building3{
//    friend void GoodFriend(Building &building);
//    friend class GoodFriend;
    friend void GoodFriend2::visit();
public:
    std::string SittingRoom;

    Building3(){
        SittingRoom = "SittingRoom";
        BedRoom = "BedRoom";
    }

private:
    std::string BedRoom;
};
GoodFriend2::GoodFriend2(){
    this->building = new Building3;
}
void GoodFriend2::visit(){
    std::cout<<"Good friend is visiting "<< building->SittingRoom << "." <<std::endl;
    std::cout<<"Good friend is visiting "<< building->BedRoom << "." <<std::endl;
}
void test14(){
    GoodFriend2 f;
    f.visit();
}
void Test(){
    test14();
    test13();
    test12();
    test11();
    class_and_obj();
    obj_tra();
    test05();
    test06();
    test07();
    test08();
    test09();
    test10();
}
//4.5.1
class Obj{
public:
    int a;
    int b;
// first method ,member function
//    Obj operator+(Obj obj){
//        Obj temp;
//        temp.a = this->a + obj.a;
//        temp.b = this->b + obj.b;
//        return temp;
//    }
};
//second method,global function
Obj operator+(Obj p1,Obj p2){
    Obj temp;
    temp.a = p1.a + p2.a;
    temp.b = p1.b + p2.b;
    return temp;
}
void add(){
    Obj o1;
    o1.a = 10;
    o1.b = 10;
    Obj o2;
    o2.a = 4;
    o2.b = 7;
    Obj o3 = o1 + o2;
    std::cout<< "o3.a:" << o3.a << " o3.b:" << o3.b << std::endl;
}
//4.5.2
//Chain programming
std::ostream & operator<<(std::ostream &out , Obj o){
    out<< "a:" << o.a << " b:" << o.b;
    return out;
}
void out(){
    Obj o;
    o.a = 10;
    o.b = 10;
    std::cout<<o<<std::endl;
}
//4.5.3
class MyInteger{
    friend std::ostream & operator<<(std::ostream &out , MyInteger o);
public:
    MyInteger(){
        num = 0;
    }
    //Overloading pre ++operators
    MyInteger& operator++(){
        num++;
        return *this;
    }
    //The int here is a placeholder parameter that can be used to distinguish between pre increment and post increment.
    MyInteger operator++(int){
        MyInteger temp = *this;
        num++;
        return temp;
    }
private:
    int num;
};
std::ostream & operator<<(std::ostream &out , MyInteger o){
    out<< "num:" << o.num ;
    return out;
}
void add_add(){
    MyInteger myInteger;
    std::cout<<++myInteger<< std::endl;
    std::cout<<myInteger<< std::endl;
    std::cout<<myInteger++<< std::endl;
    std::cout<<myInteger<< std::endl;
}
//4.5.4
class Persons{
public:
    Persons(int age){
        this->age = new int (age);
    }
    ~Persons(){
        if(age != nullptr){
            delete age;
            age = nullptr;
        }
    }
    Persons& operator=(Persons &p){
        //check if there are any attributes in the heap area firstly. If so, release them thoroughly before making a deep copy.
        if (age != nullptr){
            delete age;
            age = nullptr;
        }
        this->age = new int (*p.age);
        return *this;
    }
    int *age;
};
void equals(){
    Persons p1(18);
    std::cout<<"p1.age:"<<*p1.age<<std::endl;
    Persons p2(20);
    Persons p3(30);
    p3 = p2 = p1;
    std::cout<<"p2.age:"<<*p2.age<<std::endl;
    std::cout<<"p3.age:"<<*p3.age<<std::endl;
}
//4.5.6
class MyPrint{
public:
    void operator()(std::string test){
        std::cout<< test << std::endl;
    }
};
class MyAdd{
public:
    int operator()(int a,int b){
        return a+b;
    }
};
void testfunc(){
    MyPrint m;
    m("Hellow World");
    MyAdd add1;
    std::cout<< add1(100,66) << std::endl;

    //Anonymous object, destroyed after executing the current line, suitable for performing addition
    std::cout<< MyAdd()(100,56) << std::endl;
}

void overload(){
    testfunc();
//    equals();
//    add_add();
//    add();
//    out();
}
void tset_inher01(){
    Java java;
    java.header();
    java.bottom();
    java.left();
    java.content();
    std::cout<< "------------------------" << std::endl;
    Python python;
    python.header();
    python.bottom();
    python.left();
    python.content();
    std::cout<< "------------------------" << std::endl;
    CPP cpp;
    cpp.header();
    cpp.bottom();
    cpp.left();
    cpp.content();
}
void Test_Inheritance(){
    tset_inher01();
}
int main() {
//    testAct();
//    Test_Inheritance();
//    test_file1();
    test_file2();
//    main_cp();
//    Test();
//    overload();
    return 0;
}
