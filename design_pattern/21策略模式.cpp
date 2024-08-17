//����ģʽ
//������һϵ���㷨������ÿ���㷨��װ��������ʹ���ǿ����໥�滻
#include <iostream>
#include <memory>

// ���Խӿ�
class Strategy {
public:
    virtual ~Strategy() = default;
    virtual void execute() const = 0;
};

// ���������A
class ConcreteStrategyA : public Strategy {
public:
    virtual void execute() const override {
        std::cout << "Executing Strategy A" << std::endl;
    }
};

// ���������B
class ConcreteStrategyB : public Strategy {
public:
    virtual void execute() const override {
        std::cout << "Executing Strategy B" << std::endl;
    }
};

// ��������
class Context {
private:
    std::unique_ptr<Strategy> strategy;

public:
    Context(std::unique_ptr<Strategy> s) : strategy(std::move(s)) {}

    void setStrategy(std::unique_ptr<Strategy> s) {
        strategy = std::move(s);
    }

    void executeStrategy() const {
        strategy->execute();
    }
};

//int main() {
//    std::unique_ptr<Strategy> strategyA = std::make_unique<ConcreteStrategyA>();
//    std::unique_ptr<Strategy> strategyB = std::make_unique<ConcreteStrategyB>();
//
//    Context context(std::move(strategyA));
//    context.executeStrategy(); // ��� "Executing Strategy A"
//
//    context.setStrategy(std::move(strategyB));   //��̬�ı�ʹ��
//    context.executeStrategy(); // ��� "Executing Strategy B"
//
//    return 0;
//}
