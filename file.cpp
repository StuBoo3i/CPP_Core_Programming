//
// Created by Frank on 2024/1/6.
//

#include "file.h"
#include <fstream>
#include <iostream>

void test_file1(){
    std::ofstream ofs;
    ofs.open("text.txt",std::ios::out);

    if (!ofs.is_open()){
        std::cout<<"fail!"<<std::endl;
    }
    //write data
    ofs<<"Hi World"<<std::endl;


}
void test_file2(){
    std::ifstream ifs;
    ifs.open("text.txt",std::ios::in);

    if (!ifs.is_open()){
        std::cout<<"fail!"<<std::endl;
    }
    //read data
    //1
    char buf[1024] = {0};
    while (ifs>>buf){
        std::cout<<buf<<std::endl;
    }
    //2
    char buf2[1024] = {0};
    while (ifs.getline(buf2,1024)){
        std::cout<<buf2<<std::endl;
    }
    //3
    std::string buf3;
    while (getline(ifs,buf3)){
        std::cout<<buf3<<std::endl;
    }
    //4
//    char c;
//    while (c = ifs.get()){
//        std::cout<<c;
//    }

}
