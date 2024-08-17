//备忘录模式
//在不破坏封装的情况下,捕获对象的内部状态，并在对象之外保存这个状态,并在之后恢复这个状态
#include <iostream>
#include <string>

// 备忘录类
class Memento {
private:
    std::string state;

public:
    Memento(){}
    Memento(const std::string& s) : state(s) {}

    std::string getState() const {
        return state;
    }
};

// 发起人类
class Originator {
private:
    std::string state;

public:
    void setState(const std::string& s) {
        state = s;
    }

    std::string getState() const {
        return state;
    }

    Memento createMemento() {
        return Memento(state);
    }

    void restoreMemento(const Memento& m) {
        state = m.getState();
    }
};

// 管理者类
class Caretaker {
private:
    Memento memento;

public:
    Caretaker() {}

    void saveMemento(const Memento& m) {
        memento = m;   
    }

    Memento retrieveMemento() const {
        return memento;
    }
};

//int main() {
//    Originator originator;  //备忘录对象
//    Caretaker caretaker;    //管理者对象
//
//    originator.setState("State 1");
//    std::cout << "Current state: " << originator.getState() << std::endl;
//
//    // 保存当前状态  本质上保存的是包含状态的对象
//    caretaker.saveMemento(originator.createMemento());
//
//    // 修改状态
//    originator.setState("State 2");
//    std::cout << "Modified state: " << originator.getState() << std::endl;
//
//    // 恢复到之前保存的状态
//    originator.restoreMemento(caretaker.retrieveMemento());
//    std::cout << "Restored state: " << originator.getState() << std::endl;
//
//    return 0;
//}
