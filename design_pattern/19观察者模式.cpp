//观察者模式
//定义对象间的一种一对多的依赖关系，使得当一个对象（被观察者）的状态发生变换时，所有依赖于它的\
对象（观察者）都得到通知并自动更新
#include <iostream>
#include <vector>
#include <algorithm>

// 抽象观察者类
class Observer {
public:
    virtual void update(const std::string& message) = 0;
};

// 具体观察者类
class ConcreteObserver : public Observer {
private:
    std::string name;

public:
    ConcreteObserver(const std::string& n) : name(n) {}

    virtual void update(const std::string& message) override {
        std::cout << name << " received message: " << message << std::endl;
    }
};

// 被观察者类
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
            observer->update(message);   //更新
        }
    }
};

//int main() {
//    ConcreteObserver observer1("Observer 1");   //观察者
//    ConcreteObserver observer2("Observer 2");
//
//    Subject subject;    //被观察者
//    subject.attach(&observer1);
//    subject.attach(&observer2);
//
//    subject.notify("Hello World!");   //通知观察者，并自动更新
//
//    return 0;
//}

