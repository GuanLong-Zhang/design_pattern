//״̬ģʽ
//������������ڲ�״̬�����仯ʱ�ı�������Ϊ
#include <iostream>

// ��������
class Context;

// ����״̬��
class State {
public:
    virtual void handle(Context& context) = 0;
};

// ����״̬��
class ConcreteStateA : public State {
public:
    virtual void handle(Context& context) override;    //�������������ⶨ��
};

class ConcreteStateB : public State {
public:
    virtual void handle(Context& context) override;
};

// ��������
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

// ����״̬��ʵ��
void ConcreteStateA::handle(Context& context) {
    std::cout << "Handling request in State A." << std::endl;
    // �л�����һ��״̬
    context.setState(new ConcreteStateB());   //�ڲ�״̬�����ı�ʱ���ı�������Ϊ
}

void ConcreteStateB::handle(Context& context) {
    std::cout << "Handling request in State B." << std::endl;
    // �л�����һ��״̬
    context.setState(new ConcreteStateA());
}

//int main() {
//    ConcreteStateA stateA;
//    Context context(&stateA);
//
//    context.request(); // ��� "Handling request in State A."
//    context.request(); // ��� "Handling request in State B."
//    context.request(); // ��� "Handling request in State A."
//
//    return 0;
//}
