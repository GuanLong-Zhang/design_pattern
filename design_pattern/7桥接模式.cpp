//桥接模式
//将抽象部分与其实现部分进行分离，使得它们可以独立的变化，提高系统的灵活性和可扩展性
#include <iostream>

// 实现化接口
class Implementor {
public:
    virtual ~Implementor() {}
    virtual void operationImpl() = 0;
};

// 具体实现化
class ConcreteImplementorA : public Implementor {
public:
    void operationImpl() override {
        std::cout << "ConcreteImplementorA operation." << std::endl;
    }
};

class ConcreteImplementorB : public Implementor {
public:
    void operationImpl() override {
        std::cout << "ConcreteImplementorB operation." << std::endl;
    }
};

// 抽象化
class Abstraction {
protected:
    Implementor* implementor;

public:
    Abstraction(Implementor* impl) : implementor(impl) {}

    virtual ~Abstraction() {}
    virtual void operation() = 0;
};

// 具体抽象化
class RefinedAbstraction : public Abstraction {
public:
    RefinedAbstraction(Implementor* impl) : Abstraction(impl) {}

    void operation() override {
        implementor->operationImpl();
    }
};

//int main() {
//    Implementor* implA = new ConcreteImplementorA;   //父类指针指向子类对象   实现部分
//    Implementor* implB = new ConcreteImplementorB;
//
//    Abstraction* abstractionA = new RefinedAbstraction(implA);   //抽象部分
//    abstractionA->operation(); // 输出: ConcreteImplementorA operation.
//
//    Abstraction* abstractionB = new RefinedAbstraction(implB);
//    abstractionB->operation(); // 输出: ConcreteImplementorB operation.
//
//    delete abstractionA;
//    delete abstractionB;
//    delete implA;
//    delete implB;
//
//    return 0;
//}
