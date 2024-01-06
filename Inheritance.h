//
// Created by Frank on 2024/1/6.
//
//4.6.1
#ifndef STUDY2_INHERITANCE_H
#define STUDY2_INHERITANCE_H
#include <iostream>
#include "Page.h"
using namespace std;
class Java :public Page
{
public:
    void content(){
        cout<<"Subject video of Java"<<endl;
    }
};
class Python:public Page{
public:
    void content(){
        cout<<"Subject video of Python"<<endl;
    }
};
class CPP:public Page{
public:
    void content(){
        cout<<"Subject video of C++"<<endl;
    }
};
#endif //STUDY2_INHERITANCE_H
