//������ģʽ
//��ʾһ��������ĳ����ṹ�еĸ�Ԫ�صĲ����������ڲ��ı��Ԫ�����ǰ���¶�����������ЩԪ�ص��²���
#include <iostream>
#include <vector>
#include <memory>

// ����������Ԫ���࣬�Ա��� Visitor ��ʹ��
class ConcreteElementA;
class ConcreteElementB;

// �����߽ӿ�
class Visitor {
public:
    virtual void visitConcreteElementA(ConcreteElementA* element) = 0;
    virtual void visitConcreteElementB(ConcreteElementB* element) = 0;
};

// Ԫ�ؽӿ�
class Element {
public:
    virtual ~Element() = default;
    virtual void accept(Visitor* visitor) = 0;
};

// ����Ԫ�� A
class ConcreteElementA : public Element {
public:
    void accept(Visitor* visitor) override {
        visitor->visitConcreteElementA(this);
    }

    void operationA() const {
        std::cout << "ConcreteElementA operation." << std::endl;
    }
};

// ����Ԫ�� B
class ConcreteElementB : public Element {
public:
    void accept(Visitor* visitor) override {
        visitor->visitConcreteElementB(this);
    }

    void operationB() const {
        std::cout << "ConcreteElementB operation." << std::endl;
    }
};

// ���������
class ConcreteVisitor1 : public Visitor {
public:
    void visitConcreteElementA(ConcreteElementA* element) override {
        std::cout << "ConcreteVisitor1: ";
        element->operationA();
    }

    void visitConcreteElementB(ConcreteElementB* element) override {
        std::cout << "ConcreteVisitor1: ";
        element->operationB();
    }
};

class ConcreteVisitor2 : public Visitor {
public:
    void visitConcreteElementA(ConcreteElementA* element) override {
        std::cout << "ConcreteVisitor2: ";
        element->operationA();
    }

    void visitConcreteElementB(ConcreteElementB* element) override {
        std::cout << "ConcreteVisitor2: ";
        element->operationB();
    }
};

//int main() {
//    std::vector<std::unique_ptr<Element>> elements;
//    elements.push_back(std::make_unique<ConcreteElementA>());
//    elements.push_back(std::make_unique<ConcreteElementB>());
//
//    ConcreteVisitor1 visitor1;
//    ConcreteVisitor2 visitor2;
//
//    for (auto& element : elements) {
//        element->accept(&visitor1);
//    }
//
//    std::cout << "-----------------------------------------------" << std::endl;
//
//    for (auto& element : elements) {
//        element->accept(&visitor2);
//    }
//
//    return 0;
//}
