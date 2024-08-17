//���ģʽ
//��������ϳ����νṹ�Ա�ʾ���֡�����Ĳ�νṹ��ʹ���û���ͳһ�ķ�ʽȥ�������������϶���
#include <iostream>
#include <vector>

// �������
class Component {
public:
    virtual ~Component() {}
    virtual void operation() const = 0;
};

// Ҷ�����
class Leaf : public Component {
public:
    void operation() const override {
        std::cout << "Leaf operation." << std::endl;
    }
};

// �������
class Composite : public Component {
private:
    std::vector<Component*> children;

public:
    ~Composite() {      //������������ɾ�����Ӷ���
        for (Component* child : children) {
            delete child;
            //std::cout << "ok" << std::endl;
        }
    }

    void add(Component* component) {
        children.push_back(component);
    }

    void operation() const override {
        std::cout << "Composite operation." << std::endl;
        for (Component* child : children) {
            child->operation();
        }
    }
};

//int main() {
//    // ����Ҷ�Ӷ���
//    Component* leaf1 = new Leaf;
//    Component* leaf2 = new Leaf;
//
//    // �������϶��󣬲����Ҷ�Ӷ���
//    Composite* composite = new Composite();
//    composite->add(leaf1);
//    composite->add(leaf2);
//
//    // ���ø��϶���Ĳ���
//    composite->operation();         //���  Composite operation.\
//                                            Leaf operation.\
//                                            Leaf operation.
//
//    // �ͷ���Դ
//    delete composite;
//    
//    return 0;
//}
