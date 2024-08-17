//外观模式
//提供一个统一的接口，用于访问子系统中的一组接口，以简化客户端的使用
#include <iostream>

// 子系统 A
class SubsystemA {
public:
    void operationA() const {
        std::cout << "SubsystemA operation." << std::endl;
    }
};

// 子系统 B
class SubsystemB {
public:
    void operationB() const {
        std::cout << "SubsystemB operation." << std::endl;
    }
};

// 外观
class Facade {
private:
    SubsystemA* subsystemA;
    SubsystemB* subsystemB;

public:
    Facade(SubsystemA* subA, SubsystemB*subB):subsystemA(subA),subsystemB(subB){}

    void operation() const {
        std::cout << "Facade operation:" << std::endl;
        subsystemA->operationA();
        subsystemB->operationB();
    }
};

//int main() {
//    SubsystemA* subA = new SubsystemA;   //子系统对象
//    SubsystemB* subB = new SubsystemB;
//    Facade* fa = new Facade(subA, subB);  //统一接口
//    fa->operation();   //输出 Facade operation:\
//                              SubsystemA operation.\
//                              SubsystemB operation.
//
//    delete subA;
//    delete subB;
//    delete fa;
//
//    return 0;
//}
