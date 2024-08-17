//简单工厂模式
#include<iostream>
using namespace std;

//抽象类 父类
class abstractAnimal {
public:
	abstractAnimal() {
		cout << "abstractAnimal()" << endl;
	}
	virtual void trans() {}
	virtual void function() {}
	virtual ~abstractAnimal() {    //析构函数设置为虚函数，先释放子类的资源再释放父类的资源
		cout << "~abstractAnimal()" << endl;
	}

};

//子类重写父类虚函数
class sheep : public abstractAnimal {
public:
	sheep() {
		cout << "sheep()" << endl;
	}

	void trans() override {
		cout << "变为羊" << endl;
	}

	void function() override {
		cout << "羊技能" << endl;
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
		cout << "变为狗" << endl;
	}

	void function() override {
		cout << "狗技能" << endl;
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
		cout << "变为猫" << endl;
	}

	void function() override {
		cout << "猫技能" << endl;
	}

	~cat() {
		cout << "~cat()" << endl;
	}
};

enum class Type : char{sheep,dog,cat};
//工厂类
class factory {
public:
	factory(){
		cout << "factory()" << endl;
	}

	~factory(){
		cout << "~factory()" << endl;
	}
	abstractAnimal* createAnimal(Type type) {  //工厂函数
		abstractAnimal* ptr = nullptr;   //父类指针
		switch (type) {
			case Type::sheep:
				ptr = new sheep;  //父类指针指向子类对象
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
//	factory* fa = new factory;  //工厂对象
//	abstractAnimal* obj = fa->createAnimal(Type::sheep);    //工厂函数 传入羊类
//	obj->trans();
//	obj->function();
//	obj->~abstractAnimal();
//	fa->~factory();
//  delete obj;
//  delete fa;
//	return 0;
//
//}