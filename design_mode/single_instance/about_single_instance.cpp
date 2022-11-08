//
//  about_single_instance.cpp
//  CppLearn
//
//  Created by 张昊 on 2022/11/4.
//

#include "about_single_instance.hpp"



// 静态成员需要 类外显式初始化
SingleInstanceCase1* SingleInstanceCase1::m_SingleInstanceCase1 = nullptr;
std::mutex SingleInstanceCase1::m_Mutex;

// @为什么使用双检锁
// 确保第一次锁上之后到 new 实例时没有其他线程 抢先创建出对象实例
SingleInstanceCase1* SingleInstanceCase1::getInstance(){
    // 这里使用 2 个 if 判断称为 -> 双检锁
    // 只有判断指针为空的时候才加锁
    if( m_SingleInstanceCase1 == nullptr ){
        // +锁
        std::unique_lock<std::mutex> lock(m_Mutex);
        if( m_SingleInstanceCase1 == nullptr ){
            m_SingleInstanceCase1 = new SingleInstanceCase1();
        }
    }
    return m_SingleInstanceCase1;
}


void SingleInstanceCase1::Print(){
    std::cout<<"my pointer address = "<<this<<std::endl;
}

SingleInstanceCase1::SingleInstanceCase1(){}
SingleInstanceCase1::~SingleInstanceCase1(){}
