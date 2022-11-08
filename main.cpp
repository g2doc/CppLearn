//
//  main.cpp
//  CppLearn
//
//  Created by 张昊 on 2022/11/3.
//


#include <iostream>

// #include "memory/pointer/shared_ptr/about_shared_ptr.hpp"


// 测试 C++ 的私有静态数据成员的使用和访问权限
/** 设计原则
 类内的私有成员不允许在类外进行访问, 通常情况下, 类的成员变量建议使用 protected 或者 private 修饰
 => 避免外部接口能够直接操作类的成员变量 => 体现封装性
 
 如果在类的外部想要对类内部的变量进行读取 和 修改, => 应当显式的声明 public 接口, 在接口里对私有成员进行访问
 
 C++ 中使用 static 修饰类的数据成员 => 表明对该类而言, 所有对象的这个数据成员都只有一个实例, 即 该数据实例归所有类的对象所共有!
 */

class TestPrivateStatic{
public:
    int getA(){return a;}
    int getB(){return b;}
private:
    int a = 10;
    static int b;
    static int funcGetB(){return b;}
};

// 除了 const static, 其他的 static member 需要在类外完成类的初始化
int TestPrivateStatic::b = 20;


#include "keywords/about_static.hpp"
#include "design_mode/single_instance/about_single_instance.hpp"
#include "basic/operator/bit_operator/about_bit_operator.hpp"

#define TEST_PRINT_PARAM(PARAM) \
{\
printf("PARAM = %s \r\n", #PARAM);\
}

// C++ 的静态函数可以继承 and 覆盖, 但是不能是虚函数
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    TestPrivateStatic t;
    printf("%d\r\n", t.getA());
    printf("%d\r\n", t.getB());
    // printf("%d\r\n", TestPrivateStatic::funcGetB());
    printf("%d\r\n", TestStaticCase1().getVal());
    // printf("name %s\r\n", #t);
    // #修饰参数只能用来修饰带参宏函数, 也可以传入未定义的参数,,,
    auto test = new TestPrivateStatic();
    TEST_PRINT_PARAM(VehicleMain);
    
    auto single_instance_case1 = SingleInstanceCase1::getInstance();
    single_instance_case1->Print();
    
    auto single_instance_case2 = SingleInstanceCase1::getInstance();
    single_instance_case2->Print();
    
    
    // test_shared_ptr_case_1();
    
    
    return 0;
}


// define 的定义可以连接字符串,
