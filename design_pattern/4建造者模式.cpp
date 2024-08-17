//������ģʽ
//�����Ӷ���Ĺ������̷���Ϊ����򵥶���Ĺ������̣�ͨ����װ����������������ͬ�Ķ���
#include<iostream>
#include<vector>
using namespace std;

// ɣ���
class SunnyShip
{
public:
    // ������
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

// ÷����
class MerryShip
{
public:
    // ������
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

// �������� ����
class ShipBuilder
{
public:
    virtual void reset() = 0;
    virtual void buildBody() = 0;      //���麯��   ���촬��
    virtual void buildWeapon() = 0;    //��������
    virtual void buildEngine() = 0;    //���춯��
    virtual void buildInterior() = 0;  //��������
    virtual ~ShipBuilder() {}
};

// ɣ���������  ����
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
    // �ṩ���ú���, Ŀ�����ܹ�ʹ���������������ɶ����Ʒ
    void reset() override
    {
        m_sunny = new SunnyShip;   //ɣ��Ŷ���
    }
    void buildBody() override
    {
        m_sunny->addParts("�����ǵ�������");
    }
    void buildWeapon() override
    {
        m_sunny->addParts("ʨ����");
    }
    void buildEngine() override
    {
        m_sunny->addParts("��������");
    }
    void buildInterior() override
    {
        m_sunny->addParts("�������Ҿ�װ");
    }
    SunnyShip* getSunny()   //���ɣ��Ŷ���
    {
        SunnyShip* ship = m_sunny;
        m_sunny = nullptr;   //�ÿ�
        return ship;
    }
private:
    SunnyShip* m_sunny = nullptr;
};

// ÷����������
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
        m_merry = new MerryShip;    //÷���Ŷ���
    }
    void buildBody() override
    {
        m_merry->addParts("����ľ��");
    }
    void buildWeapon() override
    {
        m_merry->addParts("���Ŵ���");
    }
    void buildEngine() override
    {
        m_merry->addParts("������");
    }
    void buildInterior() override
    {
        m_merry->addParts("��װ");
    }
    MerryShip* getMerry()     //���÷���Ŷ���
    {
        MerryShip* ship = m_merry;
        m_merry = nullptr;  //�ÿ�
        return ship;
    }
private:
    MerryShip* m_merry = nullptr;
};

// ������
class Director
{
public:
    void setBuilder(ShipBuilder* builder)    //����ָ��ָ���������
    {
        m_builder = builder;
    }
    // ��Լ��
    void builderSimpleShip()      //��װ��������
    {
        m_builder->buildBody();
        m_builder->buildEngine();
    }
    // ��׼��
    void builderStandardShip()
    {
        builderSimpleShip();
        m_builder->buildWeapon();
    }
    // ������
    void builderRegalShip()
    {
        builderStandardShip();
        m_builder->buildInterior();
    }
private:
    ShipBuilder* m_builder = nullptr;
};

// ����ɣ���
void builderSunny()
{
    Director* director = new Director;    //���ܶ���  �������٣���Ҫ�����ֶ��ͷ�
    SunnyBuilder* builder = new SunnyBuilder;  //ɣ��Ŷ���   new����Ĭ�ϵ��ù��캯��
    // ��Լ��
    director->setBuilder(builder);   //��̬�������������
    director->builderSimpleShip();   //�����Լ��
    SunnyShip* sunny = builder->getSunny();   //���ɣ��Ŷ���
    sunny->showParts();   //չʾ
    delete sunny;
    
    // ��׼��
    builder->reset();
    director->setBuilder(builder);
    director->builderStandardShip();
    sunny = builder->getSunny();
    sunny->showParts();
    delete sunny;

    // ������
    builder->reset();
    director->setBuilder(builder);
    director->builderRegalShip();
    sunny = builder->getSunny();
    sunny->showParts();
    delete sunny;

    delete builder;
    delete director;
}

// ����÷����
void builderMerry()
{
    Director* director = new Director;
    MerryBuilder* builder = new MerryBuilder;
    // ��Լ��
    director->setBuilder(builder);
    director->builderSimpleShip();
    MerryShip* merry = builder->getMerry();
    merry->showParts();
    delete merry;

    // ��׼��
    builder->reset();
    director->setBuilder(builder);
    director->builderStandardShip();
    merry = builder->getMerry();
    merry->showParts();
    delete merry;

    // ������
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

//new ���� ���ڶ��������ڴ�ռ䣬����ָ�룬��Ҫ������ʾɾ��
//���� ������ ����ջ�������ڴ�ռ䣬����Ҫ��ʾɾ���������Զ��ͷ�
//һ����new�ĵط�������ȥ����Ƿ��ж�Ӧ��delete����ֹ�ڴ�й©




