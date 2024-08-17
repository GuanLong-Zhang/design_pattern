//�۲���ģʽ
//���������һ��һ�Զ��������ϵ��ʹ�õ�һ�����󣨱��۲��ߣ���״̬�����任ʱ����������������\
���󣨹۲��ߣ����õ�֪ͨ���Զ�����
#include <iostream>
#include <vector>
#include <algorithm>

// ����۲�����
class Observer {
public:
    virtual void update(const std::string& message) = 0;
};

// ����۲�����
class ConcreteObserver : public Observer {
private:
    std::string name;

public:
    ConcreteObserver(const std::string& n) : name(n) {}

    virtual void update(const std::string& message) override {
        std::cout << name << " received message: " << message << std::endl;
    }
};

// ���۲�����
class Subject {
private:
    std::vector<Observer*> observers;

public:
    void attach(Observer* observer) {
        observers.push_back(observer);
    }

    void detach(Observer* observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notify(const std::string& message) {
        for (auto observer : observers) {
            observer->update(message);   //����
        }
    }
};

//int main() {
//    ConcreteObserver observer1("Observer 1");   //�۲���
//    ConcreteObserver observer2("Observer 2");
//
//    Subject subject;    //���۲���
//    subject.attach(&observer1);
//    subject.attach(&observer2);
//
//    subject.notify("Hello World!");   //֪ͨ�۲��ߣ����Զ�����
//
//    return 0;
//}

