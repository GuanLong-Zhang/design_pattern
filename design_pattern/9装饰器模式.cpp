//装饰器模式
//动态的给对象添加额外的功能，而不需要修改其原始类的代码
#include <iostream>

// 抽象组件
class Component {
public:
    virtual ~Component() {}
    virtual void operation() const = 0;
};

// 具体组件
class ConcreteComponent : public Component {
public:
    void operation() const override {
        std::cout << "ConcreteComponent operation." << std::endl;
    }
};

// 抽象装饰器
class Decorator : public Component {
protected:
    Component* component;

public:
    Decorator(Component* comp) : component(comp) {}

    void operation() const override {
        if (component != nullptr) {
            component->operation();
        }
    }
};

// 具体装饰器 A
class ConcreteDecoratorA : public Decorator {
public:
    ConcreteDecoratorA(Component* comp) : Decorator(comp) {}

    void operation() const override {
        Decorator::operation();
        std::cout << "ConcreteDecoratorA operation." << std::endl;
    }
};

// 具体装饰器 B
class ConcreteDecoratorB : public Decorator {
public:
    ConcreteDecoratorB(Component* comp) : Decorator(comp) {}

    void operation() const override {
        Decorator::operation();
        std::cout << "ConcreteDecoratorB operation." << std::endl;
    }
};

//int main() {
//    // 创建具体组件对象
//    Component* component = new ConcreteComponent;
//
//    // 创建具体装饰器对象，并将组件对象传入装饰器中
//    Decorator* decoratorA = new ConcreteDecoratorA(component);
//    Decorator* decoratorB = new ConcreteDecoratorB(decoratorA);
//
//    // 调用装饰器对象的操作
//    decoratorB->operation();    //输出 ConcreteComponent operation.\
//                                       ConcreteDecoratorA operation.\
//                                       ConcreteDecoratorB operation.
//
//    // 释放资源
//    delete decoratorB;
//    delete decoratorA;
//    delete component;
//
//    return 0;
//}
