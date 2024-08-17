//代理模式
//为其他对象提供一种代理，以控制对这个对象的访问
#include <iostream>

// 抽象主题
class Subject {
public:
    virtual ~Subject() {}
    virtual void request() const = 0;
};

// 具体主题
class RealSubject : public Subject {
public:
    void request() const override {
        std::cout << "RealSubject handles the request." << std::endl;
    }
};

// 代理
class Proxy : public Subject {
private:
    RealSubject* realSubject;

public:
    Proxy() : realSubject(new RealSubject) {}

    ~Proxy() {
        delete realSubject;
    }

    void request() const override {
        std::cout << "Proxy handles the request." << std::endl;
        realSubject->request();
    }
};

//int main() {
//    Proxy* proxy = new Proxy;
//    proxy->request();    //输出 Proxy handles the request.\
//                                RealSubject handles the request.
//
//    return 0;
//}
