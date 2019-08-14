//
//  main.cpp
//  TestProtobufXcode
//
//  Created by PixBoly on 2018/1/16.
//  Copyright © 2018年 pix. All rights reserved.
//

#include <iostream>
#include "addressbook.pb.h"
using namespace std;



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    tutorial::Person p;
    p.set_id(22);
    p.set_name("zhangsan");
    p.set_email("zhangsan@163.com");
    
    int length = p.ByteSize();
    char* buf = new char[length];

    // 序列化
    p.SerializeToArray(buf, length);
    
    // 反序列化
    tutorial::Person p2;
    p2.ParseFromArray(buf, length);
    cout<<"Person id:"<<p2.id()<<",name:"<<p2.name()<<",email:"<<p2.email()<<endl;
    
    return 0;
}
