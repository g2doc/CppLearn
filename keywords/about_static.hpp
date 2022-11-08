//
//  about_static.hpp
//  CppLearn
//
//  Created by 张昊 on 2022/11/3.
//

#ifndef about_static_hpp
#define about_static_hpp

#include <stdio.h>


/** C++ 中的 static
 类:
 1. 静态成员变量
    => 静态成员变量属于 所有类, 存放在静态区,
    非静态成员变量的存放和 类实例的空间有关: if 类实例在堆上, 该成员变量就存放在 堆上
    类空间实例在栈上, 该成员变量就存放在 栈上
 2. 静态函数
 
 
 */


/** 使用 static 的情况
 1. 需要一个数据对象为 整个类 而非某一个对象服务, 同时又力求不破坏类的封装性, 即 => 要求此成员隐藏在类的内部, 对外不可见, 也就是常见的 public 获取 private 成员的 case
 2.
 */
//e.g.
class TestStaticCase1{
public:
    int getVal(){return val;}
    
private:
    int val = 10;
};
// printf("%d\r\n", TestStaticCase1().getVal());


#endif /* about_static_hpp */
