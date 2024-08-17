//�򵥹���ģʽ
#include<iostream>
using namespace std;

//������ ����
class abstractAnimal {
public:
	abstractAnimal() {
		cout << "abstractAnimal()" << endl;
	}
	virtual void trans() {}
	virtual void function() {}
	virtual ~abstractAnimal() {    //������������Ϊ�麯�������ͷ��������Դ���ͷŸ������Դ
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

	~sheep() {
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

	~dog() {
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

	~cat() {
		cout << "~cat()" << endl;
	}
};

enum class Type : char{sheep,dog,cat};
//������
class factory {
public:
	factory(){
		cout << "factory()" << endl;
	}

	~factory(){
		cout << "~factory()" << endl;
	}
	abstractAnimal* createAnimal(Type type) {  //��������
		abstractAnimal* ptr = nullptr;   //����ָ��
		switch (type) {
			case Type::sheep:
				ptr = new sheep;  //����ָ��ָ���������
				break;
			case Type::dog:
				ptr = new dog;
				break;
			case Type::cat:
				ptr = new cat;
				break;
			default:
				break;
		}
		return ptr;
	}

};

//int main() {
//	factory* fa = new factory;  //��������
//	abstractAnimal* obj = fa->createAnimal(Type::sheep);    //�������� ��������
//	obj->trans();
//	obj->function();
//	obj->~abstractAnimal();
//	fa->~factory();
//  delete obj;
//  delete fa;
//	return 0;
//
//}