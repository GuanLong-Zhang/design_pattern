//适配器模式
//将现有类的接口转换为客户端所期待的接口，以适配不兼容的接口
#include <iostream>

// 目标接口（客户端所期望的接口）
class TargetInterface {
public:
    virtual ~TargetInterface() {}
    virtual void request() const = 0;    //常量成员函数，即在函数体内不能修改对象的成员变量
};

// 适配者（现有的类的接口）
class Adaptee {
public:
    void specificRequest() const {
        std::cout << "Adaptee's specific request." << std::endl;
    }
};

// 适配器
class Adapter : public TargetInterface {
private:
    Adaptee* adaptee;

public:
    Adapter(Adaptee* adaptee) : adaptee(adaptee) {}

    void request() const override {
        adaptee->specificRequest();
    }
};

//int main() {
//
//    Adaptee* adaptee = new Adaptee;   //现有类接口
//    TargetInterface* targetInterface = new Adapter(adaptee);   //目标类接口
//    targetInterface->request();   // 输出: Adaptee's specific request.
//
//    delete adaptee;
//    delete targetInterface;
//
//    return 0;
//}
