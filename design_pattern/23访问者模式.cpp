//访问者模式
//表示一个作用于某对象结构中的各元素的操作，可以在不改变各元素类的前提下定义作用于这些元素的新操作
#include <iostream>
#include <vector>
#include <memory>

// 先声明具体元素类，以便在 Visitor 中使用
class ConcreteElementA;
class ConcreteElementB;

// 访问者接口
class Visitor {
public:
    virtual void visitConcreteElementA(ConcreteElementA* element) = 0;
    virtual void visitConcreteElementB(ConcreteElementB* element) = 0;
};

// 元素接口
class Element {
public:
    virtual ~Element() = default;
    virtual void accept(Visitor* visitor) = 0;
};

// 具体元素 A
class ConcreteElementA : public Element {
public:
    void accept(Visitor* visitor) override {
        visitor->visitConcreteElementA(this);
    }

    void operationA() const {
        std::cout << "ConcreteElementA operation." << std::endl;
    }
};

// 具体元素 B
class ConcreteElementB : public Element {
public:
    void accept(Visitor* visitor) override {
        visitor->visitConcreteElementB(this);
    }

    void operationB() const {
        std::cout << "ConcreteElementB operation." << std::endl;
    }
};

// 具体访问者
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
