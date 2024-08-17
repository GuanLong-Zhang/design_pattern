//����¼ģʽ
//�ڲ��ƻ���װ�������,���������ڲ�״̬�����ڶ���֮�Ᵽ�����״̬,����֮��ָ����״̬
#include <iostream>
#include <string>

// ����¼��
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

// ��������
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

// ��������
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
//    Originator originator;  //����¼����
//    Caretaker caretaker;    //�����߶���
//
//    originator.setState("State 1");
//    std::cout << "Current state: " << originator.getState() << std::endl;
//
//    // ���浱ǰ״̬  �����ϱ�����ǰ���״̬�Ķ���
//    caretaker.saveMemento(originator.createMemento());
//
//    // �޸�״̬
//    originator.setState("State 2");
//    std::cout << "Modified state: " << originator.getState() << std::endl;
//
//    // �ָ���֮ǰ�����״̬
//    originator.restoreMemento(caretaker.retrieveMemento());
//    std::cout << "Restored state: " << originator.getState() << std::endl;
//
//    return 0;
//}
