//建造者模式
//将复杂对象的构建过程分离为多个简单对象的构建过程，通过组装构建构成来创建不同的对象
#include<iostream>
#include<vector>
using namespace std;

// 桑尼号
class SunnyShip
{
public:
    // 添加零件
    void addParts(string name)
    {
        m_parts.push_back(name);
    }
    void showParts()
    {
        for (const auto& item : m_parts)
        {
            cout << item << "   ";
        }
        cout << endl;
    }
private:
    vector<string> m_parts;
};

// 梅利号
class MerryShip
{
public:
    // 添加零件
    void addParts(string name)
    {
        m_parts.push_back(name);
    }
    void showParts()
    {
        for (const auto& item : m_parts)
        {
            cout << item << "   ";
        }
        cout << endl;
    }
private:
    vector<string> m_parts;
};

// 生成器类 父类
class ShipBuilder
{
public:
    virtual void reset() = 0;
    virtual void buildBody() = 0;      //纯虚函数   建造船体
    virtual void buildWeapon() = 0;    //建造武器
    virtual void buildEngine() = 0;    //建造动力
    virtual void buildInterior() = 0;  //建造内饰
    virtual ~ShipBuilder() {}
};

// 桑尼号生成器  子类
class SunnyBuilder : public ShipBuilder
{
public:
    SunnyBuilder()
    {
        reset();
    }

    ~SunnyBuilder()
    {
        if (m_sunny != nullptr)
        {
            delete m_sunny;
        }
    }
    // 提供重置函数, 目的是能够使用生成器对象生成多个产品
    void reset() override
    {
        m_sunny = new SunnyShip;   //桑尼号对象
    }
    void buildBody() override
    {
        m_sunny->addParts("神树亚当的树干");
    }
    void buildWeapon() override
    {
        m_sunny->addParts("狮吼炮");
    }
    void buildEngine() override
    {
        m_sunny->addParts("可乐驱动");
    }
    void buildInterior() override
    {
        m_sunny->addParts("豪华内室精装");
    }
    SunnyShip* getSunny()   //获得桑尼号对象
    {
        SunnyShip* ship = m_sunny;
        m_sunny = nullptr;   //置空
        return ship;
    }
private:
    SunnyShip* m_sunny = nullptr;
};

// 梅利号生成器
class MerryBuilder : public ShipBuilder
{
public:
    MerryBuilder()
    {
        reset();
    }

    ~MerryBuilder()
    {
        if (m_merry != nullptr)
        {
            delete m_merry;
        }
    }
    void reset() override
    {
        m_merry = new MerryShip;    //梅利号对象
    }
    void buildBody() override
    {
        m_merry->addParts("优质木材");
    }
    void buildWeapon() override
    {
        m_merry->addParts("四门大炮");
    }
    void buildEngine() override
    {
        m_merry->addParts("蒸汽机");
    }
    void buildInterior() override
    {
        m_merry->addParts("精装");
    }
    MerryShip* getMerry()     //获得梅利号对象
    {
        MerryShip* ship = m_merry;
        m_merry = nullptr;  //置空
        return ship;
    }
private:
    MerryShip* m_merry = nullptr;
};

// 主管类
class Director
{
public:
    void setBuilder(ShipBuilder* builder)    //父类指针指向子类对象
    {
        m_builder = builder;
    }
    // 简约型
    void builderSimpleShip()      //组装构建过程
    {
        m_builder->buildBody();
        m_builder->buildEngine();
    }
    // 标准型
    void builderStandardShip()
    {
        builderSimpleShip();
        m_builder->buildWeapon();
    }
    // 豪华型
    void builderRegalShip()
    {
        builderStandardShip();
        m_builder->buildInterior();
    }
private:
    ShipBuilder* m_builder = nullptr;
};

// 建造桑尼号
void builderSunny()
{
    Director* director = new Director;    //主管对象  堆区开辟，需要进行手动释放
    SunnyBuilder* builder = new SunnyBuilder;  //桑尼号对象   new对象默认调用构造函数
    // 简约型
    director->setBuilder(builder);   //多态，传入子类对象
    director->builderSimpleShip();   //建造简约型
    SunnyShip* sunny = builder->getSunny();   //获得桑尼号对象
    sunny->showParts();   //展示
    delete sunny;
    
    // 标准型
    builder->reset();
    director->setBuilder(builder);
    director->builderStandardShip();
    sunny = builder->getSunny();
    sunny->showParts();
    delete sunny;

    // 豪华型
    builder->reset();
    director->setBuilder(builder);
    director->builderRegalShip();
    sunny = builder->getSunny();
    sunny->showParts();
    delete sunny;

    delete builder;
    delete director;
}

// 建造梅利号
void builderMerry()
{
    Director* director = new Director;
    MerryBuilder* builder = new MerryBuilder;
    // 简约型
    director->setBuilder(builder);
    director->builderSimpleShip();
    MerryShip* merry = builder->getMerry();
    merry->showParts();
    delete merry;

    // 标准型
    builder->reset();
    director->setBuilder(builder);
    director->builderStandardShip();
    merry = builder->getMerry();
    merry->showParts();
    delete merry;

    // 豪华型
    builder->reset();
    director->setBuilder(builder);
    director->builderRegalShip();
    merry = builder->getMerry();
    merry->showParts();
    delete merry;
    delete builder;
    delete director;
}

//int main()
//{
//    builderSunny();
//    cout << "=====================================" << endl;
//    builderMerry();
//}

//new 类名 是在堆区开辟内存空间，返回指针，需要进行显示删除
//类名 对象名 是在栈区开辟内存空间，不需要显示删除，可以自动释放
//一般有new的地方，必须去检查是否有对应的delete，防止内存泄漏




