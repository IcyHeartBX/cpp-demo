//
//  main.cpp
//  AddTest
//
//  Created by 唐鹏翔 on 2017/7/7.
//
//

#include <iostream>
#include "Add.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int a = 3;
    int b = 4;
    Add add;
    cout<<a<<" + "<<b<<" = "<<add.Sum(a, b)<<endl;
    return 0;
}
