//单例模式
//类只能实例化一次，采用静态类成员变量（无论实例化多少次，只能有一个静态成员）
#include<iostream>
#include<mutex>
#include<atomic>
#include<queue>
#include<thread>
using namespace std;

#if 0  //0关闭， 1打开
//饿汉模式：在定义类的时候，就创建了类的单例对象，占用内存但是线程安全
class taskQueue {
public:
	//禁用拷贝构造函数和等号赋值
	//方式一
	taskQueue(const taskQueue& t) = delete;
	taskQueue& operator= (const taskQueue& t) = delete;
	static taskQueue* getInstance() {   //不需要进行实例化，直接通过类名就可以调用
		return mtask;
	}

	void print() {
		cout << "饿汉模式单例对象的打印成员函数..." << endl;
	}

private:
	taskQueue() = default;
	////方式二
	//taskQueue(const taskQueue& t) = default;
	//taskQueue& operator= (const taskQueue& t) = default;
	static taskQueue* mtask;   //无论类实例化多少次，只能有一个静态成员，只能在类外进行初始化
};

taskQueue* taskQueue::mtask = new taskQueue;
#endif 

#if 0
//懒汉模式：什么时候使用单例对象，再去创建，节省内存但是线程不安全
class taskQueue {
public:
	//禁用拷贝构造函数和等号赋值
	//方式一
	taskQueue(const taskQueue& t) = delete;
	taskQueue& operator= (const taskQueue& t) = delete;
	static taskQueue* getInstance() {   //不需要进行实例化，直接通过类名就可以调用
		if (mtask == nullptr) {   //双重检查锁定
			mt.lock();    //加锁
			if (mtask == nullptr) {
				mtask = new taskQueue;
			}
			mt.unlock();  //解锁
		}
		return mtask;	 
	}

	void print() {
		cout << "懒汉模式单例对象的打印成员函数..." << endl;
	}

private:
	taskQueue() = default;
	////方式二
	//taskQueue(const taskQueue& t) = default;
	//taskQueue& operator= (const taskQueue& t) = default;
	static taskQueue* mtask;   //无论类实例化多少次，只能有一个静态成员，只能在类外进行初始化
	static mutex mt;
};

taskQueue* taskQueue::mtask = nullptr;
mutex taskQueue::mt;
#endif

#if 0
//懒汉模式：原子变量解决双重检查锁定问题
class taskQueue {
public:
	//禁用拷贝构造函数和等号赋值
	//方式一
	taskQueue(const taskQueue& t) = delete;
	taskQueue& operator= (const taskQueue& t) = delete;
	static taskQueue* getInstance() {   //不需要进行实例化，直接通过类名就可以调用
		taskQueue* task = mtask.load();  //原子变量加载
		if (task == nullptr) {     //双重检查锁定
			mt.lock();    //加锁
			task = mtask.load();
			if (task == nullptr) {
				task = new taskQueue;
				mtask.store(task);   //原子变量存储
			}
			mt.unlock();  //解锁
		}
		return task;
	}

	void print() {
		cout << "懒汉模式单例对象的打印成员函数..." << endl;
	}

private:
	taskQueue() = default;
	////方式二
	//taskQueue(const taskQueue& t) = default;
	//taskQueue& operator= (const taskQueue& t) = default;
	static atomic<taskQueue*> mtask;   //原子变量存储
	static mutex mt;
};

atomic<taskQueue*> taskQueue::mtask;
mutex taskQueue::mt;
#endif 

#if 0
//懒汉模式：使用静态局部对象解决线程不安全问题
class taskQueue {
public:
	//禁用拷贝构造函数和等号赋值
	//方式一
	taskQueue(const taskQueue& t) = delete;
	taskQueue& operator= (const taskQueue& t) = delete;
	static taskQueue* getInstance() {   //不需要进行实例化，直接通过类名就可以调用
		static taskQueue task;    //静态局部对象
		return &task;
	}

	void print() {
		cout << "懒汉模式单例对象的打印成员函数..." << endl;
	}

private:
	taskQueue() = default;
	////方式二
	//taskQueue(const taskQueue& t) = default;
	//taskQueue& operator= (const taskQueue& t) = default;

};

#endif 

#if 1  
//饿汉模式：多线程推荐使用，因为其没有线程不安全的问题(指的是创建单例对象时没有线程不安全问题)
//多线程任务队列
class taskQueue {
public:
	//禁用拷贝构造函数和等号赋值
	//方式一
	taskQueue(const taskQueue& t) = delete;
	taskQueue& operator= (const taskQueue& t) = delete;
	static taskQueue* getInstance() {   //不需要进行实例化，直接通过类名就可以调用
		return mtask;
	}

	void print() {
		cout << "饿汉模式单例对象的打印成员函数..." << endl;
	}

	//判断任务队列是否为空
	bool isEmpty() {
		lock_guard<mutex> locker(mt);    //智能锁，会自动解锁，避免解锁忘记操作
		return mq.empty();
	}

	//添加任务
	void addTask(int task) {
		lock_guard<mutex> locker(mt);
		mq.push(task);
	}

	//删除任务
	bool deleteTask() {
		lock_guard<mutex> locker(mt); 
		if (mq.empty()) {
			return false;
		}
		mq.pop();
		return true;
	}

	//获得任务
	int takeTask() {
		lock_guard<mutex> locker(mt);
		if (mq.empty()) {
			return -1;
		}
		return mq.front();
	}

private:
	taskQueue() = default;
	////方式二
	//taskQueue(const taskQueue& t) = default;
	//taskQueue& operator= (const taskQueue& t) = default;
	static taskQueue* mtask;   //无论类实例化多少次，只能有一个静态成员，只能在类外进行初始化
	queue<int> mq;   //任务队列
	mutex mt;   //互斥锁
};

taskQueue* taskQueue::mtask = new taskQueue;
#endif 

//int main() {
//	taskQueue* m = taskQueue::getInstance();
//	//m->print();
//
//	//生产者
//	thread t1([=]() {
//		for (int i = 0; i < 10; i++) {
//			m->addTask(i);
//			cout << " add data:" << i << " thread id:" << this_thread::get_id << endl;
//			this_thread::sleep_for(chrono::milliseconds(500));   //休眠500ms
//		}
//	});
//
//	//消费者
//	thread t2([=]() {
//		while(!m->isEmpty()){
//			int num = m->takeTask();
//			cout << "take data:" << num << " thread id:" << this_thread::get_id << endl;
//			m->deleteTask();
//			this_thread::sleep_for(chrono::milliseconds(500));   //休眠500ms
//		}
//	});
//
//	t1.join();
//	t2.join();
//
//	return 0;
//}