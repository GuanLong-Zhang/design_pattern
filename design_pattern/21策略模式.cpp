//策略模式
//定义了一系列算法，并将每个算法封装起来，并使它们可以相互替换
#include <iostream>
#include <memory>

// 策略接口
class Strategy {
public:
    virtual ~Strategy() = default;
    virtual void execute() const = 0;
};

// 具体策略类A
class ConcreteStrategyA : public Strategy {
public:
    virtual void execute() const override {
        std::cout << "Executing Strategy A" << std::endl;
    }
};

// 具体策略类B
class ConcreteStrategyB : public Strategy {
public:
    virtual void execute() const override {
        std::cout << "Executing Strategy B" << std::endl;
    }
};

// 上下文类
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
//    context.executeStrategy(); // 输出 "Executing Strategy A"
//
//    context.setStrategy(std::move(strategyB));   //动态改变使用
//    context.executeStrategy(); // 输出 "Executing Strategy B"
//
//    return 0;
//}
