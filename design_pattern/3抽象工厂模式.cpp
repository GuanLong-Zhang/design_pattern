//抽象工厂模式
//提供了一个创建一系列相关或者相互依赖对象的接口，而无需指定它们具体的类
#include <iostream>
#include <string>
using namespace std;

// 船体 父类
class ShipBody
{
public:
    ShipBody() {
        cout << "ShipBody()" << endl;
    }

    virtual string getShipBody() = 0;   //纯虚函数

    virtual ~ShipBody() {      //先释放子类资源，再释放父类资源
        cout << "~ShipBody()" << endl;
    }
};

class WoodBody : public ShipBody
{
public:
    WoodBody() {
        cout << "WoodBody()" << endl;
    }

    ~WoodBody() {
        cout << "~WoodBody()" << endl;
    }

    string getShipBody() override{
        return string("用<木材>制作轮船船体...");
    }
};

class IronBody : public ShipBody
{
public:
    IronBody() {
        cout << "IronBody()" << endl;
    }

    ~IronBody() {
        cout << "~IronBody()" << endl;
    }

    string getShipBody() override{
        return string("用<钢铁>制作轮船船体...");
    }
};

class MetalBody : public ShipBody
{
public:
    MetalBody() {
        cout << "MetalBody()" << endl;
    }

    ~MetalBody() {
        cout << "~MetalBody()" << endl;
    }

    string getShipBody() override{
        return string("用<合金>制作轮船船体...");
    }
};

// 武器 父类
class Weapon
{
public:
    Weapon() {
        cout << "Weapon()" << endl;
    }

    virtual string getWeapon() = 0;

    virtual ~Weapon() {
        cout << "~Weapon()" << endl;
    }
};

class Gun : public Weapon
{
public:
    Gun() {
        cout << "Gun()" << endl;
    }

    ~Gun() {
        cout << "~Gun()" << endl;
    }

    string getWeapon() override{
        return string("配备的武器是<枪>...");
    }
};

class Cannon : public Weapon
{
public:
    Cannon() {
        cout << "Cannon()" << endl;
    }

    ~Cannon() {
        cout << "~Cannon()" << endl;
    }

    string getWeapon() override{
        return string("配备的武器是<自动机关炮>...");
    }
};

class Laser : public Weapon
{
public:
    Laser() {
        cout << "Laser()" << endl;
    }

    ~Laser() {
        cout << "~Laser()" << endl;
    }

    string getWeapon() override{
        return string("配备的武器是<激光>...");
    }
};

// 动力 父类
class Engine
{
public:
    Engine() {
        cout << "Engine()" << endl;
    }
    virtual string getEngine() = 0;
    virtual ~Engine() {
        cout << "~Engine()" << endl;
    }
};

class Human : public Engine
{
public:
    Human() {
        cout << "Human()" << endl;
    }

    ~Human() {
        cout << "~Human()" << endl;
    }

    string getEngine() override{
        return string("使用<人力驱动>...");
    }
};

class Diesel : public Engine
{
public:
    Diesel() {
        cout << "Diesel()" << endl;
    }

    ~Diesel() {
        cout << "~Diesel()" << endl;
    }

    string getEngine() override{
        return string("使用<内燃机驱动>...");
    }
};

class Nuclear : public Engine
{
public:
    Nuclear() {
        cout << "Nuclear()" << endl;
    }

    ~Nuclear() {
        cout << "~Nuclear()" << endl;
    }
    
    string getEngine() override{
        return string("使用<核能驱动>...");
    }
};

// 轮船类
class Ship
{
public:
    Ship(ShipBody* body, Weapon* weapon, Engine* engine){   //父类指针
        m_body = body;
        m_weapon = weapon;
        m_engine = engine;
        cout << "Ship(ShipBody* body, Weapon* weapon, Engine* engine)" << endl;
    }
    string getProperty(){
        string info = m_body->getShipBody() + m_weapon->getWeapon() + m_engine->getEngine();
        return info;
    }

    ~Ship(){
        delete m_body;
        delete m_engine;
        delete m_weapon;
        cout << "~Ship()" << endl;
    }

private:
    ShipBody* m_body = nullptr;
    Weapon* m_weapon = nullptr;
    Engine* m_engine = nullptr;
};

// 工厂类 父类
class AbstractFactory
{
public:
    AbstractFactory() {
        cout << "AbstractFactory()" << endl;
    }
    virtual Ship* createShip() = 0;    //创建一系列相关或者相互依赖对象的接口
    virtual ~AbstractFactory() {
        cout << "~AbstractFactory()" << endl;
    }
};

class BasicFactory : public AbstractFactory
{
public:
    BasicFactory() {
        cout << "BasicFactory()" << endl;
    }

    ~BasicFactory() {
        cout << "~BasicFactory()" << endl;
    }

    Ship* createShip() override{
        Ship* ship = new Ship(new WoodBody, new Gun, new Human);   //new子类对象
        cout << "<基础型>战船生产完毕, 可以下水啦..." << endl;
        return ship;
    }
};

class StandardFactory : public AbstractFactory
{
public:
    StandardFactory() {
        cout << "StandardFactory()" << endl;
    }

    ~StandardFactory() {
        cout << "~StandardFactory()" << endl;
    }

    Ship* createShip() override{
        Ship* ship = new Ship(new IronBody, new Cannon, new Diesel);
        cout << "<标准型>战船生产完毕, 可以下水啦..." << endl;
        return ship;
    }
};

class UltimateFactory : public AbstractFactory
{
public:
    UltimateFactory() {
        cout << "UltimateFactory()" << endl;
    }

    ~UltimateFactory() {
        cout << "~UltimateFactory()" << endl;
    }

    Ship* createShip() override{
        Ship* ship = new Ship(new MetalBody, new Laser, new Nuclear);
        cout << "<旗舰型>战船生产完毕, 可以下水啦..." << endl;
        return ship;
    }
};

//int main(){
//    AbstractFactory* factory = new BasicFactory;
//    Ship* ship = factory->createShip();
//    cout << ship->getProperty() << endl;
////    ship->~Ship();
////    factory->~AbstractFactory();
//    delete ship;
//    delete factory;
//    return 0;
//
//}




