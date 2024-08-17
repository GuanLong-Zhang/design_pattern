//����ģʽ
//Ϊ���������ṩһ�ִ����Կ��ƶ��������ķ���
#include <iostream>

// ��������
class Subject {
public:
    virtual ~Subject() {}
    virtual void request() const = 0;
};

// ��������
class RealSubject : public Subject {
public:
    void request() const override {
        std::cout << "RealSubject handles the request." << std::endl;
    }
};

// ����
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
//    proxy->request();    //��� Proxy handles the request.\
//                                RealSubject handles the request.
//
//    return 0;
//}
