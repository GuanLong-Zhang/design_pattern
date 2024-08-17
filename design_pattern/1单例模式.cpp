//����ģʽ
//��ֻ��ʵ����һ�Σ����þ�̬���Ա����������ʵ�������ٴΣ�ֻ����һ����̬��Ա��
#include<iostream>
#include<mutex>
#include<atomic>
#include<queue>
#include<thread>
using namespace std;

#if 0  //0�رգ� 1��
//����ģʽ���ڶ������ʱ�򣬾ʹ�������ĵ�������ռ���ڴ浫���̰߳�ȫ
class taskQueue {
public:
	//���ÿ������캯���͵ȺŸ�ֵ
	//��ʽһ
	taskQueue(const taskQueue& t) = delete;
	taskQueue& operator= (const taskQueue& t) = delete;
	static taskQueue* getInstance() {   //����Ҫ����ʵ������ֱ��ͨ�������Ϳ��Ե���
		return mtask;
	}

	void print() {
		cout << "����ģʽ��������Ĵ�ӡ��Ա����..." << endl;
	}

private:
	taskQueue() = default;
	////��ʽ��
	//taskQueue(const taskQueue& t) = default;
	//taskQueue& operator= (const taskQueue& t) = default;
	static taskQueue* mtask;   //������ʵ�������ٴΣ�ֻ����һ����̬��Ա��ֻ����������г�ʼ��
};

taskQueue* taskQueue::mtask = new taskQueue;
#endif 

#if 0
//����ģʽ��ʲôʱ��ʹ�õ���������ȥ��������ʡ�ڴ浫���̲߳���ȫ
class taskQueue {
public:
	//���ÿ������캯���͵ȺŸ�ֵ
	//��ʽһ
	taskQueue(const taskQueue& t) = delete;
	taskQueue& operator= (const taskQueue& t) = delete;
	static taskQueue* getInstance() {   //����Ҫ����ʵ������ֱ��ͨ�������Ϳ��Ե���
		if (mtask == nullptr) {   //˫�ؼ������
			mt.lock();    //����
			if (mtask == nullptr) {
				mtask = new taskQueue;
			}
			mt.unlock();  //����
		}
		return mtask;	 
	}

	void print() {
		cout << "����ģʽ��������Ĵ�ӡ��Ա����..." << endl;
	}

private:
	taskQueue() = default;
	////��ʽ��
	//taskQueue(const taskQueue& t) = default;
	//taskQueue& operator= (const taskQueue& t) = default;
	static taskQueue* mtask;   //������ʵ�������ٴΣ�ֻ����һ����̬��Ա��ֻ����������г�ʼ��
	static mutex mt;
};

taskQueue* taskQueue::mtask = nullptr;
mutex taskQueue::mt;
#endif

#if 0
//����ģʽ��ԭ�ӱ������˫�ؼ����������
class taskQueue {
public:
	//���ÿ������캯���͵ȺŸ�ֵ
	//��ʽһ
	taskQueue(const taskQueue& t) = delete;
	taskQueue& operator= (const taskQueue& t) = delete;
	static taskQueue* getInstance() {   //����Ҫ����ʵ������ֱ��ͨ�������Ϳ��Ե���
		taskQueue* task = mtask.load();  //ԭ�ӱ�������
		if (task == nullptr) {     //˫�ؼ������
			mt.lock();    //����
			task = mtask.load();
			if (task == nullptr) {
				task = new taskQueue;
				mtask.store(task);   //ԭ�ӱ����洢
			}
			mt.unlock();  //����
		}
		return task;
	}

	void print() {
		cout << "����ģʽ��������Ĵ�ӡ��Ա����..." << endl;
	}

private:
	taskQueue() = default;
	////��ʽ��
	//taskQueue(const taskQueue& t) = default;
	//taskQueue& operator= (const taskQueue& t) = default;
	static atomic<taskQueue*> mtask;   //ԭ�ӱ����洢
	static mutex mt;
};

atomic<taskQueue*> taskQueue::mtask;
mutex taskQueue::mt;
#endif 

#if 0
//����ģʽ��ʹ�þ�̬�ֲ��������̲߳���ȫ����
class taskQueue {
public:
	//���ÿ������캯���͵ȺŸ�ֵ
	//��ʽһ
	taskQueue(const taskQueue& t) = delete;
	taskQueue& operator= (const taskQueue& t) = delete;
	static taskQueue* getInstance() {   //����Ҫ����ʵ������ֱ��ͨ�������Ϳ��Ե���
		static taskQueue task;    //��̬�ֲ�����
		return &task;
	}

	void print() {
		cout << "����ģʽ��������Ĵ�ӡ��Ա����..." << endl;
	}

private:
	taskQueue() = default;
	////��ʽ��
	//taskQueue(const taskQueue& t) = default;
	//taskQueue& operator= (const taskQueue& t) = default;

};

#endif 

#if 1  
//����ģʽ�����߳��Ƽ�ʹ�ã���Ϊ��û���̲߳���ȫ������(ָ���Ǵ�����������ʱû���̲߳���ȫ����)
//���߳��������
class taskQueue {
public:
	//���ÿ������캯���͵ȺŸ�ֵ
	//��ʽһ
	taskQueue(const taskQueue& t) = delete;
	taskQueue& operator= (const taskQueue& t) = delete;
	static taskQueue* getInstance() {   //����Ҫ����ʵ������ֱ��ͨ�������Ϳ��Ե���
		return mtask;
	}

	void print() {
		cout << "����ģʽ��������Ĵ�ӡ��Ա����..." << endl;
	}

	//�ж���������Ƿ�Ϊ��
	bool isEmpty() {
		lock_guard<mutex> locker(mt);    //�����������Զ�����������������ǲ���
		return mq.empty();
	}

	//�������
	void addTask(int task) {
		lock_guard<mutex> locker(mt);
		mq.push(task);
	}

	//ɾ������
	bool deleteTask() {
		lock_guard<mutex> locker(mt); 
		if (mq.empty()) {
			return false;
		}
		mq.pop();
		return true;
	}

	//�������
	int takeTask() {
		lock_guard<mutex> locker(mt);
		if (mq.empty()) {
			return -1;
		}
		return mq.front();
	}

private:
	taskQueue() = default;
	////��ʽ��
	//taskQueue(const taskQueue& t) = default;
	//taskQueue& operator= (const taskQueue& t) = default;
	static taskQueue* mtask;   //������ʵ�������ٴΣ�ֻ����һ����̬��Ա��ֻ����������г�ʼ��
	queue<int> mq;   //�������
	mutex mt;   //������
};

taskQueue* taskQueue::mtask = new taskQueue;
#endif 

//int main() {
//	taskQueue* m = taskQueue::getInstance();
//	//m->print();
//
//	//������
//	thread t1([=]() {
//		for (int i = 0; i < 10; i++) {
//			m->addTask(i);
//			cout << " add data:" << i << " thread id:" << this_thread::get_id << endl;
//			this_thread::sleep_for(chrono::milliseconds(500));   //����500ms
//		}
//	});
//
//	//������
//	thread t2([=]() {
//		while(!m->isEmpty()){
//			int num = m->takeTask();
//			cout << "take data:" << num << " thread id:" << this_thread::get_id << endl;
//			m->deleteTask();
//			this_thread::sleep_for(chrono::milliseconds(500));   //����500ms
//		}
//	});
//
//	t1.join();
//	t2.join();
//
//	return 0;
//}