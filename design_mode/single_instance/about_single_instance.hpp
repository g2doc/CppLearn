//
//  about_single_instance.hpp
//  CppLearn
//
//  Created by 张昊 on 2022/11/4.
//

#ifndef about_single_instance_hpp
#define about_single_instance_hpp

#include <stdio.h>


#include <iostream>

/** 单例模式
 单例模式是指在 整个系统的生命周期内:
    保证一个类只能产生一个实例对象,  确保该类的唯一性 !!!
 
 为什么使用单例模式 ?
    => 保证线程安全
 
 什么是线程安全 ?
    => 在拥有共享数据的 多条线程并行执行的程序中, 线程安全的代码会通过 同步机制 保证每一个线程都可以正常且正确的执行, 不会出现数据污染的情况.
 
 如何保证线程安全 ?
    1. 给共享的资源 + 锁，保证每一个资源变量 每时每刻 至多被一个线程占用
    2. 让线程也拥有资源, 进而不需要去共享进程中的资源, e.g: 使用 threadlocal 可以为每一个线程维护一个私有的本地变量
 
 单例模式分类:
    1. 懒汉式单例 => 系统运行时, 实例并不存在, 只有当需要使用该单例时, 才会去创建并使用该实例,
        => 这种方式要考虑线程安全, 创建单例对象时存在竞态
    2. 饿汉式单例 => 系统一运行, 就会初始化并创建实例, 当有需要的时候直接调用即可,
        => 这种方式本身就线程安全, 不存在多线程的 线程安全问题.
 
 
 单例类的特点:
    1. 构造函数 和 析构函数 为私有类型, => 目的是禁止外部构造和析构
    2. 拷贝构造函数  和  赋值构造函数 是私有类型, => 目的是禁止外部拷贝和赋值, 确保实例的唯一性
    3. 单例类中有一个获取实例的 静态方法, 可以全局访问
 
 */

// @单例模式实现

// @1-加锁的懒汉式实现
class SingleInstanceCase1{
public:
    // 获取单例对象
    static SingleInstanceCase1* getInstance();
    
    // 释放单例对象, 进程退出时调用
    static void deleteInstance();
    
    // 打印实例对象的地址
    void Print();
    
private:
    // 将构造和析构设置私有, 禁止外部调用
    SingleInstanceCase1();
    ~SingleInstanceCase1();

private:
    // 唯一单实例对象指针
    static SingleInstanceCase1* m_SingleInstanceCase1;
    // 锁
    static std::mutex m_Mutex;
    
};


#endif /* about_single_instance_hpp */
