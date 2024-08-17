//责任链模式
//将请求的发送者和接收者进行解耦，并允许多个对象都有机会去处理这个请求
//每个处理器对象都包含对下一个处理器对象的引用，形成一个链条
#include <iostream>
#include <string>

// 抽象处理器
class Handler {
public:
    virtual ~Handler() {}
    virtual void handleRequest(const std::string& request) = 0;   //纯虚函数
    void setNextHandler(Handler* handler) {
        nextHandler = handler;
    }

protected:
    Handler* nextHandler;
};

// 具体处理器 A
class ConcreteHandlerA : public Handler {
public:
    void handleRequest(const std::string& request) override {
        if (request == "A") {
            std::cout << "ConcreteHandlerA handles the request." << std::endl;
        }
        else if (nextHandler != nullptr) {
            nextHandler->handleRequest(request);
        }
        else {
            std::cout << "ConcreteHandlerA No handler can process the request." << std::endl;
        }
    }
};

// 具体处理器 B
class ConcreteHandlerB : public Handler {
public:
    void handleRequest(const std::string& request) override {
        if (request == "B") {
            std::cout << "ConcreteHandlerB handles the request." << std::endl;
        }
        else if (nextHandler != nullptr) {
            nextHandler->handleRequest(request);
        }
        else {
            std::cout << "ConcreteHandlerB No handler can process the request." << std::endl;
        }
    }
};

//int main() {
//    // 创建具体处理器对象
//    Handler* handlerA = new ConcreteHandlerA;   //父类指针指向子类对象
//    Handler* handlerB = new ConcreteHandlerB;
//
//    // 设置处理器链
//    handlerA->setNextHandler(handlerB);  //A的下一个处理对象为B
//
//    // 发送请求
//    handlerA->handleRequest("A"); // 输出: ConcreteHandlerA handles the request.
//    handlerA->handleRequest("B"); // 输出: ConcreteHandlerB handles the request.
//    handlerA->handleRequest("C"); // 输出: ConcreteHandlerB No handler can process the request.
//
//    // 释放资源
//    delete handlerA;
//    delete handlerB;
//
//    return 0;
//}
