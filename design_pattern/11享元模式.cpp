//享元模式
//通过共享已经存在的相似对象来最小化内存使用和提高性能
#include <iostream>
#include <unordered_map>

// 享元接口
class Flyweight {
public:
    virtual ~Flyweight() {}
    virtual void operation(int extrinsicState) const = 0;
};

// 具体享元
class ConcreteFlyweight : public Flyweight {
private:
    int intrinsicState; // 内部状态

public:
    ConcreteFlyweight(int intrinsicState) : intrinsicState(intrinsicState) {}

    void operation(int extrinsicState) const override {
        std::cout << "ConcreteFlyweight with intrinsic state " << intrinsicState
            << " and extrinsic state " << extrinsicState << std::endl;
    }
};

// 享元工厂
class FlyweightFactory {
private:
    std::unordered_map<int, Flyweight*> flyweights; // 缓存享元对象

public:
    Flyweight* getFlyweight(int key) {     //传入key
        if (flyweights.find(key) == flyweights.end()) {     //没查到
            // 如果不存在，则创建新的享元对象并添加到缓存中
            flyweights[key] = new ConcreteFlyweight(key);
        }
        return flyweights[key];   //返回value
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
//    // 获取享元对象并传入外部状态
//    Flyweight* flyweight1 = factory->getFlyweight(1);
//    flyweight1->operation(100);   //输出ConcreteFlyweight with intrinsic state 1 and extrinsic state 100
//
//    Flyweight* flyweight2 = factory->getFlyweight(2);
//    flyweight2->operation(200);   //输出ConcreteFlyweight with intrinsic state 2 and extrinsic state 200
//
//    // 释放资源
//    delete flyweight1;
//    delete flyweight2;
//    delete factory;
//
//    return 0;
//}
