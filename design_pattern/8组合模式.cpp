//组合模式
//将对象组合成树形结构以表示部分—整体的层次结构，使用用户以统一的方式去处理单个对象和组合对象
#include <iostream>
#include <vector>

// 抽象组件
class Component {
public:
    virtual ~Component() {}
    virtual void operation() const = 0;
};

// 叶子组件
class Leaf : public Component {
public:
    void operation() const override {
        std::cout << "Leaf operation." << std::endl;
    }
};

// 复合组件
class Composite : public Component {
private:
    std::vector<Component*> children;

public:
    ~Composite() {      //析构函数里面删除孩子对象
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
//    // 创建叶子对象
//    Component* leaf1 = new Leaf;
//    Component* leaf2 = new Leaf;
//
//    // 创建复合对象，并添加叶子对象
//    Composite* composite = new Composite();
//    composite->add(leaf1);
//    composite->add(leaf2);
//
//    // 调用复合对象的操作
//    composite->operation();         //输出  Composite operation.\
//                                            Leaf operation.\
//                                            Leaf operation.
//
//    // 释放资源
//    delete composite;
//    
//    return 0;
//}
