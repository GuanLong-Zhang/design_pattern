//�н���ģʽ
//��һ���н��������װһϵ�еĶ��󽻻���ʹ�ø���������Ҫ������ʾ���໥����
#include <iostream>
#include <string>
#include <vector>

// �н��߽ӿ�
class Mediator {
public:
    virtual void sendMessage(const std::string& message, class Colleague* colleague) const = 0;
};

// ����ͬ����
class Colleague {
protected:
    Mediator* mediator;

public:
    Colleague(Mediator* mediator) : mediator(mediator) {}

    virtual void sendMessage(const std::string& message) = 0;
    virtual void receiveMessage(const std::string& message) const = 0;
};

// �����н�����
class ConcreteMediator : public Mediator {
private:
    std::vector<Colleague*> colleagues;

public:
    void addColleague(Colleague* colleague) {
        colleagues.push_back(colleague);
    }

    virtual void sendMessage(const std::string& message, Colleague* sender) const override {
        for (auto colleague : colleagues) {
            if (colleague != sender) {
                colleague->receiveMessage(message);
            }
        }
    }
};

// ����ͬ����
class ConcreteColleague : public Colleague {
public:
    ConcreteColleague(Mediator* mediator) : Colleague(mediator) {}

    virtual void sendMessage(const std::string& message) override {
        mediator->sendMessage(message,this);
    }

    virtual void receiveMessage(const std::string& message) const override {
        std::cout << "Received message: " << message << std::endl;
    }
};

//int main() {
//    ConcreteMediator mediator;    //�н����
//    ConcreteColleague colleague1(&mediator);
//    ConcreteColleague colleague2(&mediator);
//
//    mediator.addColleague(&colleague1);
//    mediator.addColleague(&colleague2);
//
//    colleague1.sendMessage("Hello from colleague 1!");
//    colleague2.sendMessage("Hello from colleague 2!");
//
//    return 0;
//}
