//
// Created by Frank on 2024/1/6.
//

#ifndef STUDY2_PAGE_H
#define STUDY2_PAGE_H
#include <iostream>
using namespace std;

class Page {
public:
    void header(){
        cout<<"First Page , Public Courses , log on , register...(Public Header)"<<endl;
    }
    void bottom(){
        cout<<"Help center , Cooperation , Map...(Public Bottom)"<<endl;
    }
    void left(){
        cout<<"Java , Python , C++...(Shared Classification List)"<<endl;
    }
};


#endif //STUDY2_PAGE_H
