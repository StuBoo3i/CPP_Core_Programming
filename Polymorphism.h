//
// Created by Frank on 2024/1/6.
//

#ifndef STUDY2_POLYMORPHISM_H
#define STUDY2_POLYMORPHISM_H
#include <iostream>

using namespace std;

class animal{
public:
    virtual void act(){
        cout<<"Animals are roaring."<<endl;
    }
};
class cat : public animal{
public:
    void act(){
        cout<<"Cats are eating."<<endl;
    }
};
class dog : public animal{
public:
    void act(){
        cout<<"Dogs are exclaiming."<<endl;
    }
};
/*amimal &a = c;地址早绑定，在编译阶段就确定了函数地址。
 * 如果想让猫有动作，就不能早绑定，需要在运行阶段进行绑定。
 * 动态多态满足条件
 * 1.有继承关系
 * 2.子类重写父类虚函数
 * 重写：函数的返回值类型，函数名，参数列表要完全相同。
 * 子类重写的虚函数的virtual可写可不写
 */
void doAct(animal &a){
    a.act();
}
void testAct(){
    cat c;
    doAct(c);
    dog d;
    doAct(d);

}

#endif //STUDY2_POLYMORPHISM_H
