//状态模式
//允许对象在其内部状态发生变化时改变它的行为
#include <iostream>

// 上下文类
class Context;

// 抽象状态类
class State {
public:
    virtual void handle(Context& context) = 0;
};

// 具体状态类
class ConcreteStateA : public State {
public:
    virtual void handle(Context& context) override;    //类内声明，类外定义
};

class ConcreteStateB : public State {
public:
    virtual void handle(Context& context) override;
};

// 上下文类
class Context {
private:
    State* state;

public:
    Context(State* s) : state(s) {}

    void setState(State* s) {
        state = s;
    }

    void request() {
        state->handle(*this);
    }
};

// 具体状态类实现
void ConcreteStateA::handle(Context& context) {
    std::cout << "Handling request in State A." << std::endl;
    // 切换到下一个状态
    context.setState(new ConcreteStateB());   //内部状态发生改变时，改变它的行为
}

void ConcreteStateB::handle(Context& context) {
    std::cout << "Handling request in State B." << std::endl;
    // 切换到上一个状态
    context.setState(new ConcreteStateA());
}

//int main() {
//    ConcreteStateA stateA;
//    Context context(&stateA);
//
//    context.request(); // 输出 "Handling request in State A."
//    context.request(); // 输出 "Handling request in State B."
//    context.request(); // 输出 "Handling request in State A."
//
//    return 0;
//}
