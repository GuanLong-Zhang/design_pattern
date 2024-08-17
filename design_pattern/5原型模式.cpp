//原型模式
//通过复制现有的对象来创建新的对象，而不是显示实例化的创建
#include <iostream>
using namespace std;

//父类
class GermaSoldier
{
public:
    virtual GermaSoldier* clone() = 0;    //返回类型为父类指针
    virtual string whoAmI() = 0;
    virtual ~GermaSoldier() {}
};

//子类
class Soldier66 : public GermaSoldier
{
public:
    GermaSoldier* clone() override    //父类指针指向子类对象
    {
        return new Soldier66(*this);
    }
    string whoAmI() override
    {
        return string("我是杰尔马66的超级士兵!!!");
    }
};

class Soldier67 : public GermaSoldier
{
public:
    GermaSoldier* clone()
    {
        return new Soldier67(*this);
    }
    string whoAmI() override
    {
        return string("我是杰尔马67的超级士兵!!!");
    }
};

//int main()
//{
//    GermaSoldier* obj = new Soldier66;    //现有对象
//    GermaSoldier* soldier = obj->clone();   //新的对象
//    cout << soldier->whoAmI() << endl;
//    delete soldier;
//    delete obj;
//
//    cout << "==============================" << endl;
//
//    obj = new Soldier67;
//    soldier = obj->clone();
//    cout << soldier->whoAmI() << endl;
//    delete soldier;
//    delete obj;
//}

