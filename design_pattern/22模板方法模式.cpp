//模板方法模式
//定义了一个操作中的算法框架，而将一些步骤延迟到了子类中
#include <iostream>

// 抽象类
class AbstractClass {
public:
    // 模板方法
    void templateMethod() {
        baseOperation1();
        baseOperation2();
        hook1();
        requiredOperation1();
        requiredOperation2();
        hook2();
    }

    // 这些操作有默认实现
    void baseOperation1() const {
        std::cout << "AbstractClass: Base Operation 1" << std::endl;
    }

    void baseOperation2() const {
        std::cout << "AbstractClass: Base Operation 2" << std::endl;
    }

    // 这些操作必须由子类实现
    virtual void requiredOperation1() const = 0;
    virtual void requiredOperation2() const = 0;

    // 可以由子类实现，也可以不实现
    virtual void hook1() const {}
    virtual void hook2() const {}
};

// 具体类
class ConcreteClass1 : public AbstractClass {
public:
    virtual void requiredOperation1() const override {
        std::cout << "ConcreteClass1: Implemented Operation 1" << std::endl;
    }

    virtual void requiredOperation2() const override {
        std::cout << "ConcreteClass1: Implemented Operation 2" << std::endl;
    }

    virtual void hook1() const override {
        std::cout << "ConcreteClass1: Overridden Hook 1" << std::endl;
    }
};

class ConcreteClass2 : public AbstractClass {
public:
    virtual void requiredOperation1() const override {
        std::cout << "ConcreteClass2: Implemented Operation 1" << std::endl;
    }

    virtual void requiredOperation2() const override {
        std::cout << "ConcreteClass2: Implemented Operation 2" << std::endl;
    }

    virtual void hook2() const override {
        std::cout << "ConcreteClass2: Overridden Hook 2" << std::endl;
    }
};

//int main() {
//    std::cout << "Same client code can work with different subclasses:" << std::endl;
//    ConcreteClass1 concreteClass1;
//    concreteClass1.templateMethod();
//
//    std::cout << "\n";
//
//    std::cout << "Same client code can work with different subclasses:" << std::endl;
//    ConcreteClass2 concreteClass2;
//    concreteClass2.templateMethod();
//
//    return 0;
//}
