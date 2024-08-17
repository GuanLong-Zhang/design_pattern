//����ģʽ
//��һ�������װΪһ�����󣬴Ӷ�����ʹ�ò�ͬ�����󡢶��л�����־����������������
#include <iostream>
#include <vector>

// ����ӿ�
class Command {
public:
    virtual ~Command() {}
    virtual void execute() const = 0;
};

// �������� A
class ConcreteCommandA : public Command {
private:
    std::string message;

public:
    ConcreteCommandA(const std::string& msg) : message(msg) {}

    void execute() const override {
        std::cout << "ConcreteCommandA: " << message << std::endl;
    }
};

// �������� B
class ConcreteCommandB : public Command {
private:
    std::string action;

public:
    ConcreteCommandB(const std::string& act) : action(act) {}

    void execute() const override {
        std::cout << "ConcreteCommandB: " << action << std::endl;
    }
};

// ������
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
//    // �����������
//    Command* commandA = new ConcreteCommandA("Execute Command A");
//    Command* commandB = new ConcreteCommandB("Execute Command B");
//
//    // ���������߶���
//    Invoker* invoker = new Invoker;
//
//    // ������������
//    invoker->addCommand(commandA);
//    invoker->addCommand(commandB);
//
//    // ִ������
//    invoker->executeCommands();    //��� ConcreteCommandA: Execute Command A \
//                                          ConcreteCommandB: Execute Command B
//
//    // �ͷ���Դ
//    delete commandA;
//    delete commandB;
//    delete invoker;
//
//    return 0;
//}
