//工厂模式
//提供了一个创建对象的接口，并将具体的实例化过程推迟到子类中
#include<iostream>
using namespace std;

//抽象类 父类
class abstractAnimal {
public:
	abstractAnimal() {
		cout << "abstractAnimal()" << endl;
	}
	virtual void trans() = 0; //纯虚函数
	virtual void function() = 0;
	virtual ~abstractAnimal() {    //先释放子类资源，再释放父类资源
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
		cout << "变为狗" << endl;
	}

	void function() override {
		cout << "狗技能" << endl;
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
		cout << "变为猫" << endl;
	}

	void function() override {
		cout << "猫技能" << endl;
	}

	~cat(){
		cout << "~cat()" << endl;
	}
};

//抽象类 父类
class abstractFactory {
public:
	abstractFactory() {
		cout << "abstractFactory()" << endl;
	}
	virtual abstractAnimal* createAnimal() = 0;   //创建对象的接口
	virtual ~abstractFactory(){
		cout << "~abstractFactory()" << endl;
	}
};

class sheepFactory : public abstractFactory{
public:
	sheepFactory() {
		cout << "sheepFactory()" << endl;
	}

	abstractAnimal* createAnimal() override{      //实例化过程推迟子类中
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