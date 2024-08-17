//���󹤳�ģʽ
//�ṩ��һ������һϵ����ػ����໥��������Ľӿڣ�������ָ�����Ǿ������
#include <iostream>
#include <string>
using namespace std;

// ���� ����
class ShipBody
{
public:
    ShipBody() {
        cout << "ShipBody()" << endl;
    }

    virtual string getShipBody() = 0;   //���麯��

    virtual ~ShipBody() {      //���ͷ�������Դ�����ͷŸ�����Դ
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
        return string("��<ľ��>�����ִ�����...");
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
        return string("��<����>�����ִ�����...");
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
        return string("��<�Ͻ�>�����ִ�����...");
    }
};

// ���� ����
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
        return string("�䱸��������<ǹ>...");
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
        return string("�䱸��������<�Զ�������>...");
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
        return string("�䱸��������<����>...");
    }
};

// ���� ����
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
        return string("ʹ��<��������>...");
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
        return string("ʹ��<��ȼ������>...");
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
        return string("ʹ��<��������>...");
    }
};

// �ִ���
class Ship
{
public:
    Ship(ShipBody* body, Weapon* weapon, Engine* engine){   //����ָ��
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

// ������ ����
class AbstractFactory
{
public:
    AbstractFactory() {
        cout << "AbstractFactory()" << endl;
    }
    virtual Ship* createShip() = 0;    //����һϵ����ػ����໥��������Ľӿ�
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
        Ship* ship = new Ship(new WoodBody, new Gun, new Human);   //new�������
        cout << "<������>ս���������, ������ˮ��..." << endl;
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
        cout << "<��׼��>ս���������, ������ˮ��..." << endl;
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
        cout << "<�콢��>ս���������, ������ˮ��..." << endl;
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




