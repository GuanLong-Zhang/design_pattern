//命令模式
//将一个请求封装为一个对象，从而可以使用不同的请求、队列或者日志来参数化其他对象
#include <iostream>
#include <vector>

// 命令接口
class Command {
public:
    virtual ~Command() {}
    virtual void execute() const = 0;
};

// 具体命令 A
class ConcreteCommandA : public Command {
private:
    std::string message;

public:
    ConcreteCommandA(const std::string& msg) : message(msg) {}

    void execute() const override {
        std::cout << "ConcreteCommandA: " << message << std::endl;
    }
};

// 具体命令 B
class ConcreteCommandB : public Command {
private:
    std::string action;

public:
    ConcreteCommandB(const std::string& act) : action(act) {}

    void execute() const override {
        std::cout << "ConcreteCommandB: " << action << std::endl;
    }
};

// 调用者
class Invoker {
private:
    std::vector<Command*> commands;

public:
    void addCommand(Command* command) {
        commands.push_back(command);
    }

    void executeCommands() const {
        for (Command* command : commands) {
            command->execute();
        }
    }
};

//int main() {
//    // 创建命令对象
//    Command* commandA = new ConcreteCommandA("Execute Command A");
//    Command* commandB = new ConcreteCommandB("Execute Command B");
//
//    // 创建调用者对象
//    Invoker* invoker = new Invoker;
//
//    // 添加命令到调用者
//    invoker->addCommand(commandA);
//    invoker->addCommand(commandB);
//
//    // 执行命令
//    invoker->executeCommands();    //输出 ConcreteCommandA: Execute Command A \
//                                          ConcreteCommandB: Execute Command B
//
//    // 释放资源
//    delete commandA;
//    delete commandB;
//    delete invoker;
//
//    return 0;
//}
