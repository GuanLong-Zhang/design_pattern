//���ģʽ
//�ṩһ��ͳһ�Ľӿڣ����ڷ�����ϵͳ�е�һ��ӿڣ��Լ򻯿ͻ��˵�ʹ��
#include <iostream>

// ��ϵͳ A
class SubsystemA {
public:
    void operationA() const {
        std::cout << "SubsystemA operation." << std::endl;
    }
};

// ��ϵͳ B
class SubsystemB {
public:
    void operationB() const {
        std::cout << "SubsystemB operation." << std::endl;
    }
};

// ���
class Facade {
private:
    SubsystemA* subsystemA;
    SubsystemB* subsystemB;

public:
    Facade(SubsystemA* subA, SubsystemB*subB):subsystemA(subA),subsystemB(subB){}

    void operation() const {
        std::cout << "Facade operation:" << std::endl;
        subsystemA->operationA();
        subsystemB->operationB();
    }
};

//int main() {
//    SubsystemA* subA = new SubsystemA;   //��ϵͳ����
//    SubsystemB* subB = new SubsystemB;
//    Facade* fa = new Facade(subA, subB);  //ͳһ�ӿ�
//    fa->operation();   //��� Facade operation:\
//                              SubsystemA operation.\
//                              SubsystemB operation.
//
//    delete subA;
//    delete subB;
//    delete fa;
//
//    return 0;
//}
