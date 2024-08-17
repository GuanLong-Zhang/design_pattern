//������ģʽ
//��������Ľӿ�ת��Ϊ�ͻ������ڴ��Ľӿڣ������䲻���ݵĽӿ�
#include <iostream>

// Ŀ��ӿڣ��ͻ����������Ľӿڣ�
class TargetInterface {
public:
    virtual ~TargetInterface() {}
    virtual void request() const = 0;    //������Ա���������ں������ڲ����޸Ķ���ĳ�Ա����
};

// �����ߣ����е���Ľӿڣ�
class Adaptee {
public:
    void specificRequest() const {
        std::cout << "Adaptee's specific request." << std::endl;
    }
};

// ������
class Adapter : public TargetInterface {
private:
    Adaptee* adaptee;

public:
    Adapter(Adaptee* adaptee) : adaptee(adaptee) {}

    void request() const override {
        adaptee->specificRequest();
    }
};

//int main() {
//
//    Adaptee* adaptee = new Adaptee;   //������ӿ�
//    TargetInterface* targetInterface = new Adapter(adaptee);   //Ŀ����ӿ�
//    targetInterface->request();   // ���: Adaptee's specific request.
//
//    delete adaptee;
//    delete targetInterface;
//
//    return 0;
//}
