//����ģʽ
//�ṩ��һ����������Ľӿڣ����������ʵ���������Ƴٵ�������
#include<iostream>
using namespace std;

//������ ����
class abstractAnimal {
public:
	abstractAnimal() {
		cout << "abstractAnimal()" << endl;
	}
	virtual void trans() = 0; //���麯��
	virtual void function() = 0;
	virtual ~abstractAnimal() {    //���ͷ�������Դ�����ͷŸ�����Դ
		cout << "~abstractAnimal()" << endl;
	}

};

//������д�����麯��
class sheep : public abstractAnimal {
public:
	sheep() {
		cout << "sheep()" << endl;
	}

	void trans() override {
		cout << "��Ϊ��" << endl;
	}

	void function() override {
		cout << "����" << endl;
	}

	~sheep(){
		cout << "~sheep()" << endl;
	}
};

class dog : public abstractAnimal {
public:
	dog() {
		cout << "dog()" << endl;
	}

	void trans() override {
		cout << "��Ϊ��" << endl;
	}

	void function() override {
		cout << "������" << endl;
	}

	~dog(){
		cout << "~dog()" << endl;
	}
};

class cat : public abstractAnimal {
public:
	cat() {
		cout << "cat()" << endl;
	}

	void trans() override {
		cout << "��Ϊè" << endl;
	}

	void function() override {
		cout << "è����" << endl;
	}

	~cat(){
		cout << "~cat()" << endl;
	}
};

//������ ����
class abstractFactory {
public:
	abstractFactory() {
		cout << "abstractFactory()" << endl;
	}
	virtual abstractAnimal* createAnimal() = 0;   //��������Ľӿ�
	virtual ~abstractFactory(){
		cout << "~abstractFactory()" << endl;
	}
};

class sheepFactory : public abstractFactory{
public:
	sheepFactory() {
		cout << "sheepFactory()" << endl;
	}

	abstractAnimal* createAnimal() override{      //ʵ���������Ƴ�������
		return new sheep;
	}

	~sheepFactory() {
		cout << "~sheepFactory()" << endl;
	}
};

class catFactory : public abstractFactory {
public:
	catFactory() {
		cout << "catFactory()" << endl;
	}

	abstractAnimal* createAnimal() override{
		return new cat;
	}

	~catFactory() {
		cout << "~catFactory()" << endl;
	}
};

class dogFactory : public abstractFactory {
public:
	dogFactory() {
		cout << "dogFactory()" << endl;
	}

	abstractAnimal* createAnimal() override{
		return new dog;
	}

	~dogFactory() {
		cout << "~dogFactory()" << endl;
	}
};

//int main() {
//	abstractFactory* aF = new sheepFactory;  
//	abstractAnimal* obj = aF->createAnimal();
//	obj->trans();
//	obj->function();
////	obj->~abstractAnimal();
////	aF->~abstractFactory();
//	delete obj;
//	delete aF;
//	return 0;
//
//}