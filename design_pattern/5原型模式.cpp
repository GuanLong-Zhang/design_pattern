//ԭ��ģʽ
//ͨ���������еĶ����������µĶ��󣬶�������ʾʵ�����Ĵ���
#include <iostream>
using namespace std;

//����
class GermaSoldier
{
public:
    virtual GermaSoldier* clone() = 0;    //��������Ϊ����ָ��
    virtual string whoAmI() = 0;
    virtual ~GermaSoldier() {}
};

//����
class Soldier66 : public GermaSoldier
{
public:
    GermaSoldier* clone() override    //����ָ��ָ���������
    {
        return new Soldier66(*this);
    }
    string whoAmI() override
    {
        return string("���ǽܶ���66�ĳ���ʿ��!!!");
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
        return string("���ǽܶ���67�ĳ���ʿ��!!!");
    }
};

//int main()
//{
//    GermaSoldier* obj = new Soldier66;    //���ж���
//    GermaSoldier* soldier = obj->clone();   //�µĶ���
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

