//��Ԫģʽ
//ͨ�������Ѿ����ڵ����ƶ�������С���ڴ�ʹ�ú��������
#include <iostream>
#include <unordered_map>

// ��Ԫ�ӿ�
class Flyweight {
public:
    virtual ~Flyweight() {}
    virtual void operation(int extrinsicState) const = 0;
};

// ������Ԫ
class ConcreteFlyweight : public Flyweight {
private:
    int intrinsicState; // �ڲ�״̬

public:
    ConcreteFlyweight(int intrinsicState) : intrinsicState(intrinsicState) {}

    void operation(int extrinsicState) const override {
        std::cout << "ConcreteFlyweight with intrinsic state " << intrinsicState
            << " and extrinsic state " << extrinsicState << std::endl;
    }
};

// ��Ԫ����
class FlyweightFactory {
private:
    std::unordered_map<int, Flyweight*> flyweights; // ������Ԫ����

public:
    Flyweight* getFlyweight(int key) {     //����key
        if (flyweights.find(key) == flyweights.end()) {     //û�鵽
            // ��������ڣ��򴴽��µ���Ԫ������ӵ�������
            flyweights[key] = new ConcreteFlyweight(key);
        }
        return flyweights[key];   //����value
    }

    ~FlyweightFactory() {
        for (auto pair : flyweights) {
            delete pair.second;
        }
    }
};

//int main() {
//    FlyweightFactory* factory = new FlyweightFactory;
//
//    // ��ȡ��Ԫ���󲢴����ⲿ״̬
//    Flyweight* flyweight1 = factory->getFlyweight(1);
//    flyweight1->operation(100);   //���ConcreteFlyweight with intrinsic state 1 and extrinsic state 100
//
//    Flyweight* flyweight2 = factory->getFlyweight(2);
//    flyweight2->operation(200);   //���ConcreteFlyweight with intrinsic state 2 and extrinsic state 200
//
//    // �ͷ���Դ
//    delete flyweight1;
//    delete flyweight2;
//    delete factory;
//
//    return 0;
//}
