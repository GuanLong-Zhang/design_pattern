//������ģʽ
//������ķ����ߺͽ����߽��н���������������л���ȥ�����������
//ÿ�����������󶼰�������һ����������������ã��γ�һ������
#include <iostream>
#include <string>

// ��������
class Handler {
public:
    virtual ~Handler() {}
    virtual void handleRequest(const std::string& request) = 0;   //���麯��
    void setNextHandler(Handler* handler) {
        nextHandler = handler;
    }

protected:
    Handler* nextHandler;
};

// ���崦���� A
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

// ���崦���� B
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
//    // �������崦��������
//    Handler* handlerA = new ConcreteHandlerA;   //����ָ��ָ���������
//    Handler* handlerB = new ConcreteHandlerB;
//
//    // ���ô�������
//    handlerA->setNextHandler(handlerB);  //A����һ���������ΪB
//
//    // ��������
//    handlerA->handleRequest("A"); // ���: ConcreteHandlerA handles the request.
//    handlerA->handleRequest("B"); // ���: ConcreteHandlerB handles the request.
//    handlerA->handleRequest("C"); // ���: ConcreteHandlerB No handler can process the request.
//
//    // �ͷ���Դ
//    delete handlerA;
//    delete handlerB;
//
//    return 0;
//}
