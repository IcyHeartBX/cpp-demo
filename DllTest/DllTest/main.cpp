//
//  main.cpp
//  DllTest
//
//  Created by 唐鹏翔 on 2017/7/7.
//  Copyright © 2017年 pix. All rights reserved.
//

#include <iostream>
#include "Add.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Add add;
    cout<<add.Sum(2, 3)<<endl;
    return 0;
}
