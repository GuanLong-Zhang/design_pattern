//�Ž�ģʽ
//�����󲿷�����ʵ�ֲ��ֽ��з��룬ʹ�����ǿ��Զ����ı仯�����ϵͳ������ԺͿ���չ��
#include <iostream>

// ʵ�ֻ��ӿ�
class Implementor {
public:
    virtual ~Implementor() {}
    virtual void operationImpl() = 0;
};

// ����ʵ�ֻ�
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

// ����
class Abstraction {
protected:
    Implementor* implementor;

public:
    Abstraction(Implementor* impl) : implementor(impl) {}

    virtual ~Abstraction() {}
    virtual void operation() = 0;
};

// �������
class RefinedAbstraction : public Abstraction {
public:
    RefinedAbstraction(Implementor* impl) : Abstraction(impl) {}

    void operation() override {
        implementor->operationImpl();
    }
};

//int main() {
//    Implementor* implA = new ConcreteImplementorA;   //����ָ��ָ���������   ʵ�ֲ���
//    Implementor* implB = new ConcreteImplementorB;
//
//    Abstraction* abstractionA = new RefinedAbstraction(implA);   //���󲿷�
//    abstractionA->operation(); // ���: ConcreteImplementorA operation.
//
//    Abstraction* abstractionB = new RefinedAbstraction(implB);
//    abstractionB->operation(); // ���: ConcreteImplementorB operation.
//
//    delete abstractionA;
//    delete abstractionB;
//    delete implA;
//    delete implB;
//
//    return 0;
//}
