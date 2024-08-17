//װ����ģʽ
//��̬�ĸ�������Ӷ���Ĺ��ܣ�������Ҫ�޸���ԭʼ��Ĵ���
#include <iostream>

// �������
class Component {
public:
    virtual ~Component() {}
    virtual void operation() const = 0;
};

// �������
class ConcreteComponent : public Component {
public:
    void operation() const override {
        std::cout << "ConcreteComponent operation." << std::endl;
    }
};

// ����װ����
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

// ����װ���� A
class ConcreteDecoratorA : public Decorator {
public:
    ConcreteDecoratorA(Component* comp) : Decorator(comp) {}

    void operation() const override {
        Decorator::operation();
        std::cout << "ConcreteDecoratorA operation." << std::endl;
    }
};

// ����װ���� B
class ConcreteDecoratorB : public Decorator {
public:
    ConcreteDecoratorB(Component* comp) : Decorator(comp) {}

    void operation() const override {
        Decorator::operation();
        std::cout << "ConcreteDecoratorB operation." << std::endl;
    }
};

//int main() {
//    // ���������������
//    Component* component = new ConcreteComponent;
//
//    // ��������װ�������󣬲������������װ������
//    Decorator* decoratorA = new ConcreteDecoratorA(component);
//    Decorator* decoratorB = new ConcreteDecoratorB(decoratorA);
//
//    // ����װ��������Ĳ���
//    decoratorB->operation();    //��� ConcreteComponent operation.\
//                                       ConcreteDecoratorA operation.\
//                                       ConcreteDecoratorB operation.
//
//    // �ͷ���Դ
//    delete decoratorB;
//    delete decoratorA;
//    delete component;
//
//    return 0;
//}
